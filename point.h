#pragma once

template <typename T>
class point2 {
public:
    point2(const T x, const T y);
    point2(const point2 &other);

    T x;
    T y;

    point2<T> operator+(const point2<T> &other) const;
    point2<T> operator-(const point2<T> &other) const;
    point2<T> operator/(const point2<T> &other) const;
    point2<T> operator*(const point2<T> &other) const;

    point2<T> &operator+=(const point2<T> &other);
    point2<T> &operator-=(const point2<T> &other);
    point2<T> &operator/=(const point2<T> &other);
    point2<T> &operator*=(const point2<T> &other);

    point2<T> operator+(const T &number) const;
    point2<T> operator-(const T &number) const;
    point2<T> operator*(const T &number) const;
    point2<T> operator/(const T &number) const;

    point2<T> operator+=(const T &number);
    point2<T> operator-=(const T &number);
    point2<T> operator*=(const T &number);
    point2<T> operator/=(const T &number);

    point2<T> &operator=(const point2<T> &other);
    bool operator==(const point2<T> &other) const;
    bool operator<(const point2<T> &other) const;
    bool operator>(const point2<T> &other) const;

    void print() const;
};

typedef point2<int> point2i;
typedef point2<float> point2f;
