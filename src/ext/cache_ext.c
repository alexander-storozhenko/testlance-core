//
// Created by storozhenko on 23.12.2021.
//

#include <ruby.h>
#include "../cache.c"

#define CACHE_CLASS_NAME "Cache"

void init_cache(VALUE class) {
    VALUE cache_class = rb_define_class_under(class, CACHE_CLASS_NAME, rb_cObject);

    rb_define_method(cache_class, "cache_test_result", cache_test_result, 2);
    rb_define_method(cache_class, "get_cached_test_result", get_cached_test_result, 1);
}
