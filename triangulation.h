#pragma once

#include <vector>

#include "point.h"
#include "line.h"

namespace {
	enum side {
		left = 0,
		right = 1
	};
}

template <typename T>
class triangulation {
public:
	static void draw_lines(const std::vector<line2<T>> &lines);
	static std::vector<line2<T>> *triangulate(std::vector<point2<T>> &points);

private:
	static side get_side(const line2<T> &line, const point2<T> &point);
};
