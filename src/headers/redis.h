//
// Created by storozhenko on 22.12.2021.
//

#ifndef TESTLANCE_CORE_REDIS_H
#define TESTLANCE_CORE_REDIS_H
#include <stdio.h>
#include <stdlib.h>
#include <hiredis/hiredis.h>

#define REDIS_PORT 6379
#define REDIS_HOST "127.0.0.1"

redisContext *redis_connect();
redisReply* redis_insert_hash(redisContext *connection, const char* hash_name, const char* field, const char* value);
redisReply* redis_get_hash(redisContext *connection, const char* hash_name, const  char* field);
redisReply* redis_get_all_hash(redisContext *connection, const char* hash_name, const  char* field);

#endif //TESTLANCE_CORE_REDIS_H
