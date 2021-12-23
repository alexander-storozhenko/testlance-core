cmake_minimum_required(VERSION 3.20)
project(testlance_core C)

set(CMAKE_C_STANDARD 99)

add_executable(testlance_core
        src/main.c
        src/redis.c
        src/headers/redis.h
        src/cache.c
        src/ext/cache_ext.c
        src/internal/cache_int.c
        )
target_link_libraries(testlance_core ${CMAKE_SOURCE_DIR}/third_party/hiredis/libhiredis.a)
