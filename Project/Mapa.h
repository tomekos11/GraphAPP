#pragma once
#include <glad/glad.h>
#include "Graf.h"

class Mapa{

public:
	GLfloat* WzorMapy(Graf& g);
	void ZmienMape(Graf& g);
	Mapa();
	~Mapa();

};