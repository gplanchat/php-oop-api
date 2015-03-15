
#ifndef PHP_MUTAGEN_H
#define PHP_MUTAGEN_H

#define __MUTAGEN_NS_IDENTIFIER_1(_1, ...)                                                       _1
#define __MUTAGEN_NS_IDENTIFIER_2(_1, _2, ...)                                                   _1 ## _ ## _2
#define __MUTAGEN_NS_IDENTIFIER_3(_1, _2, _3, ...)                                               _1 ## _ ## _2 ## _ ## _3
#define __MUTAGEN_NS_IDENTIFIER_4(_1, _2, _3, _4, ...)                                           _1 ## _ ## _2 ## _ ## _3 ## _ ## _4
#define __MUTAGEN_NS_IDENTIFIER_5(_1, _2, _3, _4, _5, ...)                                       _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5
#define __MUTAGEN_NS_IDENTIFIER_6(_1, _2, _3, _4, _5, _6, ...)                                   _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6
#define __MUTAGEN_NS_IDENTIFIER_7(_1, _2, _3, _4, _5, _6, _7, ...)                               _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6 ## _ ## _7
#define __MUTAGEN_NS_IDENTIFIER_8(_1, _2, _3, _4, _5, _6, _7, _8, ...)                           _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6 ## _ ## _7 ## _ ## _8
#define __MUTAGEN_NS_IDENTIFIER_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, ...)                       _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6 ## _ ## _7 ## _ ## _8 ## _ ## _9
#define __MUTAGEN_NS_IDENTIFIER_10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...)                 _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6 ## _ ## _7 ## _ ## _8 ## _ ## _9 ## _ ## _10
#define __MUTAGEN_NS_IDENTIFIER_11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, ...)            _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6 ## _ ## _7 ## _ ## _8 ## _ ## _9 ## _ ## _10 ## _ ## _11
#define __MUTAGEN_NS_IDENTIFIER_12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, ...)       _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6 ## _ ## _7 ## _ ## _8 ## _ ## _9 ## _ ## _10 ## _ ## _11 ## _ ## _12
#define __MUTAGEN_NS_IDENTIFIER_13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, ...)  _1 ## _ ## _2 ## _ ## _3 ## _ ## _4 ## _ ## _5 ## _ ## _6 ## _ ## _7 ## _ ## _8 ## _ ## _9 ## _ ## _10 ## _ ## _11 ## _ ## _12 ## _ ## _13

#define __MUTAGEN_NS_STR_1(_1, ...)                                  _1
#define __MUTAGEN_NS_STR_2(_1, _2, ...)                              _1 "\\" _2
#define __MUTAGEN_NS_STR_3(_1, _2, _3, ...)                          _1 "\\" _2 "\\" _3
#define __MUTAGEN_NS_STR_4(_1, _2, _3, _4, ...)                      _1 "\\" _2 "\\" _3 "\\" _4
#define __MUTAGEN_NS_STR_5(_1, _2, _3, _4, _5, ...)                  _1 "\\" _2 "\\" _3 "\\" _4 "\\" _5
#define __MUTAGEN_NS_STR_6(_1, _2, _3, _4, _5, _6, ...)              _1 "\\" _2 "\\" _3 "\\" _4 "\\" _5 "\\" _6
#define __MUTAGEN_NS_STR_7(_1, _2, _3, _4, _5, _6, _7, ...)          _1 "\\" _2 "\\" _3 "\\" _4 "\\" _5 "\\" _6 "\\" _7
#define __MUTAGEN_NS_STR_8(_1, _2, _3, _4, _5, _6, _7, _8, ...)      _1 "\\" _2 "\\" _3 "\\" _4 "\\" _5 "\\" _6 "\\" _7 "\\" _8
#define __MUTAGEN_NS_STR_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, ...)  _1 "\\" _2 "\\" _3 "\\" _4 "\\" _5 "\\" _6 "\\" _7 "\\" _8 "\\" _9

