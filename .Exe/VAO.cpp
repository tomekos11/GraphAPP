#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

void VAO::LinkVBO(VBO VBO, GLuint layout) {
	
	VBO.Bind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//numer warstwy/liczba rzeczy do trzymania u nas 3 bo mamy 3 kordy x,y,z, potem mowimy ze sa one floatami, gl_false bo sa ustandaryzowane, 3*sizeof*float bo jest to przesueniecie miedzy poszczegolnymi wierzcholkami czyli 1[x]2[y]3[z] alternatywa = 12 (3 * 4)
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind() {
	glBindVertexArray(ID);
}

void VAO::Unbind() {
	glBindVertexArray(0);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}













//GLuint VAO, VBO, EBO; //VBO - bufor wierzcholkow


	/*//VAO
	glGenVertexArrays(1, &VAO);

	//VBO
	glGenBuffers(1, &VBO);
	// Bind the VBO specifying it's a  GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	// Przeœlij dane wierzcholkow do urz¹dzenia wideo
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_DYNAMIC_DRAW);

	//VAO BIND
	glBindVertexArray(VAO);

	//EBO
	glGenBuffers(1, &EBO);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// Przeœlij dane indeksow wierzcholkow(indices) do urz¹dzenia wideo
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	*/

	//glGenVertexArrays(1, &VAO); pod aktywacja shaderow(w petli)

/*glDeleteVertexArrays(1, &VAO);
	glDeleteVertexArrays(1, &VBO);
	glDeleteVertexArrays(1, &EBO); to na samym koncu programu, po petli*/