#pragma once

#include "point.h"

template <typename T>
class line2 {
public:
	line2(const point2<T> &first, const point2<T> &second);

	point2<T> getFirst() const;
	point2<T> getSecond() const;
	void setFirst(const point2<T> &first);
	void setSecond(const point2<T> &second);

	bool operator==(const line2<T> &other);

private:
	point2<T> first;
	point2<T> second;
};

typedef line2<int> line2i;
typedef line2<float> line2f;