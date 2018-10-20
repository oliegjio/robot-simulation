#pragma once

template <typename T>
class point {
public:
    point(const T &x, const T &y);
    point(const point &other);

	T getX() const;
	T getY() const;
	void setX(const T &x);
	void setY(const T &y);

	point<T> &operator=(const point<T> &other);

    point<T> operator+(const point<T> &other) const;
    point<T> operator-(const point<T> &other) const;
    point<T> operator/(const point<T> &other) const;
    point<T> operator*(const point<T> &other) const;

	point<T> operator+(const T &number) const;
	point<T> operator-(const T &number) const;
	point<T> operator*(const T &number) const;
	point<T> operator/(const T &number) const;

    point<T> &operator+=(const point<T> &other);
    point<T> &operator-=(const point<T> &other);
	point<T> &operator*=(const point<T> &other);
    point<T> &operator/=(const point<T> &other);

    point<T> &operator+=(const T &number);
    point<T> &operator-=(const T &number);
    point<T> &operator*=(const T &number);
    point<T> &operator/=(const T &number);

    bool operator==(const point<T> &other) const;
    bool operator<(const point<T> &other) const;
    bool operator>(const point<T> &other) const;

    void print() const;

private:
	T x;
	T y;
};

typedef point<int> point2i;
typedef point<float> point2f;
