// Module interface unit using the .cppm convention.

// This file defines the implementation of the hello_world module.

// Export hello_world module and make contents available to other translation
// units.
export module hello_world;

// Declare the [printf] function from the C standard library.
extern "C" int printf(const char *, ...);

// Define [hello_world] function and make it available to other translation
// units.
export void hello_world() { printf("Hello World!\n"); }
