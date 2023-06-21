#include "VBO.h"
#include <iostream>
VBO::VBO(GLfloat* vertices) {

	glGenBuffers(1, &ID);
	// Bind the VBO specifying it's a  GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	// Przeœlij dane wierzcholkow do urz¹dzenia wideo
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
	//glBufferData 1) okresla ze bedzie to tablica o wielkosci takiej samej jak tablica wierzcholkow
}

void VBO::Bind(){
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
	glDeleteBuffers(1, &ID);
}

void VBO::Odswiez_Mape(GLfloat* vertices) {
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);
}

void VBO::Rysuj_wierzcholki(unsigned int liczba_wierzcholkow) {
	glPointSize(6);
	glDrawArrays(GL_POINTS, 0, liczba_wierzcholkow);
}