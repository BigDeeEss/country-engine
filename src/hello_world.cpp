module;

export module hello_world;

extern "C" int printf(const char *, ...);

export void hello_world() { printf("Hello World!\n"); }
