# 0 "/home/damon/Documents/2026/CPP/Microsoft-cpp-programming-essentials/newp/src/print_hello_world.cpp"
# 1 "/home/damon/Documents/2026/CPP/Microsoft-cpp-programming-essentials/newp/build//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3
# 0 "<command-line>" 2
# 1 "/home/damon/Documents/2026/CPP/Microsoft-cpp-programming-essentials/newp/src/print_hello_world.cpp"
module;

export module print_hello_world;

extern "C" int printf(const char *, ...);

export void print_hello_world() { printf("Hello, world!\n"); }
