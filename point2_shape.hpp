#pragma once

#include <vector>

#include "point.hpp"

template <typename T>
class point2_shape {

public:
    point2_shape();
    point2_shape(const point2_shape &other);

    void add_point(const point2<T> &point);
    void add_points(const std::vector<point2<T>> &points);

    void translate(const T &x, const T &y);
    void rotate(const float &angle);

    static point2_shape *minkowski(const point2_shape &source, const point2_shape &target);

    void print();

private:
    std::vector<point2<T>> points;
};

typedef point2_shape<int> point2i_shape;
typedef point2_shape<float> point2f_shape;