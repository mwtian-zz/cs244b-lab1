#ifndef __SERVERUTIL_H__
#define __SERVERUTIL_H__

#include <set>
#include <string>
#include <vector>

#include "include/server.hh"
#include "include/global.hh"

bool isValidKey(const std::string &key);

std::string getParentKey(const std::string &key);

std::string getNodeName(const std::string &path);

std::string logResult(const std::string &content, ReturnType type);

template<typename T>
std::string logResult(const std::string &content, const T &res) {
  if (res->type() == RESULT) {
    return content + " Succeeded";
  } else {
    return content + " Failed: " + errorCodeDetails(res->error());
  }
}

#endif /* __SERVERUTIL_H__ */
