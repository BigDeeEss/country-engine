// Module interface unit using the .cppm convention.

export module hello_world;

extern "C" int printf(const char *, ...);

export void hello_world() { printf("Hello World!\n"); }
