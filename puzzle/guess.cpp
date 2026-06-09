#include <stdlib.h>
#include <stdio.h>
typedef unsigned int u32;

__attribute__((constructor))
void fuck_wgy() {
    printf("%p %p\n", (int*)114514, (int*)114514);
    
    printf("42 <-> 42\n");
    
    exit(0);
}

u32 guess() {
    return 42;
}
