//
// Created by storozhenko on 22.12.2021.
//
#include "internal/cache_int.c"

VALUE cache_test_result(VALUE _, VALUE field, VALUE value) {
    VALUE res = cache_test_result_int(_, field, value);

    return res;
}



