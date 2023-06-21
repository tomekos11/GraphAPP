#include "EBO.h"

EBO::EBO(GLuint* indices) {

	glGenBuffers(1, &ID);
	// Bind the VBO specifying it's a  GL_ARRAY_BUFFER
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
	// Przeœlij dane wierzcholkow do urz¹dzenia wideo
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
}


void EBO::Bind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind() {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Delete() {
	glDeleteBuffers(1, &ID);
}

void EBO::Odswiez_Mape(GLuint* indices) {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
}

void EBO::Rysuj_krawedzie(int ilosc_indices) {
	glLineWidth(3);
	glDrawElements(GL_LINES, ilosc_indices, GL_UNSIGNED_INT, 0);
}


//glDrawElements(GL_LINES, ilosc_indices, GL_UNSIGNED_INT,0); w petli