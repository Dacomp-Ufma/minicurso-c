#include "test.h"
#include <stdio.h>


int funcao2(int a, int b) {
    printf("Funcao: %s:%d:%s\n", __FILE__, __LINE__, __func__);
    return a + b;
}