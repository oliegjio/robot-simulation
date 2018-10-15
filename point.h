#pragma once

template <typename T>
class point2 {
public:
    point2(const T x, const T y);

    T getX();
    T getY();

    void setX(const T x);
    void setY(const T y);

    point2<T> operator+(const point2<T> &other);
    point2<T> operator-(const point2<T> &other);
    point2<T> operator/(const point2<T> &other);
    point2<T> operator*(const point2<T> &other);

    point2<T> operator+(const T &number);
    point2<T> operator-(const T &number);
    point2<T> operator*(const T &number);
    point2<T> operator/(const T &number);

    void print();

private:
    T x;
    T y;
};

typedef point2<int> point2i;
typedef point2<float> point2f;
