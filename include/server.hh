// -*- C++ -*-
// Automatically generated from include/server.x.
// DO NOT EDIT or your changes may be overwritten

#ifndef __XDR_INCLUDE_SERVER_HH_INCLUDED__
#define __XDR_INCLUDE_SERVER_HH_INCLUDED__ 1

#include <xdrpp/types.h>

using longstring = xdr::xstring<>;
using stringvector = xdr::xvector<longstring>;

struct kvpair {
  xdr::xstring<512> key{};
  xdr::xstring<> val{};
};
namespace xdr {
template<> struct xdr_traits<::kvpair>
  : xdr_struct_base<field_ptr<::kvpair,
                              decltype(::kvpair::key),
                              &::kvpair::key>,
                    field_ptr<::kvpair,
                              decltype(::kvpair::val),
                              &::kvpair::val>> {
  template<typename Archive> static void
  save(Archive &ar, const ::kvpair &obj) {
    archive(ar, obj.key, "key");
    archive(ar, obj.val, "val");
  }
  template<typename Archive> static void
  load(Archive &ar, ::kvpair &obj) {
    archive(ar, obj.key, "key");
    archive(ar, obj.val, "val");
  }
};
}

enum ReturnType : std::uint32_t {
  RESULT,
  ERROR_CODE,
};
namespace xdr {
template<> struct xdr_traits<::ReturnType>
  : xdr_integral_base<::ReturnType, std::uint32_t> {
  static constexpr bool is_enum = true;
  static constexpr bool is_numeric = false;
  static const char *enum_name(::ReturnType val) {
    switch (val) {
    case ::RESULT:
      return "RESULT";
    case ::ERROR_CODE:
      return "ERROR_CODE";
    default:
      return nullptr;
    }
  }
};
}

enum ClientError : std::uint32_t {
  KEY_NOT_FOUND,
  NO_PARENT,
  HAS_CHILDREN,
  MALFORMED_KEY,
};
namespace xdr {
template<> struct xdr_traits<::ClientError>
  : xdr_integral_base<::ClientError, std::uint32_t> {
  static constexpr bool is_enum = true;
  static constexpr bool is_numeric = false;
  static const char *enum_name(::ClientError val) {
    switch (val) {
    case ::KEY_NOT_FOUND:
      return "KEY_NOT_FOUND";
    case ::NO_PARENT:
      return "NO_PARENT";
    case ::HAS_CHILDREN:
      return "HAS_CHILDREN";
    case ::MALFORMED_KEY:
      return "MALFORMED_KEY";
    default:
      return nullptr;
    }
  }
};
}

struct bool_err {
private:
  std::uint32_t type_;
  union {
    bool success_;
    ClientError error_;
  };

public:
  static_assert (sizeof (ReturnType) <= 4, "union discriminant must be 4 bytes");

