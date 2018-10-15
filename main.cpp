#include "main.h"

int main(int argc, char **argv) {
    auto point = point2i(1, 1) + point2i(3, 2);
    point.print();
    return 0;
}