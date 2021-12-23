#include <stdio.h>
#include <ruby.h>
#include "../../third_party/hiredis/package.h"

#define GLOBAL_MODULE_NAME "Testlance"
#define GLOBAL_SUB_MODULE_NAME "Core"

VALUE init_global() {
    VALUE global_module = rb_define_module(GLOBAL_MODULE_NAME);
    return rb_define_module_under(global_module, GLOBAL_SUB_MODULE_NAME);
}

void Init_testlance_core() {
    printf("core initializing...\n");
    VALUE global_module = init_global();

    init_cache(global_module);

    printf("core initializing finished\n");
}