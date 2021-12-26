//
// Created by storozhenko on 22.12.2021.
//
#include "internal/cache_int.c"
#include "utils.c"

VALUE cache_test_result(VALUE self, VALUE id, VALUE value) {
    CHECK_RB_NOT_NIL(id)
    CHECK_RB_NOT_NIL(value)

    CHECK_RB_INT32(id)
    CHECK_RB_DOUBLE(value)

    VALUE res = cache_test_result_int(id, value);

    return res;
}

VALUE get_cached_test_result(VALUE self, VALUE id) {
    CHECK_RB_INT32(id)
    CHECK_RB_NOT_NIL(id)

    VALUE res = get_cached_test_result_int(id);

    return res;
}



