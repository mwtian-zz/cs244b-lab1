#ifndef __SERVERUTIL_H__
#define __SERVERUTIL_H__

#include <set>
#include <string>
#include <vector>

bool isValidKey(const std::string &key);

std::string getParentKey(const std::string &key);

std::string getNodeName(const std::string &path);

// template<typename T>
// std::string logResult(const std::string &content, const T &res);

#endif /* __SERVERUTIL_H__ */
