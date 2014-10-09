typedef string longstring<>;
typedef longstring stringvector<>;

struct kvpair {
  string key<512>;
  string val<>;
};

enum ReturnType {
  RESULT,
  ERROR
};

enum ErrorCode {
  /*
  * Set, Get or Remove failed because they key was not found.
  */
  KEY_NOT_FOUND,
  /*
  * Create operation failed because the key has no parent.
  */
  NO_PARENT,
  /*
  * The key has children so it cannot be deleted.
  */
  HAS_CHILDREN,
  /*
  * The key path violates our formatting rules
  */
  MALFORMED_KEY,
  /*
  * The operation is invalid on the node
  */
  INVALID_OPERATION
};

union bool_err switch (ReturnType type) {
case RESULT:
  bool value;
case ERROR:
  ErrorCode error;
};

union void_err switch (ReturnType type) {
case RESULT:
  void;
case ERROR:
  ErrorCode error;
};

union string_err switch (ReturnType type) {
case RESULT:
  longstring value;
case ERROR:
  ErrorCode error;
};

union stringvector_err switch (ReturnType type) {
case RESULT:
  stringvector value;
case ERROR:
  ErrorCode error;
};

program server_api {
  version api_v1 {
    bool_err create(kvpair) = 1;
    bool_err remove(longstring) = 2;
    void_err set(kvpair) = 3;
    string_err get(longstring) = 4;
    stringvector_err list(longstring) = 5;
  } = 1;
} = 0x40048086;
