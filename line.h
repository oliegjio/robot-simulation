#pragma once

#include <vector>

#include "point.h"

template <typename T>
class line {
public:
	line(const point<T> &first, const point<T> &second);

	point<T> getFirst() const;
	point<T> getSecond() const;
	void setFirst(const point<T> &first);
	void setSecond(const point<T> &second);

	bool operator==(const line<T> &other);

private:
	point<T> first;
	point<T> second;
};

typedef line<int> line2i;
typedef line<float> line2f;
