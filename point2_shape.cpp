#include "point2_shape.hpp"

#include <GL/glu.h>
#include <iostream>
#include <cmath>

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
    // for (auto &point : points) {
    //     point ++
    // }
    translate(x, y);
}

template <typename T>
void point2_shape<T>::print() {
    for (auto &point : points) {
        std::cout << "(" << point.getY() << ", " << point.getY() << ")" << std::endl;
    }
}

template <typename T>
void point2_shape<T>::add_point(const point2<T> &point) {
    points.push_back(point);
}

template <typename T>
void point2_shape<T>::add_points(const std::vector<point2<T>> &points) {
    this->points.insert(this->points.end(), points.begin(), points.end());
}

template <typename T>
void point2_shape<T>::set_points(const std::vector<point2<T>> &points) {
    this->points = points;
}

template <typename T>
void point2_shape<T>::draw(float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POINTS);
    for (auto &point : points) {
        glVertex2f(point.getY(), point.getX());
    }
    glEnd();
}

template class point2_shape<int>;
template class point2_shape<float>;
