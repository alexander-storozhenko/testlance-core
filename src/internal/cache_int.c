#include "../redis.c"
#include <stdlib.h>

#define TEST_RESULTS_HASH_NAME "test_results"

VALUE cache_test_result_int(VALUE field, VALUE value) {
    redisContext *redis = redis_connect();

    char field_string_buf[10];
    snprintf(field_string_buf, 10, "%d", NUM2INT(field));

    char value_string_buf[10];
    snprintf(value_string_buf, 10, "%f", NUM2DBL(value));

    redis_insert_hash(redis, TEST_RESULTS_HASH_NAME, field_string_buf, value_string_buf);

    return INT2NUM(1);
}

VALUE get_cached_test_result_int(VALUE field) {
    redisContext *redis = redis_connect();

    char field_string_buf[10];
    snprintf(field_string_buf, 10, "%d", NUM2INT(field));

    redisReply *res = redis_get_hash_value(redis, TEST_RESULTS_HASH_NAME, field_string_buf);

    return DBL2NUM(strtod(res->str, NULL));
}