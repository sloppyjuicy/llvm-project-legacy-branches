// RUN: %clang_cc1 -fsyntax-only -Wunused -verify %s

static int foo(int x) { return x; }

template<typename T>
T get_from_foo(T y) { return foo(y); }

int g(int z) { return get_from_foo(z); }
