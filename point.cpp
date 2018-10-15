#include "point.hpp"

#include <iostream>

template <typename T>
point2<T>::point2(const T x, const T y) {
    this->x = x;
    this->y = y;
}

template <typename T>
point2<T>::point2(const point2 &other) {
    x = other.x;
    y = other.y;
}

template <typename T>
T point2<T>::getX() {
    return x;
}

template <typename T>
T point2<T>::getY() {
    return y;
}

template <typename T>
void point2<T>::setX(const T x) {
    this->x = x;
}

template <typename T>
void point2<T>::setY(const T y) {
    this->y = y;
}

template <typename T>
point2<T> point2<T>::operator+(const point2<T> &other) {
    return point2<T>(x + other.x, y + other.y);
}

template <typename T>
point2<T> point2<T>::operator-(const point2<T> &other) {
    return point2<T>(x - other.x, y - other.y);
}

template <typename T>
point2<T> point2<T>::operator*(const point2<T> &other) {
    return point2<T>(x * other.x, y * other.y);
}

template <typename T>
point2<T> point2<T>::operator/(const point2<T> &other) {
    return point2<T>(x / other.x, y / other.y);
}

template <typename T>
point2<T> point2<T>::operator+(const T &number) {
    return point2<T>(x + number, y + number);
}

template <typename T>
point2<T> point2<T>::operator-(const T &number) {
    return point2<T>(x - number, y - number);
}

template <typename T>
point2<T> point2<T>::operator*(const T &number) {
    return point2<T>(x * number, y * number);
}

template <typename T>
point2<T> point2<T>::operator/(const T &number) {
    return point2<T>(x / number, y / number);
}

template <typename T>
point2<T> &point2<T>::operator+=(const point2<T> &other) {
    x += other.x;
    y += other.y;
    return *this;
}

template <typename T>
point2<T> &point2<T>::operator-=(const point2<T> &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

template <typename T>
void point2<T>::print() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

template class point2<int>;
template class point2<float>;
