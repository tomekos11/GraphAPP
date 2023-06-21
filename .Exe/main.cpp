#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <thread>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shaders.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Graf.h"
#include "Mapa.h"

//POLA STATYCZNE
Mapa mapa;
Graf G1;

using namespace std;


int okienko() {
	//INICJALIZACJA - LADUJEMY GLFW od razu z komunikatem czy sie udalo
	if (glfwInit()) {
		cout << "Pomyslnie zainicjalizowano GLFW" << endl;
	}
	else {
		cout << "Nastapil jakis blad" << endl;
	}
	//GLFW NIE WIE JAKA MAMY WERSJE WIEC MUSIMY MU DAC WSKAZOWKI - HINTS, w tym przpadku uzywamy wersji 3 wiec jako argument dajemy 3ke
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//INFORMUJEMY GLFW ZE BEDZIEMY KORZYSTAC Z PROFILU CORE, KTORY ZAWIERA NOWOCZESNIEJSZE FUNKCJE
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//TWORZENIE OKIENKA
	GLFWwindow* window = glfwCreateWindow(600, 600, "Matematyka Dyskretna", NULL, NULL);

	//CO MA SIE WYDARZYC JESLI COS POJDZIE NIE TAK
	if (window == NULL) {
		cout << "Cos nie pyklo" << endl;
		glfwTerminate();
		return -1;
	}
	//WPROWADZAMY OKIENKO DO AKTUALNEGO KONTEKSTU
	glfwMakeContextCurrent(window);

	//LADUJEMY GLADA
	gladLoadGL();
	//USTALAMY JAK OPENGL MA RENDEROWAC - OD LEWEGO DOLNEGO ROGU(0,0) DO PRAWEGO GORNEGO(800,600)
	glViewport(0, 0, 600, 600);

	Shader shaderProgram("default.vert", "default.frag");

	VAO VAO1;

	VBO VBO1(G1.vertices);


	VAO1.Bind();
	EBO EBO1(G1.indices);

	VAO1.LinkVBO(VBO1, 0);
	glfwSwapBuffers(window);
	int czy_nastapila_zmiana_wierzcholkow = G1.IloscWierzcholkow();
	int czy_nastapila_zmiana_krawedzi = G1.IloscKrawedzi();
	VBO1.Bind();
	
	//PETLA DZIEKI KTOREJ OKIENKO WIE ZE MA SIE NIE ZAMYKAC AZ DO MOMENTU GUZIKA X
	while (!glfwWindowShouldClose(window))
	{
		//USTALAMY KOLOR TLA NA TAKI JAK PONIZEJ (OSTATNI PARAMETR TO PRZEZROCZYSTOSC)
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		//CZYSCIMY TYLNI BUFFER I PRZYDZIELAMY MU NOWY KOLOR
		glClear(GL_COLOR_BUFFER_BIT);

		shaderProgram.Activate();

		//JEZELI UZYTKOWNIK ZMIENI PODANA LICZBE WIERZCHOLKOW ZMIEN MAPE ---------------------ZMIANA MAPY
		if (czy_nastapila_zmiana_wierzcholkow != G1.IloscWierzcholkow()) {
			cout << "------------------------------------" << endl;
			cout << "Nastapila zmiana ilosci wierzcholkow na mapie.\nAktualnie mapa zawiera: " << G1.IloscWierzcholkow() <<" wierzcholkow"<<endl;
			cout << "------------------------------------" << endl;
			//ZmienMape(ilosc_wierzcholkow); //ZMIENIAMY MAPE
			mapa.ZmienMape(G1); //ZMIENIAMY MAPE

			
			//REFRESHUJEMY BUFER WIERZCHOLKOW I GO DYNAMICZNIE RYSUJEMY
			glBufferData(GL_ARRAY_BUFFER, sizeof(G1.vertices), G1.vertices, GL_DYNAMIC_DRAW);


			//VBO1.Odswiez_Mape(vertices);
			czy_nastapila_zmiana_wierzcholkow = G1.IloscWierzcholkow();
		}

		//Sprawdzamy czy liczba krawedzi sie zmienila, poprzez wprowadzenie w drugim watku
		if (czy_nastapila_zmiana_krawedzi != G1.IloscKrawedzi())
		{
			G1.DodajKrawedz();
			//REFRESHUJEMY BUFER INDEKSOW I GO DYNAMICZNIE RYSUJEMY
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(G1.indices), G1.indices, GL_DYNAMIC_DRAW);
			//EBO1.Odswiez_Mape(indices);
			czy_nastapila_zmiana_krawedzi = G1.IloscKrawedzi();
		}

		VBO1.Rysuj_wierzcholki(G1.IloscWierzcholkow()); //(nie wazne jakie VBO sie uzyje)

		EBO1.Rysuj_krawedzie(G1.IloscIndices());
		//TUTAJ ZAMIENIAMY BUFORY PRZEDNI Z TYLNIM, TYM SAMYM RENDERUJ�C OBRAZ
		glfwSwapBuffers(window);
		//TUTAJ MOWIMY ZE W NASZEJ PETLI MOGA WYSTAPYWAC ZDARZENIA, NP RESIZING OKNA,	MINIMALIZACJA ITP
		glfwPollEvents();
	}
	mapa.~Mapa();
	//NISZCZENIE RYSUNKOWYCH SMIECI
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	//NISZCZENIE OKIENKA
	glfwDestroyWindow(window);
	//konczymy uzywac glfw
	glfwTerminate();
};

void wypisz() {
	Sleep(200);
	G1.WprowadzLiczbeWierzcholkow();

	while (G1.ParaWierzcholkow(0) >= 0 && G1.ParaWierzcholkow(1) >= 0)
	{
		Sleep(100);
		cout << "Podaj pare wierzcholkow na ktorych ma byc zbudowana krawedz" << endl;
		//jezeli wierzcholka do ktorego ma siegac krawedz nie ma w zbiorze wierzcholkow to zwieksz liczbe wierzcholkow o 1
		//WprowadzKrawedzie();
		G1.WprowadzKrawedzie();
		//sprawdzamy czy jakikolwiek id wierzcholka jest wiekszy lub rowny jego liczbie i w zaleznosci od tego modyfikujemy liczbe wierzcholkow i tym samym generujemy inna mape
	}
}

int main() {
	thread th1(okienko);
	thread th2(wypisz);
	th1.join();
	th2.join();

	return 0;
}