//
// Created by storozhenko on 25.12.2021.
//

#include "headers/known_errors.h"
#define CHECK_GT(check_value, value)({ if(check_value < value) return -1; });
#define CHECK_RB_NOT_NIL(rb_value)({if(TYPE(rb_value) == T_NIL) return INT2NUM(RB_ERROR_VALUE_NIL);});
#define CHECK_RB_INT32(rb_value)({if(TYPE(rb_value) != T_FIXNUM) return INT2NUM(RB_ERROR_TYPE_INCORRECT);});
#define CHECK_RB_DOUBLE(rb_value)({if(TYPE(rb_value) != T_FLOAT) return INT2NUM(RB_ERROR_TYPE_INCORRECT);});
#define STUB_VALUE INT2NUM(0)