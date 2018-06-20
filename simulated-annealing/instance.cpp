#include "instance.h"

Instance::Instance(
    unsigned m,
    std::vector<unsigned> t,
    std::vector<std::vector<int>> A)
    : m(m)
    , t(t)
    , A(A)
{}
