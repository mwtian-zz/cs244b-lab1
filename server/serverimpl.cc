// Scaffolding originally generated from include/server.x.
// Edit to add functionality.

#include <string>
#include <iostream>

#include "server/serverimpl.hh"
#include "server/util.hh"

api_v1_server::api_v1_server() : db("kvstore.db") {

}

std::unique_ptr<bool_err>
api_v1_server::create(std::unique_ptr<kvpair> arg)
{
  std::unique_ptr<bool_err> res(new bool_err);
  
  bool hasKey;
  std::string key = arg->key;
  std::string val = arg->val;
  
  // Fill in additional sanity checking (e.g. prevent malformed paths)
  
  hasKey = db.hasKey(arg->key);
  if (hasKey) {
    res->type(RESULT);
    res->success() = false;
    std::cout << "Created " << key << " Failed" << std::endl;
  } else {
    res->type(RESULT);
    res->success() = true;
    db.set(key, val);
    std::cout << "Created " << key << " Succeded" << std::endl;
  }
  
  return res;
}

std::unique_ptr<bool_err>
api_v1_server::remove(std::unique_ptr<longstring> arg)
{
  std::unique_ptr<bool_err> res(new bool_err);

  // Fill in function body here
  
  return res;
}

std::unique_ptr<void_err>
api_v1_server::set(std::unique_ptr<kvpair> arg)
{
  std::unique_ptr<void_err> res(new void_err);
  
  // Fill in function body here
  
  return res;
}

std::unique_ptr<string_err>
api_v1_server::get(std::unique_ptr<longstring> arg)
{
  std::unique_ptr<string_err> res(new string_err);
  
  // Fill in function body here
  
  return res;
}

std::unique_ptr<stringvector_err>
api_v1_server::list(std::unique_ptr<longstring> arg)
{
  std::unique_ptr<stringvector_err> res(new stringvector_err);
  
  // Fill in function body here
  
  return res;
}
