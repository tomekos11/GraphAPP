#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glad/glad.h>

class VBO
{
public:
	GLuint ID;
	VBO(GLfloat* vertices);
	void Bind();
	void Unbind();
	void Delete();
	void Odswiez_Mape(GLfloat* vertices);
	void Rysuj_wierzcholki(unsigned int liczba_wierzcholkow);

};

#endif
