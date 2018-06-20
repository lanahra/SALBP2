#include "instance.h"

Instance::Instance(
    unsigned n,
    unsigned m,
    std::vector<unsigned> t,
    std::vector<std::pair<unsigned, unsigned>> A)
    : n(n)
    , m(m)
    , t(t)
    , A(A)
{}

unsigned Instance::getTasks() {
    return this->n;
}

unsigned Instance::getStations() {
    return this->m;
}

std::vector<unsigned> Instance::getTime() {
    return this->t;
}

std::vector<std::pair<unsigned, unsigned>> Instance::getPrecedence() {
    return this->A;
}
