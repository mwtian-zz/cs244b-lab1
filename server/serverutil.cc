#include "serverutil.hh"

#include <locale>

const char SEPARATOR = '/';

bool 
isValidKey(const std::string &key) {
  if (key.empty() || key[0] != SEPARATOR) {
    return false;
  }

  if (key.length() == 1) {
    return true;
  }

  int prev = 0;
  int i = 1;
  while (i <= key.length()) {
    // Making sure each node's name is non-empty.
    // and path does not end on '/'
    if (key[i] == SEPARATOR || i == key.length()) {
      if (i - prev == 1) {
        return false;
      }
      prev = i;
    // names can only contain letters, numbers, underscores and slashes
    } else if (!(std::isalnum(key[i]) || key[i] == '_')) {
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
getNodeName(const std::string &path) {
  int begin = path.find_last_of(SEPARATOR) + 1;
  int len = path.length() - begin;
  return path.substr(begin, len);
}

// template<typename T>
// std::string logResult(const std::string &content, const T &res) {
//   if (res->type() == RESULT) {
//     return content + " " + "Succeeded";
//   } else {
//     return content + " " + "Failed";
//   }
// }