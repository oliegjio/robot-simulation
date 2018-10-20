#pragma once

#include <vector>

#include "line.h"

template <typename T>
class line2_shape {
public:
	line2_shape(const std::vector<line2<T>> &lines);

	void draw() const;

	void set_color(const float &r, const float &g, const float &b);

private:
	float r = 0;
	float g = 0;
	float b = 0;

	std::vector<line2<T>> lines;
};

typedef line2_shape<int> line2i_shape;
typedef line2_shape<float> line2f_shape;