  static constexpr int _xdr_field_number(std::uint32_t which) {
    return which == RESULT ? 1
      : which == ERROR_CODE ? 2
      : -1;
  }
  template<typename _F, typename...A> static bool
  _xdr_with_mem_ptr(_F &_f, std::uint32_t which, A&&...a) {
    switch (which) {
    case RESULT:
      _f(&bool_err::success_, std::forward<A>(a)...);
      return true;
    case ERROR_CODE:
      _f(&bool_err::error_, std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  std::uint32_t _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(std::uint32_t which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in bool_err");
    if (fnum != _xdr_field_number(type_)) {
      this->~bool_err();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
  }
  bool_err(ReturnType which = ReturnType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  bool_err(const bool_err &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  bool_err(bool_err &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~bool_err() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  bool_err &operator=(const bool_err &source) {
    if (_xdr_field_number(type_) 
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~bool_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  bool_err &operator=(bool_err &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~bool_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  ReturnType type() const { return ReturnType(type_); }
  bool_err &type(ReturnType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  bool &success() {
    if (_xdr_field_number(type_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("bool_err: success accessed when not selected");
  }
  const bool &success() const {
    if (_xdr_field_number(type_) == 1)
      return success_;
    throw xdr::xdr_wrong_union("bool_err: success accessed when not selected");
  }
  ClientError &error() {
    if (_xdr_field_number(type_) == 2)
      return error_;
    throw xdr::xdr_wrong_union("bool_err: error accessed when not selected");
  }
  const ClientError &error() const {
    if (_xdr_field_number(type_) == 2)
      return error_;
    throw xdr::xdr_wrong_union("bool_err: error accessed when not selected");
  }
};
namespace xdr {
template<> struct xdr_traits<::bool_err> : xdr_traits_base {
  static constexpr bool is_class = true;
  static constexpr bool is_union = true;
  static constexpr bool has_fixed_size = false;

  using union_type = ::bool_err;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static constexpr const char *union_field_name(std::uint32_t which) {
    return which == RESULT ? "success"
      : which == ERROR_CODE ? "error"
      : nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::bool_err &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in bool_err");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::bool_err &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in bool_err");
  }
  template<typename Archive> static void
  load(Archive &ar, ::bool_err &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
  }
};
}

struct void_err {
private:
  std::uint32_t type_;
  union {
    ClientError error_;
  };

public:
  static_assert (sizeof (ReturnType) <= 4, "union discriminant must be 4 bytes");

  static constexpr int _xdr_field_number(std::uint32_t which) {
    return which == RESULT ? 0
      : which == ERROR_CODE ? 1
      : -1;
  }
  template<typename _F, typename...A> static bool
  _xdr_with_mem_ptr(_F &_f, std::uint32_t which, A&&...a) {
    switch (which) {
    case RESULT:
      return true;
    case ERROR_CODE:
      _f(&void_err::error_, std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  std::uint32_t _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(std::uint32_t which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in void_err");
    if (fnum != _xdr_field_number(type_)) {
      this->~void_err();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
  }
  void_err(ReturnType which = ReturnType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  void_err(const void_err &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  void_err(void_err &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~void_err() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  void_err &operator=(const void_err &source) {
    if (_xdr_field_number(type_) 
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~void_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  void_err &operator=(void_err &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~void_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  ReturnType type() const { return ReturnType(type_); }
  void_err &type(ReturnType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  ClientError &error() {
    if (_xdr_field_number(type_) == 1)
      return error_;
    throw xdr::xdr_wrong_union("void_err: error accessed when not selected");
  }
  const ClientError &error() const {
    if (_xdr_field_number(type_) == 1)
      return error_;
    throw xdr::xdr_wrong_union("void_err: error accessed when not selected");
  }
};
namespace xdr {
template<> struct xdr_traits<::void_err> : xdr_traits_base {
  static constexpr bool is_class = true;
  static constexpr bool is_union = true;
  static constexpr bool has_fixed_size = false;

  using union_type = ::void_err;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static constexpr const char *union_field_name(std::uint32_t which) {
    return which == RESULT ? nullptr
      : which == ERROR_CODE ? "error"
      : nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::void_err &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in void_err");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::void_err &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in void_err");
  }
  template<typename Archive> static void
  load(Archive &ar, ::void_err &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
  }
};
}

struct string_err {
private:
  std::uint32_t type_;
  union {
    longstring value_;
    ClientError error_;
  };

public:
  static_assert (sizeof (ReturnType) <= 4, "union discriminant must be 4 bytes");

  static constexpr int _xdr_field_number(std::uint32_t which) {
    return which == RESULT ? 1
      : which == ERROR_CODE ? 2
      : -1;
  }
  template<typename _F, typename...A> static bool
  _xdr_with_mem_ptr(_F &_f, std::uint32_t which, A&&...a) {
    switch (which) {
    case RESULT:
      _f(&string_err::value_, std::forward<A>(a)...);
      return true;
    case ERROR_CODE:
      _f(&string_err::error_, std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  std::uint32_t _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(std::uint32_t which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in string_err");
    if (fnum != _xdr_field_number(type_)) {
      this->~string_err();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
  }
  string_err(ReturnType which = ReturnType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  string_err(const string_err &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  string_err(string_err &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~string_err() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  string_err &operator=(const string_err &source) {
    if (_xdr_field_number(type_) 
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~string_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  string_err &operator=(string_err &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~string_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  ReturnType type() const { return ReturnType(type_); }
  string_err &type(ReturnType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  longstring &value() {
    if (_xdr_field_number(type_) == 1)
      return value_;
    throw xdr::xdr_wrong_union("string_err: value accessed when not selected");
  }
  const longstring &value() const {
    if (_xdr_field_number(type_) == 1)
      return value_;
    throw xdr::xdr_wrong_union("string_err: value accessed when not selected");
  }
  ClientError &error() {
    if (_xdr_field_number(type_) == 2)
      return error_;
    throw xdr::xdr_wrong_union("string_err: error accessed when not selected");
  }
  const ClientError &error() const {
    if (_xdr_field_number(type_) == 2)
      return error_;
    throw xdr::xdr_wrong_union("string_err: error accessed when not selected");
  }
};
namespace xdr {
template<> struct xdr_traits<::string_err> : xdr_traits_base {
  static constexpr bool is_class = true;
  static constexpr bool is_union = true;
  static constexpr bool has_fixed_size = false;

  using union_type = ::string_err;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static constexpr const char *union_field_name(std::uint32_t which) {
    return which == RESULT ? "value"
      : which == ERROR_CODE ? "error"
      : nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::string_err &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in string_err");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::string_err &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in string_err");
  }
  template<typename Archive> static void
  load(Archive &ar, ::string_err &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
  }
};
}

struct stringvector_err {
private:
  std::uint32_t type_;
  union {
    stringvector vector_;
    ClientError error_;
  };

public:
  static_assert (sizeof (ReturnType) <= 4, "union discriminant must be 4 bytes");

  static constexpr int _xdr_field_number(std::uint32_t which) {
    return which == RESULT ? 1
      : which == ERROR_CODE ? 2
      : -1;
  }
  template<typename _F, typename...A> static bool
  _xdr_with_mem_ptr(_F &_f, std::uint32_t which, A&&...a) {
    switch (which) {
    case RESULT:
      _f(&stringvector_err::vector_, std::forward<A>(a)...);
      return true;
    case ERROR_CODE:
      _f(&stringvector_err::error_, std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  std::uint32_t _xdr_discriminant() const { return type_; }
  void _xdr_discriminant(std::uint32_t which, bool validate = true) {
    int fnum = _xdr_field_number(which);
    if (fnum < 0 && validate)
      throw xdr::xdr_bad_discriminant("bad value of type in stringvector_err");
    if (fnum != _xdr_field_number(type_)) {
      this->~stringvector_err();
      type_ = which;
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
    }
  }
  stringvector_err(ReturnType which = ReturnType{}) : type_(which) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this);
  }
  stringvector_err(const stringvector_err &source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
  }
  stringvector_err(stringvector_err &&source) : type_(source.type_) {
    _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                      std::move(source));
  }
  ~stringvector_err() { _xdr_with_mem_ptr(xdr::field_destructor, type_, *this); }
  stringvector_err &operator=(const stringvector_err &source) {
    if (_xdr_field_number(type_) 
        == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this, source);
    else {
      this->~stringvector_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this, source);
    }
    type_ = source.type_;
    return *this;
  }
  stringvector_err &operator=(stringvector_err &&source) {
    if (_xdr_field_number(type_)
         == _xdr_field_number(source.type_))
      _xdr_with_mem_ptr(xdr::field_assigner, type_, *this,
                        std::move(source));
    else {
      this->~stringvector_err();
      type_ = std::uint32_t(-1);
      _xdr_with_mem_ptr(xdr::field_constructor, type_, *this,
                        std::move(source));
    }
    type_ = source.type_;
    return *this;
  }

  ReturnType type() const { return ReturnType(type_); }
  stringvector_err &type(ReturnType _xdr_d, bool _xdr_validate = true) {
    _xdr_discriminant(_xdr_d, _xdr_validate);
    return *this;
  }

  stringvector &vector() {
    if (_xdr_field_number(type_) == 1)
      return vector_;
    throw xdr::xdr_wrong_union("stringvector_err: vector accessed when not selected");
  }
  const stringvector &vector() const {
    if (_xdr_field_number(type_) == 1)
      return vector_;
    throw xdr::xdr_wrong_union("stringvector_err: vector accessed when not selected");
  }
  ClientError &error() {
    if (_xdr_field_number(type_) == 2)
      return error_;
    throw xdr::xdr_wrong_union("stringvector_err: error accessed when not selected");
  }
  const ClientError &error() const {
    if (_xdr_field_number(type_) == 2)
      return error_;
    throw xdr::xdr_wrong_union("stringvector_err: error accessed when not selected");
  }
};
namespace xdr {
template<> struct xdr_traits<::stringvector_err> : xdr_traits_base {
  static constexpr bool is_class = true;
  static constexpr bool is_union = true;
  static constexpr bool has_fixed_size = false;

  using union_type = ::stringvector_err;
  using discriminant_type = decltype(std::declval<union_type>().type());

  static constexpr const char *union_field_name(std::uint32_t which) {
    return which == RESULT ? "vector"
      : which == ERROR_CODE ? "error"
      : nullptr;
  }
  static const char *union_field_name(const union_type &u) {
    return union_field_name(u._xdr_discriminant());
  }

  static std::size_t serial_size(const ::stringvector_err &obj) {
    std::size_t size = 0;
    if (!obj._xdr_with_mem_ptr(field_size, obj._xdr_discriminant(), obj, size))
      throw xdr_bad_discriminant("bad value of type in stringvector_err");
    return size + 4;
  }
  template<typename Archive> static void
  save(Archive &ar, const ::stringvector_err &obj) {
    xdr::archive(ar, obj.type(), "type");
    if (!obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                               union_field_name(obj)))
      throw xdr_bad_discriminant("bad value of type in stringvector_err");
  }
  template<typename Archive> static void
  load(Archive &ar, ::stringvector_err &obj) {
    discriminant_type which;
    xdr::archive(ar, which, "type");
    obj.type(which);
    obj._xdr_with_mem_ptr(field_archiver, obj.type(), ar, obj,
                          union_field_name(which));
  }
};
}

struct api_v1 {
  static constexpr std::uint32_t program = 1074036870;
  static constexpr const char *program_name = "server_api";
  static constexpr std::uint32_t version = 1;
  static constexpr const char *version_name = "api_v1";

  struct create_t {
    using interface_type = api_v1;
    static constexpr std::uint32_t proc = 1;
    static constexpr const char *proc_name = "create";
    using arg_type = kvpair;
    using arg_wire_type = kvpair;
    using res_type = bool_err;
    using res_wire_type = bool_err;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.create(std::forward<A>(a)...)) {
      return c.create(std::forward<A>(a)...);
    }
    
    template<typename C, typename DropIfVoid, typename...A> static auto
    dispatch_dropvoid(C &&c, DropIfVoid &&d, A &&...a) ->
    decltype(c.create(std::forward<DropIfVoid>(d), std::forward<A>(a)...)) {
      return c.create(std::forward<DropIfVoid>(d), std::forward<A>(a)...);
    }
  };

  struct remove_t {
    using interface_type = api_v1;
    static constexpr std::uint32_t proc = 2;
    static constexpr const char *proc_name = "remove";
    using arg_type = longstring;
    using arg_wire_type = longstring;
    using res_type = bool_err;
    using res_wire_type = bool_err;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.remove(std::forward<A>(a)...)) {
      return c.remove(std::forward<A>(a)...);
    }
    
    template<typename C, typename DropIfVoid, typename...A> static auto
    dispatch_dropvoid(C &&c, DropIfVoid &&d, A &&...a) ->
    decltype(c.remove(std::forward<DropIfVoid>(d), std::forward<A>(a)...)) {
      return c.remove(std::forward<DropIfVoid>(d), std::forward<A>(a)...);
    }
  };

  struct set_t {
    using interface_type = api_v1;
    static constexpr std::uint32_t proc = 3;
    static constexpr const char *proc_name = "set";
    using arg_type = kvpair;
    using arg_wire_type = kvpair;
    using res_type = void_err;
    using res_wire_type = void_err;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.set(std::forward<A>(a)...)) {
      return c.set(std::forward<A>(a)...);
    }
    
    template<typename C, typename DropIfVoid, typename...A> static auto
    dispatch_dropvoid(C &&c, DropIfVoid &&d, A &&...a) ->
    decltype(c.set(std::forward<DropIfVoid>(d), std::forward<A>(a)...)) {
      return c.set(std::forward<DropIfVoid>(d), std::forward<A>(a)...);
    }
  };

  struct get_t {
    using interface_type = api_v1;
    static constexpr std::uint32_t proc = 4;
    static constexpr const char *proc_name = "get";
    using arg_type = longstring;
    using arg_wire_type = longstring;
    using res_type = string_err;
    using res_wire_type = string_err;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.get(std::forward<A>(a)...)) {
      return c.get(std::forward<A>(a)...);
    }
    
    template<typename C, typename DropIfVoid, typename...A> static auto
    dispatch_dropvoid(C &&c, DropIfVoid &&d, A &&...a) ->
    decltype(c.get(std::forward<DropIfVoid>(d), std::forward<A>(a)...)) {
      return c.get(std::forward<DropIfVoid>(d), std::forward<A>(a)...);
    }
  };

  struct list_t {
    using interface_type = api_v1;
    static constexpr std::uint32_t proc = 5;
    static constexpr const char *proc_name = "list";
    using arg_type = longstring;
    using arg_wire_type = longstring;
    using res_type = stringvector_err;
    using res_wire_type = stringvector_err;
    
    template<typename C, typename...A> static auto
    dispatch(C &&c, A &&...a) ->
    decltype(c.list(std::forward<A>(a)...)) {
      return c.list(std::forward<A>(a)...);
    }
    
    template<typename C, typename DropIfVoid, typename...A> static auto
    dispatch_dropvoid(C &&c, DropIfVoid &&d, A &&...a) ->
    decltype(c.list(std::forward<DropIfVoid>(d), std::forward<A>(a)...)) {
      return c.list(std::forward<DropIfVoid>(d), std::forward<A>(a)...);
    }
  };

  template<typename T, typename...A> static bool
  call_dispatch(T &&t, std::uint32_t proc, A &&...a) {
    switch(proc) {
    case 1:
      t.template dispatch<create_t>(std::forward<A>(a)...);
      return true;
    case 2:
      t.template dispatch<remove_t>(std::forward<A>(a)...);
      return true;
    case 3:
      t.template dispatch<set_t>(std::forward<A>(a)...);
      return true;
    case 4:
      t.template dispatch<get_t>(std::forward<A>(a)...);
      return true;
    case 5:
      t.template dispatch<list_t>(std::forward<A>(a)...);
      return true;
    }
    return false;
  }

  template<typename _XDRBASE> struct client : _XDRBASE {
    using _XDRBASE::_XDRBASE;

    template<typename..._XDRARGS> auto
    create(_XDRARGS &&..._xdr_args) ->
    decltype(this->_XDRBASE::template invoke<create_t>(_xdr_args...)) {
      return this->_XDRBASE::template invoke<create_t>(_xdr_args...);
    }

    template<typename..._XDRARGS> auto
    remove(_XDRARGS &&..._xdr_args) ->
    decltype(this->_XDRBASE::template invoke<remove_t>(_xdr_args...)) {
      return this->_XDRBASE::template invoke<remove_t>(_xdr_args...);
    }

    template<typename..._XDRARGS> auto
    set(_XDRARGS &&..._xdr_args) ->
    decltype(this->_XDRBASE::template invoke<set_t>(_xdr_args...)) {
      return this->_XDRBASE::template invoke<set_t>(_xdr_args...);
    }

    template<typename..._XDRARGS> auto
    get(_XDRARGS &&..._xdr_args) ->
    decltype(this->_XDRBASE::template invoke<get_t>(_xdr_args...)) {
      return this->_XDRBASE::template invoke<get_t>(_xdr_args...);
    }

    template<typename..._XDRARGS> auto
    list(_XDRARGS &&..._xdr_args) ->
    decltype(this->_XDRBASE::template invoke<list_t>(_xdr_args...)) {
      return this->_XDRBASE::template invoke<list_t>(_xdr_args...);
    }
  };
};

#endif // !__XDR_INCLUDE_SERVER_HH_INCLUDED__
