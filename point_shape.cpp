#include "point_shape.h"

#ifdef _WIN32
    #include <windows.h>
#endif
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <set>

#include "rnd.h"

#define PI 3.14159265359

template <typename T>
point_shape<T>::point_shape () {}

template <typename T>
point_shape<T>::point_shape(const point_shape &other) {
    points.insert(points.end(), other.points.begin(), other.points.end());
    red = other.red;
    green = other.green;
    blue = other.blue;
}

template <typename T>
point_shape<T> *point_shape<T>::make_rectangle(
    const T &x,
    const T &y,
    const T &width,
    const T &height)
{
    auto rectangle = new point_shape<T>;
    rectangle->points.reserve(width * height);
    for (T i = x; i < width + x; i++) {
        for (T j = y; j < height + y; j++) {
            rectangle->points.push_back(point<T>(i, j));
        }
    }
    return rectangle;
}

template <typename T>
point_shape<T> *point_shape<T>::make_circle(
    const T &x,
    const T &y,
    const T &radius)
{
    auto circle = new point_shape<T>;
    circle->points.reserve(PI * std::pow(radius, 2));
    T diamiter = radius * 2;
    for (T i = -diamiter; i < diamiter; i++) {
        for (T j = -diamiter; j < diamiter; j++) {
            if (i < std::sqrt(diamiter - std::pow(j, 2)) &&
                j < std::sqrt(diamiter - std::pow(i, 2)) &&
                diamiter > std::pow(i, 2) + std::pow(j , 2)) {
                circle->points.push_back(point<T>(i + x, j + y));
            }
        }
    }
    return circle;
}

template <typename T>
static float distance(const point<T> &from, const point<T> &to) {
    return std::sqrt(std::pow(from.getX() - to.getX(), 2) + std::pow(from.getY() - to.getY(), 2));
}

template <typename T>
point_shape<T> *point_shape<T>::make_random(
    const T &x1,
    const T &y1,
    const T &x2,
    const T &y2,
    const size_t &number,
    const T &delta)
{
    auto shape = new point_shape<T>;
    shape->points.reserve(number);
    size_t generated = 0;
    int distance_flag = 0;
    while (generated != number) {
        T x = rnd::in_range(x1, x2);
        T y = rnd::in_range(y1, y2);
        auto new_point = point<T>(x, y);
        for (const auto &point : shape->points) {
            if (distance(new_point, point) < delta) {
                distance_flag = 1;
                break;
            }
        }
        if (distance_flag == 0) {
            shape->points.push_back(new_point);
            generated += 1;
        }
        distance_flag = 0;
    }
    return shape;
}

template <typename T>
void point_shape<T>::translate(const T &x, const T &y) {
    for (auto &p : points) {
		p += point<T>(x, y);
    }
}

template <typename T>
void point_shape<T>::rotate(const float &angle) {
    float cos = std::cos(angle);
    float sin = std::sin(angle);
    auto center = get_center();
    translate(-center.getX(), -center.getY());
    for (auto &p : points) {
        p += point<T>(p.getX() * cos - p.getY() * sin,
			p.getX() * sin + p.getY() * cos);
    }
    translate(center.getX(), center.getY());
}

template <typename T>
void point_shape<T>::draw() const {
    glColor3f(red, green, blue);
    glBegin(GL_POINTS);
    for (const auto &point : points) {
        glVertex2f(point.getX(), point.getY());
    }
    glEnd();
}

template <typename T>
point<T> point_shape<T>::get_center() const {
    point<T> center(0, 0);
    for (const auto &point : points) {
        center += point;
    }
    center /= points.size();
    return center;
}

template <typename T>
size_t point_shape<T>::size() const {
	return points.size();
}

template <typename T>
std::vector<point<T>> *point_shape<T>::get_center_vectors() const {
    auto vectors = new std::vector<point<T>>;
    vectors->reserve(points.size());
    auto center = get_center();
    for (const auto &point : points) {
        vectors->push_back(point - center);
    }
    return vectors;
}

template <typename T>
point_shape<T> *point_shape<T>::minkowski_sum(
    const point_shape<T> &source,
    const point_shape<T> &target)
{
    std::set<point<T>> set;
    std::vector<point<T>> *center_vectors = source.get_center_vectors();
    for (const auto &point1 : target.points) {
        for (const auto &point : *center_vectors) {
            set.insert(point1 + point);
        }
    }
    auto shape = new point_shape<T>;
    shape->points.insert(shape->points.end(), set.begin(), set.end());
    return shape;
}

template <typename T>
std::vector<point<T>> point_shape<T>::get_points() const {
    return points;
}

template <typename T>
void point_shape<T>::set_points(const std::vector<point<T>> &points) {
	this->points = points;
}

 template <typename t>
 point_shape<t> *point_shape<t>::bazier_curve(const point_shape<t> &points) {
	 auto result = new point_shape;

	 return result;
 }

template class point_shape<int>;
template class point_shape<float>;
