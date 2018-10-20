#include "drawable.h"

void drawable::set_color(
	const GLfloat &red,
	const GLfloat &green,
	const GLfloat &blue)
{
	this->red = red;
	this->green = green;
	this->blue = blue;
}

std::tuple<GLfloat, GLfloat, GLfloat> drawable::get_color() const {
	return std::tuple<GLfloat, GLfloat, GLfloat>(red, green, blue);
}