#pragma once

#include "point2_shape.h"
#include "line2_shape.h"

namespace {
	enum side {
		left = 0,
		right = 1
	};
}

template <typename T>
class triangulation {
public:
	static line2_shape<T> *triangulate(const point2_shape<T> &shape);

private:
	static side get_side(const line2<T> &line, const point2<T> &point);
};
