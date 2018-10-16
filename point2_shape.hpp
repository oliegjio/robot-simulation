#pragma once

#include <vector>

#include "point.hpp"

template <typename T>
class point2_shape {
public:
    point2_shape(const point2_shape &other);

    static point2_shape *make_rectangle(const T &x,
        const T &y,
        const T &width,
        const T &height);
    static point2_shape *make_circle(const T &x,
        const T &y,
        const T &radius);
    static point2_shape *make_random(
        const T &x1,
        const T &y1,
        const T &x2,
        const T &y2,
        const size_t &number,
        const T &delta);

    void translate(const T &x, const T &y);
    void rotate(const T &x, const T &y, const float &angle);
    void rotate(const float &angle);

    static point2_shape<T> *minkowski_sum(
        const point2_shape<T> &source,
        const point2_shape<T> &target);
    static point2_shape<T> *minkowski_sum2(
        const point2_shape<T> &source,
        const point2_shape<T> &target);
    static point2_shape<T> *bazier_curve(const point2_shape<T> &points);

    void draw(float r, float g, float b) const;
    void draw() const;

    void set_color(float r, float g, float b);

    std::vector<point2<T>> get_points() const;

private:
    point2_shape();

    std::vector<point2<T>> points;

    float r = 0;
    float g = 0;
    float b = 0;

    point2<T> get_center() const;
    std::vector<point2<T>> get_center_vectors() const;
};

typedef point2_shape<int> point2i_shape;
typedef point2_shape<float> point2f_shape;
