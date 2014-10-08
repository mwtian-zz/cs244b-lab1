// Scaffolding originally generated from include/server.x.
// Edit to add functionality.

#include <string>
#include <iostream>
#include <vector>

#include "server/serverimpl.hh"
#include "server/serverutil.hh"

api_v1_server::api_v1_server() : db("kvstore.db") {
  // Initialize root
  if (!db.hasKey("")) {
    db.set("", "");
  }
}

std::unique_ptr<bool_err>
api_v1_server::create(std::unique_ptr<kvpair> arg)
{
  std::unique_ptr<bool_err> res(new bool_err);
  res->type(ERROR);

  if (!(arg && isValidKey(arg->key))) {
    res->error() = MALFORMED_KEY;
    return res;
  }

  const std::string &key = arg->key;
  const std::string &val = arg->val;

  if (key == "/") {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(getParentKey(key))) {
    res->error() = NO_PARENT;
  } else {
    bool hasKey = db.hasKey(key);
    if (!hasKey) {
      db.set(key, val);
      std::cout << "Create " << key << " Succeded" << std::endl;
    }
    res->type(RESULT);
    res->value() = !hasKey;
  }

  return res;
}

std::unique_ptr<bool_err>
api_v1_server::remove(std::unique_ptr<longstring> arg)
{
  std::unique_ptr<bool_err> res(new bool_err);
  res->type(ERROR);

  if (!(arg && isValidKey(*arg))) {
    res->error() = MALFORMED_KEY;
    return res;
  }

  const std::string &key = *arg;

  if (key == "/") {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(key)) {
    res->error() = KEY_NOT_FOUND;
  } else if (db.list(key).size() > 0) {
    res->error() = HAS_CHILDREN;
  } else {
    db.remove(key);
    res->type(RESULT);
    res->value() = true;
  }

  return res;
}

std::unique_ptr<void_err>
api_v1_server::set(std::unique_ptr<kvpair> arg)
{
  std::unique_ptr<void_err> res(new void_err);
  res->type(ERROR);

  if (!(arg && isValidKey(arg->key))) {
    res->error() = MALFORMED_KEY;
    return res;
  }

  const std::string &key = arg->key;
  const std::string &val = arg->val;

  if (key == "/") {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(key)) {
    res->error() = KEY_NOT_FOUND;
  } else {
    db.set(key, val);
    res->type(RESULT);
  }

  return res;
}

std::unique_ptr<string_err>
api_v1_server::get(std::unique_ptr<longstring> arg)
{
  std::unique_ptr<string_err> res(new string_err);
  res->type(ERROR);

  if (!(arg && isValidKey(*arg))) {
    res->error() = MALFORMED_KEY;
    return res;
  }

  const std::string &key = *arg;

  if (key == "/") {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(key)) {
    res->error() = KEY_NOT_FOUND;
  } else {
    res->type(RESULT);
    res->value() = db.get(key);
  }

  return res;
}

std::unique_ptr<stringvector_err>
api_v1_server::list(std::unique_ptr<longstring> arg)
{
  std::unique_ptr<stringvector_err> res(new stringvector_err);
  res->type(ERROR);

  if (!(arg && isValidKey(*arg))) {
    res->error() = MALFORMED_KEY;
    return res;
  }

  std::string key = *arg == "/" ? "" : *arg;

  if (!db.hasKey(key)) {
    res->error() = KEY_NOT_FOUND;
  } else {
    res->type(RESULT);
    for (const std::string &path : db.list(key)) {
      res->value().push_back(getNodeName(path));
    }
  }
  
  return res;
}
