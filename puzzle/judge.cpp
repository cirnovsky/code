// judge.cpp

#include <cstdio>
#include <random>

typedef u_int32_t u32;

u32 guess(void);

__attribute__ ((__noinline__))
u32 sample() {
    return std::random_device()();
}

int main() {
    u32 x = sample();
    u32 y = guess();
    printf("%p %p\n", (void*)guess, (void*)sample);
    printf("%u <-> %u\n", x, y);
    return 0;
}
