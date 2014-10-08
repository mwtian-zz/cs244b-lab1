#ifndef __SERVERUTIL_H__
#define __SERVERUTIL_H__

#include <set>
#include <string>
#include <vector>

bool isValidKey(const std::string &key);

std::string getParentKey(const std::string &key);

std::string setToString(const std::set<std::string> &set);

std::vector<std::string> stringToVector(const std::string &str);

#endif /* __SERVERUTIL_H__ */
