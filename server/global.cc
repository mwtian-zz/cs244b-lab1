#include "include/global.hh"

const char SEPARATOR = '/';
const char *ROOTNODE = "/";

const char*
errorCodeDetails(ErrorCode code) {
  switch (code) {
    case KEY_NOT_FOUND:
        return "KEY NOT FOUND";
    case NO_PARENT:
        return "NO PARENT";
    case HAS_CHILDREN:
        return "HAS CHILDREN";
    case MALFORMED_KEY:
        return "MALFORMED KEY";
    case INVALID_OPERATION:
        return "INVALID OPERATION";
  }
  return "UNKNOWN ERROR CODE";
}