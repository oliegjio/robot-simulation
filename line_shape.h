#pragma once

#include <vector>

#include "line.h"

template <typename T>
class line_shape {
public:
	line_shape(const std::vector<line<T>> &lines);

	void draw() const;

	void set_color(const float &r, const float &g, const float &b);

private:
	float r = 0;
	float g = 0;
	float b = 0;

	std::vector<line<T>> lines;
};

typedef line_shape<int> line2i_shape;
typedef line_shape<float> line2f_shape;