#define __MUTAGEN_NS_REF_1(_1, ...)                                  _1
#define __MUTAGEN_NS_REF_2(_1, _2, ...)                              _1\\_2
#define __MUTAGEN_NS_REF_3(_1, _2, _3, ...)                          _1\\_2\\_3
#define __MUTAGEN_NS_REF_4(_1, _2, _3, _4, ...)                      _1\\_2\\_3\\_4
#define __MUTAGEN_NS_REF_5(_1, _2, _3, _4, _5, ...)                  _1\\_2\\_3\\_4\\_5
#define __MUTAGEN_NS_REF_6(_1, _2, _3, _4, _5, _6, ...)              _1\\_2\\_3\\_4\\_5\\_6
#define __MUTAGEN_NS_REF_7(_1, _2, _3, _4, _5, _6, _7, ...)          _1\\_2\\_3\\_4\\_5\\_6\\_7
#define __MUTAGEN_NS_REF_8(_1, _2, _3, _4, _5, _6, _7, _8, ...)      _1\\_2\\_3\\_4\\_5\\_6\\_7\\_8
#define __MUTAGEN_NS_REF_9(_1, _2, _3, _4, _5, _6, _7, _8, _9, ...)  _1\\_2\\_3\\_4\\_5\\_6\\_7\\_8\\_9

#define __MUTAGEN_ARG_N(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, N, ...) (N)
#define __MUTAGEN_RSEQ_N     13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 0
#define __MUTAGEN_NARG(...)  (__MUTAGEN_ARG_N(__VA_ARGS__, __MUTAGEN_RSEQ_N))

#define __MUTAGEN_NS_IDENTIFIER_EX_13(count, ...)                 __MUTAGEN_NS_IDENTIFIER_13(__VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_12(count, ...) (count <= 12) ? __MUTAGEN_NS_IDENTIFIER_12(__VA_ARGS__) : __MUTAGEN_NS_IDENTIFIER_EX_13(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_11(count, ...) (count <= 11) ? __MUTAGEN_NS_IDENTIFIER_11(__VA_ARGS__) : __MUTAGEN_NS_IDENTIFIER_EX_12(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_10(count, ...) (count <= 10) ? __MUTAGEN_NS_IDENTIFIER_10(__VA_ARGS__) : __MUTAGEN_NS_IDENTIFIER_EX_11(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_9(count, ...)  (count <= 9)  ? __MUTAGEN_NS_IDENTIFIER_9(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_10(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_8(count, ...)  (count <= 8)  ? __MUTAGEN_NS_IDENTIFIER_8(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_9(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_7(count, ...)  (count <= 7)  ? __MUTAGEN_NS_IDENTIFIER_7(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_8(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_6(count, ...)  (count <= 6)  ? __MUTAGEN_NS_IDENTIFIER_6(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_7(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_5(count, ...)  (count <= 5)  ? __MUTAGEN_NS_IDENTIFIER_5(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_6(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_4(count, ...)  (count <= 4)  ? __MUTAGEN_NS_IDENTIFIER_4(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_5(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_3(count, ...)  (count <= 3)  ? __MUTAGEN_NS_IDENTIFIER_3(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_4(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_2(count, ...)  (count <= 2)  ? __MUTAGEN_NS_IDENTIFIER_2(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_3(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX_1(count, ...)  (count <= 1)  ? __MUTAGEN_NS_IDENTIFIER_1(__VA_ARGS__)  : __MUTAGEN_NS_IDENTIFIER_EX_2(count, __VA_ARGS__)
#define __MUTAGEN_NS_IDENTIFIER_EX(...)           __MUTAGEN_NS_IDENTIFIER_EX_1(__MUTAGEN_NARG(__VA_ARGS__), __VA_ARGS__)

#define __MUTAGEN_NS_STR_EX_9(count, ...)                 __MUTAGEN_NS_STR_9(__VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_8(count, ...)  (count <= 8) ? __MUTAGEN_NS_STR_8(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_9(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_7(count, ...)  (count <= 7) ? __MUTAGEN_NS_STR_7(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_8(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_6(count, ...)  (count <= 6) ? __MUTAGEN_NS_STR_6(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_7(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_5(count, ...)  (count <= 5) ? __MUTAGEN_NS_STR_5(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_6(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_4(count, ...)  (count <= 4) ? __MUTAGEN_NS_STR_4(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_5(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_3(count, ...)  (count <= 3) ? __MUTAGEN_NS_STR_3(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_4(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_2(count, ...)  (count <= 2) ? __MUTAGEN_NS_STR_2(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_3(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX_1(count, ...)  (count <= 1) ? __MUTAGEN_NS_STR_1(__VA_ARGS__) : __MUTAGEN_NS_STR_EX_2(count, __VA_ARGS__)
#define __MUTAGEN_NS_STR_EX(...)           __MUTAGEN_NS_STR_EX_1(__MUTAGEN_NARG(__VA_ARGS__), __VA_ARGS__)

