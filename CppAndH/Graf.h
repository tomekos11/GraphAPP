#pragma once
#include <glad/glad.h>

class Graf {
private:
	unsigned int stopienie_wierzcholkow[10];
	unsigned int para_wierzcholkow[2];
	unsigned int ilosc_krawedzi;
	unsigned int ilosc_wierzcholkow;
	unsigned int ilosc_indices;
	const unsigned int max_ilosc_wierzcholkow = 10;
public:
	GLuint indices[720];
	GLfloat vertices[30];
	//Graf(unsigned int liczba_wierzcholkow);
	//void DodajKrawedz(unsigned int* para_wierzcholkow);
	Graf();
	void DodajKrawedz();
	void WprowadzLiczbeWierzcholkow();
	void WprowadzKrawedzie();
	//GETERY
	unsigned int IloscKrawedzi();
	unsigned int IloscWierzcholkow();
	unsigned int IloscIndices();
	unsigned int MaxIloscWierzcholkow() const;
	unsigned int ParaWierzcholkow(unsigned int ix);
	void UstawLiczbeWierzcholkow(unsigned int lw);
	void OdswiezStopnieWierzcholkow();
	bool CzyWierzcholkiSasiednie(unsigned int w1, unsigned int w2);
};