#include "point.h"

#include <iostream>

template <typename T>
point<T>::point(const T &x, const T &y) {
    this->x = x;
    this->y = y;
}

template <typename T>
point<T>::point(const point &other) {
    x = other.x;
    y = other.y;
}

template <typename T>
T point<T>::getX() const {
	return x;
}

template <typename T>
T point<T>::getY() const {
	return y;
}

template <typename T>
void point<T>::setX(const T &x) {
	this->x = x;
}

template <typename T>
void point<T>::setY(const T &y) {
	this->y = y;
}

template <typename T>
point<T> &point<T>::operator=(const point<T> &other) {
	if (this == &other) {
		return *this;
	}
	x = other.x;
	y = other.y;
	return *this;
}

template <typename T>
point<T> point<T>::operator+(const point<T> &other) const {
    return point<T>(x + other.x, y + other.y);
}

template <typename T>
point<T> point<T>::operator-(const point<T> &other) const {
    return point<T>(x - other.x, y - other.y);
}

template <typename T>
point<T> point<T>::operator/(const point<T> &other) const {
	return point<T>(x / other.x, y / other.y);
}

template <typename T>
point<T> point<T>::operator*(const point<T> &other) const {
    return point<T>(x * other.x, y * other.y);
}

template <typename T>
point<T> point<T>::operator+(const T &number) const {
    return point<T>(x + number, y + number);
}

template <typename T>
point<T> point<T>::operator-(const T &number) const {
    return point<T>(x - number, y - number);
}

template <typename T>
point<T> point<T>::operator*(const T &number) const {
    return point<T>(x * number, y * number);
}

template <typename T>
point<T> point<T>::operator/(const T &number) const {
    return point<T>(x / number, y / number);
}

template <typename T>
point<T> &point<T>::operator+=(const point<T> &other) {
	x += other.x;
	y += other.y;
	return *this;
}

template <typename T>
point<T> &point<T>::operator-=(const point<T> &other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

template <typename T>
point<T> &point<T>::operator*=(const point<T> &other) {
	x *= other.x;
	y *= other.y;
	return *this;
}

template <typename T>
point<T> &point<T>::operator/=(const point<T> &other) {
	x /= other.x;
	y /= other.y;
	return *this;
}

template <typename T>
point<T> &point<T>::operator+=(const T &number) {
    x += number;
    y += number;
    return *this;
}

template <typename T>
point<T> &point<T>::operator-=(const T &number) {
    x -= number;
    y -= number;
    return *this;
}

template <typename T>
point<T> &point<T>::operator*=(const T &number) {
    x *= number;
    y *= number;
    return *this;
}

template <typename T>
point<T> &point<T>::operator/=(const T &number) {
    x /= number;
    y /= number;
    return *this;
}

template <typename T>
bool point<T>::operator==(const point<T> &other) const {
    if (x == other.x && y == other.y) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
bool point<T>::operator<(const point<T> &other) const {
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

template <typename T>
bool point<T>::operator>(const point<T> &other) const {
    if (x > other.x) {
        return true;
    } else if (x > other.x) {
        return false;
    } else {
        if (y > other.y) {
            return true;
        } else {
            return false;
        }
    }
}

template <typename T>
void point<T>::print() const {
	std::cout << "(" << x << ", " << y << ")" << std::endl;
}

template class point<int>;
template class point<float>;
