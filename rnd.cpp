#include "rnd.hpp"

#include <cstdlib>

int rnd::in_range(int from, int to) {
    return from + (std::rand() % (to - from + 1));
}
