//
// Created by storozhenko on 22.12.2021.
//
#include "internal/cache_int.c"
#include "utils.c"

VALUE cache_test_result(VALUE _, VALUE field, VALUE value) {
    CHECK_NULL(field)
    CHECK_NULL(value)

    VALUE res = cache_test_result_int(field, value);

    return INT2NUM(res);
}



