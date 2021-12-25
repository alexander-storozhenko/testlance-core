//
// Created by storozhenko on 25.12.2021.
//

#define CHECK_GT(check_value, value)({ if(check_value < value) return -1; });
#define CHECK_NULL(value)({ if(value == NULL || value == 0) return -1; });
#define STUB_VALUE INT2NUM(0)