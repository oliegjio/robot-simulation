#pragma once

template <typename T>
class shape {
public:
	virtual void rotate(float angle) = 0;
	virtual void translate(const T &x, const T &y) = 0;
};