// Scaffolding originally generated from include/server.x.
// Edit to add functionality.

#include "server/serverimpl.hh"

#include <iostream>
#include <string>
#include <vector>

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

  if (!isValidKey(arg->key)) {
    res->error() = MALFORMED_KEY;
  } else if (arg->key == ROOTNODE) {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(getParentKey(arg->key))) {
    res->error() = NO_PARENT;
  } else {
    bool hasKey = db.hasKey(arg->key);
    if (!hasKey) {
      db.set(arg->key, arg->val);
    }
    res->type(RESULT);
    res->value() = !hasKey;
  }

  std::cout << logResult("Create " + arg->key, res) << std::endl;
  return res;
}

std::unique_ptr<bool_err>
api_v1_server::remove(std::unique_ptr<longstring> key)
{
  std::unique_ptr<bool_err> res(new bool_err);
  res->type(ERROR);

  if (!isValidKey(*key)) {
    res->error() = MALFORMED_KEY;
  } else if (*key == ROOTNODE) {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(*key)) {
    res->error() = KEY_NOT_FOUND;
  } else if (db.list(*key).size() > 0) {
    res->error() = HAS_CHILDREN;
  } else {
    db.remove(*key);
    res->type(RESULT);
    res->value() = true;
  }

  std::cout << logResult("Remove " + *key, res) << std::endl;
  return res;
}

std::unique_ptr<void_err>
api_v1_server::set(std::unique_ptr<kvpair> arg)
{
  std::unique_ptr<void_err> res(new void_err);
  res->type(ERROR);

  if (!isValidKey(arg->key)) {
    res->error() = MALFORMED_KEY;
  } else if (arg->key == ROOTNODE) {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(arg->key)) {
    res->error() = KEY_NOT_FOUND;
  } else {
    db.set(arg->key, arg->val);
    res->type(RESULT);
  }

  std::cout << logResult("Set " + arg->key, res) << std::endl;
  return res;
}

std::unique_ptr<string_err>
api_v1_server::get(std::unique_ptr<longstring> key)
{
  std::unique_ptr<string_err> res(new string_err);
  res->type(ERROR);

  if (!isValidKey(*key)) {
    res->error() = MALFORMED_KEY;
  } else if (*key == ROOTNODE) {
    res->error() = INVALID_OPERATION;
  } else if (!db.hasKey(*key)) {
    res->error() = KEY_NOT_FOUND;
  } else {
    res->type(RESULT);
    res->value() = db.get(*key);
  }

  std::cout << logResult("Get " + *key, res) << std::endl;
  return res;
}

std::unique_ptr<stringvector_err>
api_v1_server::list(std::unique_ptr<longstring> key)
{
  std::unique_ptr<stringvector_err> res(new stringvector_err);
  res->type(ERROR);

  if (!isValidKey(*key)) {
    res->error() = MALFORMED_KEY;
    std::cout << logResult("List " + *key, res) << std::endl;
    return res;
  }

  // Allowed to access root
  std::string query = *key == ROOTNODE ? "" : *key;

  if (!db.hasKey(query)) {
    res->error() = KEY_NOT_FOUND;
  } else {
    res->type(RESULT);
    for (const std::string &path : db.list(query)) {
      res->value().push_back(getNodeName(path));
    }
  }
  
  std::cout << logResult("List " + *key, res) << std::endl;
  return res;
}