#define __MUTAGEN_NS_REF_EX_9(count, ...)                 __MUTAGEN_NS_REF_9(__VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_8(count, ...)  (count <= 8) ? __MUTAGEN_NS_REF_8(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_9(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_7(count, ...)  (count <= 7) ? __MUTAGEN_NS_REF_7(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_8(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_6(count, ...)  (count <= 6) ? __MUTAGEN_NS_REF_6(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_7(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_5(count, ...)  (count <= 5) ? __MUTAGEN_NS_REF_5(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_6(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_4(count, ...)  (count <= 4) ? __MUTAGEN_NS_REF_4(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_5(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_3(count, ...)  (count <= 3) ? __MUTAGEN_NS_REF_3(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_4(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_2(count, ...)  (count <= 2) ? __MUTAGEN_NS_REF_2(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_3(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX_1(count, ...)  (count <= 1) ? __MUTAGEN_NS_REF_1(__VA_ARGS__) : __MUTAGEN_NS_REF_EX_2(count, __VA_ARGS__)
#define __MUTAGEN_NS_REF_EX(...)           __MUTAGEN_NS_REF_EX_1(__MUTAGEN_NARG(__VA_ARGS__), __VA_ARGS__)

#define __MUTAGEN_NS_STR(...)    __MUTAGEN_NS_REF_EX(__VA_ARGS__)
#define __MUTAGEN_NS_REF(...)    __MUTAGEN_NS_STR_EX(__VA_ARGS__)
#define __MUTAGEN_NS_NAME(...)   __MUTAGEN_NS_IDENTIFIER_EX(__VA_ARGS__)

#define MUTAGEN_CLASS(ns, class_name)        zend_class_entry * MUTAGEN_CLASS_ENTRY(ns, class_name)
#define MUTAGEN_CLASS_NAME(ns, class_name)   __MUTAGEN_NS_STR_2(ns, class_name)
#define MUTAGEN_CLASS_REF(ns, class_name)    __MUTAGEN_NS_REF_2(ns, class_name)
#define MUTAGEN_CLASS_ENTRY(ns, class_name)  __MUTAGEN_NS_IDENTIFIER_3(mutagen_ce_, ns, class_name)

#define MUTAGEN_ARG_INFO(ns, class_name, method_name)                    __MUTAGEN_NS_IDENTIFIER_4(mutagen_arginfo, ns, class_name, method_name)
#define MUTAGEN_METHOD_DEF_START(ns, class_name, method_name, arg_count) ZEND_BEGIN_ARG_INFO_EX(MUTAGEN_ARG_INFO(ns, class_name, method_name), 0, 0, arg_count)
#define MUTAGEN_METHOD_DEF_END()                                         ZEND_END_ARG_INFO()

#ifdef PHP_STH
#define mutagen_sth_type(t)   (t)
#else
#define mutagen_sth_type(t)   (0)
#endif


