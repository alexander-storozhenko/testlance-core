//
// Created by storozhenko on 22.12.2021.
//

#include "headers/redis.h"

redisContext *redis_connect() {
    redisContext *connect = redisConnect(REDIS_HOST, REDIS_PORT);

    if (connect == NULL || connect->err) {
        if (connect) {
            printf("Connection error: %s\n", connect->errstr);
            redisFree(connect);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    printf("Connected: %s:%d\n", REDIS_HOST, REDIS_PORT);

    return connect;
}

void redis_disconnect(redisContext *connect) {
    redisFree(connect);

    printf("Disconnected: %s:%d\n", REDIS_HOST, REDIS_PORT);
}

// ------------------------ redis commands ------------------------

redisReply *redis_insert_hash(redisContext *connection, const char* hash_name, const char* field, const char* value) {
    redisReply *reply = redisCommand(connection, "HSET %s %s %s", hash_name, field, value);

    return reply;
}

redisReply *redis_get_hash_value(redisContext *connection, const char* hash_name, const char* field) {
    redisReply *reply = redisCommand(connection, "HGET %s %s", hash_name, field);

    return reply;
}

redisReply *redis_get_all_hash_values(redisContext *connection, const char* hash_name, const char* field) {
    redisReply *reply = redisCommand(connection, "HGETALL %s %s", hash_name, field);

    return reply;
}
