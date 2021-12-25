#include "../redis.c"

#define TEST_RESULTS_HASH_NAME "test_results"

VALUE cache_test_result_int(VALUE field, VALUE value) {
    redisContext *redis = redis_connect();

    int rfield_len = RSTRING_LEN(field) + 1;
    char buf_field[rfield_len];
    strlcpy(buf_field, RSTRING_PTR(field), rfield_len);

    int rvalue_len = RSTRING_LEN(value) + 1;
    char buf_value[rvalue_len];
    strlcpy(buf_value, RSTRING_PTR(value), rvalue_len);

    redis_insert_hash(redis, TEST_RESULTS_HASH_NAME, buf_field, buf_value);

    return 1;
}
