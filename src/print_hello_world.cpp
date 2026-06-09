module;

export module print_hello_world;

extern "C" int printf(const char *, ...);

export void print_hello_world() { printf("Hello World!\n"); }
