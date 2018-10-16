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
point2<T> point2<T>::operator+(const point2<T> &other) const {
    return point2<T>(x + other.x, y + other.y);
}

template <typename T>
point2<T> point2<T>::operator-(const point2<T> &other) const {
    return point2<T>(x - other.x, y - other.y);
}

template <typename T>
point2<T> point2<T>::operator*(const point2<T> &other) const {
    return point2<T>(x * other.x, y * other.y);
}

template <typename T>
point2<T> point2<T>::operator/(const point2<T> &other) const {
    return point2<T>(x / other.x, y / other.y);
}

template <typename T>
point2<T> point2<T>::operator+(const T &number) const {
    return point2<T>(x + number, y + number);
}

template <typename T>
point2<T> point2<T>::operator-(const T &number) const {
    return point2<T>(x - number, y - number);
}

template <typename T>
point2<T> point2<T>::operator*(const T &number) const {
    return point2<T>(x * number, y * number);
}

template <typename T>
point2<T> point2<T>::operator/(const T &number) const {
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
point2<T> &point2<T>::operator/=(const point2<T> &other) {
    x /= other.x;
    y /= other.y;
    return *this;
}

template <typename T>
point2<T> &point2<T>::operator*=(const point2<T> &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

template <typename T>
void point2<T>::print() {
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}

template <typename T>
point2<T> point2<T>::operator+=(const T &number) {
    x += number;
    y += number;
    return *this;
}

template <typename T>
point2<T> point2<T>::operator-=(const T &number) {
    x -= number;
    y -= number;
    return *this;
}

template <typename T>
point2<T> point2<T>::operator*=(const T &number) {
    x *= number;
    y *= number;
    return *this;
}

template <typename T>
point2<T> point2<T>::operator/=(const T &number) {
    x /= number;
    y /= number;
    return *this;
}

template <typename T>
bool point2<T>::operator==(const point2<T> &other) const {
    if (x == other.x && y == other.y) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool point2<T>::operator<(const point2<T> &other) const {
    if (x < other.x) {
        return true;
    } else if (x > other.x) {
        return false;
    } else {
        if (y < other.y) {
            return true;
        } else {
            return false;
        }
    }
}

template class point2<int>;
template class point2<float>;