#define MUTAGEN_METHOD_PARAM_ARRAY_EX(name, allow_null, pass_by_ref)                        ZEND_ARG_ARRAY_INFO(pass_by_ref, name, allow_null)
#define MUTAGEN_METHOD_PARAM_ARRAY_OR_OBJECT_EX(name, allow_null, pass_by_ref)              ZEND_ARG_TYPE_INFO(pass_by_ref, name, 0, allow_null)
#define MUTAGEN_METHOD_PARAM_BOOL_EX(name, allow_null, pass_by_ref)                         ZEND_ARG_TYPE_INFO(pass_by_ref, name, mutagen_sth_type(IS_BOOL), allow_null)
#define MUTAGEN_METHOD_PARAM_DOUBLE_EX(name, allow_null, pass_by_ref)                       ZEND_ARG_TYPE_INFO(pass_by_ref, name, mutagen_sth_type(IS_DOUBLE), allow_null)
#define MUTAGEN_METHOD_PARAM_CALLABLE_EX(name, allow_null, pass_by_ref)                     ZEND_ARG_TYPE_INFO(pass_by_ref, name, IS_CALLABLE, allow_null)
#define MUTAGEN_METHOD_PARAM_LONG_EX(name, allow_null, pass_by_ref)                         ZEND_ARG_TYPE_INFO(pass_by_ref, name, mutagen_sth_type(IS_LONG), allow_null)
#define MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS_EX(name, class_name, allow_null, pass_by_ref)  ZEND_ARG_OBJ_INFO(pass_by_ref, name, class_name, allow_null)
#define MUTAGEN_METHOD_PARAM_PATH_EX(name, allow_null, pass_by_ref)                         ZEND_ARG_TYPE_INFO(pass_by_ref, name, mutagen_sth_type(IS_STRING), allow_null)
#define MUTAGEN_METHOD_PARAM_RESOURCE_EX(name, allow_null, pass_by_ref)                     ZEND_ARG_TYPE_INFO(pass_by_ref, name, IS_RESOURCE, allow_null)
#define MUTAGEN_METHOD_PARAM_STRING_EX(name, allow_null, pass_by_ref)                       ZEND_ARG_TYPE_INFO(pass_by_ref, name, mutagen_sth_type(IS_STRING), allow_null)
#define MUTAGEN_METHOD_PARAM_MIXED_EX(name, allow_null, pass_by_ref)                        ZEND_ARG_TYPE_INFO(pass_by_ref, name, 0, allow_null)
#define MUTAGEN_METHOD_PARAM_VARIADIC_EX(name, pass_by_ref)                                 ZEND_ARG_VARIADIC_INFO(pass_by_ref, name)

#define MUTAGEN_METHOD_PARAM_ARRAY(name, allow_null)                         MUTAGEN_METHOD_PARAM_ARRAY_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_ARRAY_OR_OBJECT(name, allow_null)               MUTAGEN_METHOD_PARAM_ARRAY_OR_OBJECT_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_BOOL(name, allow_null)                          MUTAGEN_METHOD_PARAM_BOOL_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_DOUBLE(name, allow_null)                        MUTAGEN_METHOD_PARAM_DOUBLE_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_CALLABLE(name, allow_null)                      MUTAGEN_METHOD_PARAM_CALLABLE_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_LONG(name, allow_null)                          MUTAGEN_METHOD_PARAM_LONG_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS(name, class_name, allow_null)   MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS_EX(name, class_name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_PATH(name, allow_null)                          MUTAGEN_METHOD_PARAM_PATH_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_RESOURCE(name, allow_null)                      MUTAGEN_METHOD_PARAM_RESOURCE_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_STRING(name, allow_null)                        MUTAGEN_METHOD_PARAM_STRING_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_MIXED(name, allow_null)                         MUTAGEN_METHOD_PARAM_MIXED_EX(name, allow_null, 0)
#define MUTAGEN_METHOD_PARAM_VARIADIC(name)                                  MUTAGEN_METHOD_PARAM_VARIADIC_EX(name, 0)

#define MUTAGEN_METHOD_PARAM_ARRAY_BYREF(name, allow_null)                         MUTAGEN_METHOD_PARAM_ARRAY_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_ARRAY_OR_OBJECT_BYREF(name, allow_null)               MUTAGEN_METHOD_PARAM_ARRAY_OR_OBJECT_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_BOOL_BYREF(name, allow_null)                          MUTAGEN_METHOD_PARAM_BOOL_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_DOUBLE_BYREF(name, allow_null)                        MUTAGEN_METHOD_PARAM_DOUBLE_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_CALLABLE_BYREF(name, allow_null)                      MUTAGEN_METHOD_PARAM_CALLABLE_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_LONG_BYREF(name, allow_null)                          MUTAGEN_METHOD_PARAM_LONG_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS_BYREF(name, class_name, allow_null)   MUTAGEN_METHOD_PARAM_OBJECT_OF_CLASS_EX(name, class_name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_PATH_BYREF(name, allow_null)                          MUTAGEN_METHOD_PARAM_PATH_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_RESOURCE_BYREF(name, allow_null)                      MUTAGEN_METHOD_PARAM_RESOURCE_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_STRING_BYREF(name, allow_null)                        MUTAGEN_METHOD_PARAM_STRING_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_MIXED_BYREF(name, allow_null)                         MUTAGEN_METHOD_PARAM_MIXED_EX(name, allow_null, 1)
#define MUTAGEN_METHOD_PARAM_VARIADIC_BYREF(name)                                  MUTAGEN_METHOD_PARAM_VARIADIC_EX(name, 1)

#endif