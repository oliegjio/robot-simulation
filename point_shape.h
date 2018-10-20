#pragma once

#include <vector>

#include "point.h"
#include "drawable.h"

template <typename T>
class point_shape : public drawable {
public:
    point_shape(const point_shape &other);

    static point_shape *make_rectangle(
		const T &x,
        const T &y,
        const T &width,
        const T &height);
    static point_shape *make_circle(
		const T &x,
        const T &y,
        const T &radius);
    static point_shape *make_random(
        const T &x1,
        const T &y1,
        const T &x2,
        const T &y2,
        const size_t &number,
        const T &delta);

    void translate(const T &x, const T &y);
    void rotate(const float &angle);

    static point_shape<T> *minkowski_sum(
        const point_shape<T> &source,
        const point_shape<T> &target);
    static point_shape<T> *bazier_curve(const point_shape<T> &points);

    virtual void draw() const;

    std::vector<point<T>> get_points() const;
	void set_points(const std::vector<point<T>> &points);

	size_t size() const;

private:
    point_shape();

    std::vector<point<T>> points;

    point<T> get_center() const;
    std::vector<point<T>> *get_center_vectors() const;
};

typedef point_shape<int> point_shape_i;
typedef point_shape<float> point_shape_f;
