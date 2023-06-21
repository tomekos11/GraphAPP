#include "Mapa.h"
#include <iostream>
float z = 0;

Mapa::Mapa() {
	std::cout << "Utworzono mape" << std::endl;
}

Mapa::~Mapa() {
	std::cout << "Zamknieto okienko" << std::endl;
}

GLfloat* Mapa::WzorMapy(Graf& g) {
	if (g.IloscWierzcholkow() <= 1 || g.IloscWierzcholkow() > g.MaxIloscWierzcholkow()) {

		GLfloat wierzcholki[] = { -0.5f,0.5f, z };
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 2) {

		GLfloat wierzcholki[] = { -0.5f, 0.5f, z ,
								  0.5f, 0.5f, z };
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 3) {

		GLfloat wierzcholki[] = { -0.5f, 0.5f, z ,
								0.5f, 0.5f, z,
								-0.5f, -0.5f, z };
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 4) {

		GLfloat wierzcholki[] = { -0.7f, 0.7f, z ,//lewy gorny
								0.7f, 0.7f, z,//prawy gorny
								0.7f,-0.7f, z,//prawy dolny
								-0.7f, -0.7f, z };//lewy dolny
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 5) {

		GLfloat wierzcholki[] = { 0.0f, 0.85f, z ,
								0.7f, 0.6f, z,
								0.7f,-0.6f,z,
								-0.7f, -0.6f, z,
								-0.7f, 0.6f, z };
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 6) {

		GLfloat wierzcholki[] = { 0.0f, 0.85f, z ,
								0.7f, 0.6f, z,
								0.7f,-0.6f,z,
								0.0f, -0.85f, z,
								-0.7f, -0.6f, z,
								-0.7f, 0.6f, z };
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 7) {

		GLfloat wierzcholki[] = { 0.0f, 0.85f, z ,
								0.4f, 0.9f, z,
								0.7f, 0.6f, z,
								0.7f,-0.6f,z,
								0.0f, -0.85f, z,
								-0.7f, -0.6f, z,
								-0.7f, 0.6f, z };
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 8) {

		GLfloat wierzcholki[] = { 0.0f, 0.85f, z ,
								0.4f, 0.9f, z,
								0.7f, 0.6f, z,
								0.7f,-0.6f,z,
								0.0f, -0.85f, z,
								-0.4f, -0.9f, z
								- 0.7f, -0.6f, z,
								-0.7f, 0.6f, z };
		return wierzcholki;
	}

	else if (g.IloscWierzcholkow() == 9) {

		GLfloat wierzcholki[] = { 0.0f, 0.85f, z ,
								0.4f, 0.9f, z,
								0.7f, 0.6f, z,
								0.7f,-0.6f,z,
								0.4f, -0.9f, z,
								0.0f, -0.85f, z,
								-0.4f, -0.9f, z
								- 0.7f, -0.8f, z,
								-0.7f, 0.6f, z };
		return wierzcholki;
	}
	else if (g.IloscWierzcholkow() == 10) {

		GLfloat wierzcholki[] = { 0.0f, 0.85f, z ,
								0.4f, 0.9f, z,
								0.7f, 0.6f, z,
								0.7f,-0.6f,z,
								0.4f, -0.9f, z,
								0.0f, -0.85f, z,
								-0.4f, -0.9f, z,
								-0.7f, -0.8f, z,
								-0.7f, 0.6f, z,
								-0.4f, 0.9f, z };
		return wierzcholki;
	}
}

void Mapa::ZmienMape(Graf& g) {
	//zmienna pomocnicza, unikajaca wielokrotnego uzywania funkcji w petli
	GLfloat* pozycja_wierzcholkow = WzorMapy(g);
	//petla nadpisujaca wierzcholki w tabeli wierzcholkow
	for (int p = 0; p < 30; p++) {
		g.vertices[p] = *(pozycja_wierzcholkow + p);
	}
}