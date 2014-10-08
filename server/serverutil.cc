#include "serverutil.hh"

#include <locale>

const char SEPARATOR = '/';

bool 
isValidKey(const std::string &key) {
  if (key.empty()) {
    return true;
  }

  if (key[0] != SEPARATOR) {
    return false;
  }

  int prev = 0;
  int i = 1;
  while (i <= key.length()) {
    if (key[i] == SEPARATOR || i == key.length()) {
      if (i - prev == 1) {
        return false;
      }
      prev = i;
    } else if (!std::isalnum(key[i])) {
      return false;
    }
    i++;
  }

  return true;
}

std::string 
getParentKey(const std::string &key) {
  int last = key.find_last_of(SEPARATOR);
  return key.substr(0, last);
}

std::string 
setToString(const std::set<std::string> &set) {
  std::string result;
  for (const std::string &str : set) {
    result += str + ",";
  }
  return result;
}

std::vector<std::string> 
stringToVector(const std::string &str) {
  std::vector<std::string> result;
  int prev = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ',') {
      result.emplace_back(str.substr(prev, i - prev));
      prev = i + 1;
    }
  }
  return result;
}
