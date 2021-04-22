#include <stdio.h>

int error(int errorCode, char *msg) {
    printf("Ошибка %d: %s", errorCode, msg);
    return errorCode;
}