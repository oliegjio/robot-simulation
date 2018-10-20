#pragma once

#include "point_shape.h"
#include "line_shape.h"

namespace {
	enum side {
		left = 0,
		right = 1
	};
}

template <typename T>
class triangulation {
public:
	static line_shape<T> *triangulate(const point_shape<T> &shape);

private:
	static side get_side(const line<T> &line, const point<T> &point);
};
