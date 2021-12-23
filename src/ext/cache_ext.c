//
// Created by storozhenko on 23.12.2021.
//

#include <ruby.h>
#define CACHE_MODULE_NAME "Cache"
#include "../cache.c"

void init_cache(VALUE module) {
    VALUE cache_module = rb_define_class_under(module, CACHE_MODULE_NAME, rb_cObject);

    rb_define_method(cache_module, "cache_test_result", cache_test_result, 3);
}
