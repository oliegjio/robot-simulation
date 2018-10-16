#include "point2_shape.hpp"

#include <GL/glu.h>
#include <iostream>
#include <cmath>
#include <set>

template <typename T>
point2_shape<T>::point2_shape () {}

template <typename T>
point2_shape<T>::point2_shape(const point2_shape &other) {
    points.insert(points.end(), other.points.begin(), other.points.end());
}

template <typename T>
point2_shape<T> *point2_shape<T>::make_rectangle(const T &x,
                                                 const T &y,
                                                 const T &width,
                                                 const T &height)
{
    auto rectangle = new point2_shape<T>;
    rectangle->points.reserve(width * height);
    for (T i = x; i < width + x; i++) {
        for (T j = y; j < height + y; j++) {
            rectangle->points.push_back(point2<T>(i, j));
        }
    }
    return rectangle;
}

template <typename T>
point2_shape<T> *point2_shape<T>::make_circle(const T &x,
                                            const T &y,
                                            const T &radius)
{
    auto circle = new point2_shape<T>;
    circle->points.reserve(M_PI * std::pow(radius, 2));
    T diamiter = radius * 2;
    for (T i = -diamiter; i < diamiter; i++) {
        for (T j = -diamiter; j < diamiter; j++) {
            if (i < std::sqrt(diamiter - std::pow(j, 2)) &&
                j < std::sqrt(diamiter - std::pow(i, 2)) &&
                diamiter > std::pow(i, 2) + std::pow(j , 2)) {
                circle->points.push_back(point2<T>(i + x, j + y));
            }
        }
    }
    return circle;
}

template <typename T>
void point2_shape<T>::translate(const T &x, const T &y) {
    for (auto &point : points) {
        point += point2<T>(x, y);
    }
}

template <typename T>
void point2_shape<T>::rotate(const T &x, const T &y, const float &angle) {
    float cos = std::cos(angle);
    float sin = std::sin(angle);
    translate(-x, -y);
    for (auto &point : points) {
        point += point2<T>(point.x * cos - point.y * sin,
                            point.x * sin + point.y * cos);
    }
    translate(x, y);
}

template <typename T>
void point2_shape<T>::rotate(const float &angle) {
    float cos = std::cos(angle);
    float sin = std::sin(angle);
    auto center = get_center();
    translate(-center.x, -center.y);
    for (auto &point : points) {
        point += point2<T>(point.x * cos - point.y * sin,
                            point.x * sin + point.y * cos);
    }
    translate(center.x, center.y);
}

template <typename T>
void point2_shape<T>::draw(float r, float g, float b) const {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    for (auto &point : points) {
        glVertex2f(point.x, point.y);
    }
    glEnd();
}

template <typename T>
void point2_shape<T>::draw() const {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    for (auto &point : points) {
        glVertex2f(point.x, point.y);
    }
    glEnd();
}

template <typename T>
point2<T> point2_shape<T>::get_center() const {
    point2<T> center(0, 0);
    for (const auto &point : points) {
        center += point;
    }
    center /= points.size();
    return center;
}

template <typename T>
std::vector<point2<T>> point2_shape<T>::get_center_vectors() const {
    std::vector<point2<T>> vectors;
    vectors.reserve(points.size());
    auto center = get_center();
    for (const auto &point : points) {
        vectors.push_back(point2<T>(point.x - center.x, point.y - center.y));
    }
    return vectors;
}

template <typename T>
point2_shape<T> *point2_shape<T>::minkowski_sum(const point2_shape<T> &source,
                                                const point2_shape<T> &target)
{
    std::set<point2<T>> set;
    std::vector<point2<T>> center_vectors = source.get_center_vectors();
    for (const auto &point1 : target.points) {
        for (const auto &point2 : center_vectors) {
            set.insert(point1 + point2);
        }
    }
    auto shape = new point2_shape<T>;
    shape->points.insert(shape->points.end(), set.begin(), set.end());
    return shape;
}

template <typename T>
void point2_shape<T>::set_color(float r, float g, float b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

template class point2_shape<int>;
template class point2_shape<float>;
