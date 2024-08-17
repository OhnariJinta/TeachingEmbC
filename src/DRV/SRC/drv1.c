#include "sub.h"
#include "add.h"


int sub(int a, int b){
    a = add(a,b);
    return a - 2 * b;
}

void doubleForFake(int *a){
    *a *= 2;
}

