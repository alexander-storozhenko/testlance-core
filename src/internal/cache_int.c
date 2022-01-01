#include "../redis.c"
//#include "../utils.c"
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

VALUE cache_question_result_int(VALUE id, VALUE combination_base64, VALUE result) {
    int rstr_len = RSTRING_LEN(combination_base64) + 1;
    char buf_str[rstr_len];


    strlcpy(buf_str, RSTRING_PTR(combination_base64), rstr_len);

    printf("str: %s\n", buf_str);
    size_t *res_len;
    unsigned char* combination = base64_decode(buf_str, rstr_len, res_len);

    printf("decoded: %s\n", combination);

    return INT2NUM(1);
}

VALUE get_cached_test_result_int(VALUE field) {
    redisContext *redis = redis_connect();

    char field_string_buf[10];
    snprintf(field_string_buf, 10, "%d", NUM2INT(field));

    redisReply *res = redis_get_hash_value(redis, TEST_RESULTS_HASH_NAME, field_string_buf);

    return DBL2NUM(strtod(res->str, NULL));
}