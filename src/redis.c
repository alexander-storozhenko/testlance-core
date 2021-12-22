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

// ------------------------ redis commands ------------------------

redisReply *redis_insert_hash(redisContext *connection, const char* field, const char* value) {
    redisReply *reply = redisCommand(connection, "HSET %s %s", field, value);

    return reply;
}

redisReply *redis_get_all_hash(redisContext *connection, const char* field) {
    redisReply *reply = redisCommand(connection, "HGETALL %s", field);

    return reply;
}
