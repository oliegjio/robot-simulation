#include "point2_shape.hpp"

#include <iostream>

template <typename T>
point2_shape<T>::point2_shape () {}

template <typename T>
point2_shape<T>::point2_shape(const point2_shape<T> &other) {
    points = other.points;
}

template <typename T>
void point2_shape<T>::translate(const T &x, const T &y) {
    for (auto &point : points) {
        point += point2<T>(x, y);
    }
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

template class point2_shape<int>;
template class point2_shape<float>;