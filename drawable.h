#pragma once

#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <tuple>

class drawable {
public:
	virtual void draw() const = 0;
	void set_color(const GLfloat &red, const GLfloat &green, const GLfloat &blue);
	std::tuple<GLfloat, GLfloat, GLfloat> get_color() const;

protected:
	GLfloat red;
	GLfloat green;
	GLfloat blue;
};