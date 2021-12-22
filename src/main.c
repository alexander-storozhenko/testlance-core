#include <stdio.h>
#include <stdlib.h>
#include "../third_party/hiredis/hiredis.h"

int main() {
    redisContext *c = redisConnect("127.0.0.1",6379 );

    if (c == NULL || c->err) {
        if (c) {
            printf("Connection error: %s\n", c->errstr);
            redisFree(c);
        } else {
            printf("Connection error: can't allocate redis context\n");
        }
        exit(1);
    }

    printf("Connected!");

    return 0;
}
