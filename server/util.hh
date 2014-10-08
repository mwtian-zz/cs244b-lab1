#ifndef __UTIL_H__
#define __UTIL_H__

#include <set>
#include <string>
#include <vector>

bool validateKey(const std::string &key);

std::string getParentKey(const std::string &key);

std::string setToString(const std::set<std::string> &set);

std::vector<std::string> stringToVector(const std::string &str);

#endif /* __UTIL_H__ */
