#include <glad/glad.h>

class EBO
{
public:
	GLuint ID;
	EBO(GLuint* indices);

	void Bind();
	void Unbind();
	void Delete();
	void Odswiez_Mape(GLuint* indices);
	void Rysuj_krawedzie(int ilosc_indices);
};


