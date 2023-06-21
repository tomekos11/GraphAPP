#include "Graf.h"
#include <iostream>
#include<math.h>
using namespace std;

int determinant(int matrix[10][10], int n) {
	int det = 0;
	int submatrix[10][10];
	if (n == 2)
		return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					submatrix[subi][subj] = matrix[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * matrix[0][x] * determinant(submatrix, n - 1));
		}
	}
	return det;
}


Graf::Graf() :vertices{ 0 }, indices{ 0 }, stopienie_wierzcholkow{ 0 }, para_wierzcholkow{ 0 },
				ilosc_krawedzi(0), ilosc_wierzcholkow(0), ilosc_indices(0), max_ilosc_wierzcholkow(10)
{
	cout << "Utworzony zostal GRAF" << endl;
}

//GETERY
unsigned int Graf::IloscKrawedzi()
{
	return ilosc_krawedzi;
}

unsigned int Graf::IloscWierzcholkow()
{
	return ilosc_wierzcholkow;
}

unsigned int Graf::IloscIndices()
{
	return ilosc_indices;
}

 unsigned int Graf::MaxIloscWierzcholkow() const
{
	return max_ilosc_wierzcholkow;
}

unsigned int Graf::ParaWierzcholkow(unsigned int ix){
	return para_wierzcholkow[ix];
}

//KONIEC GETEROW

//SETER
void Graf::UstawLiczbeWierzcholkow(unsigned int lw) {
	if (lw < max_ilosc_wierzcholkow) ilosc_wierzcholkow = lw;
	else return;
}


void Graf::DodajKrawedz() {
	for (int i = 0; i < 2; i++)
	{
		indices[ilosc_indices] = para_wierzcholkow[i];
		ilosc_indices++;
	}
	//nizej zabezpieczenie ktore binduje ilosc indices na ilosc krawedzi *2 aby dobrze dzialalo rysowanie wszystkich krawedzi
	if (ilosc_indices != ilosc_krawedzi * 2) {
		ilosc_indices = ilosc_krawedzi * 2;
	}
}

void Graf::WprowadzLiczbeWierzcholkow() {
	cout << "Wprowadz liczbe wierzcholkow, w celu wygenerowania odpowiedniej mapy(ograniczenie do 10)" << endl;
	cout << "Dynamicznie bedzie ona rosla wraz z wprowadzniem krawedzi, aby jednak ja zwezyc uzyj komendy change" << endl;
	cin >> ilosc_wierzcholkow;
}

void Graf::OdswiezStopnieWierzcholkow() {
	//INICJALIZUJEMY STOPNIE LUB ZERUJEMY JESLI JUZ BYLY;
	for (int i = 0; i < 9; i++) {
		stopienie_wierzcholkow[i] = 0;
	}
	//DWIE PETLE PIERWSZA TO "DLA KAZDEGO Z WIERZCHOLKOW", DRUGA "JEZELI ID JEDNEGO Z WIERZCHOLKOW TWORZACYCH KRAWEDZ TO k TO PODNIES STOPIEN O JEDEN"
	for (int k = 0; k < ilosc_wierzcholkow; k++) {
		for (int i = 0; i < ilosc_krawedzi * 2; i++)
		{
			if (indices[i] == k)
			{
				stopienie_wierzcholkow[k]++;
			}
		}
	}
}

bool Graf::CzyWierzcholkiSasiednie(unsigned int w1, unsigned int w2) {

	//przechodzimy przez wszystkie indeksy krawedzi
	for (int i = 0; i < ilosc_indices*2; i=i+2)
	{
		//JEZELI JAKIES DWA INDEKSY IDEALNIE PASUJA
		if (((indices[i] == w1) && (indices[i + 1] == w2)) || ((indices[i] == w2) && (indices[i + 1] == w1))) {
			return true;
		}
		else continue;
	}
	return false;
}

void Graf::WprowadzKrawedzie() {
	char para_merged[100];
	int czy_nastapila_zmiana_krawedzi = ilosc_krawedzi;
	cin >> para_merged;
	//sprawdzamy czy para wprowadzonych wierzcholkow do polaczenia krawedzia na pewno ma 2 wierzcholki
	//oraz to czy ich zakres miesci sie w zakresie ascii 48-57 odpowiadajacy liczbom
	//na koncu to czy dwie liczby nie s¹ takie same
		if (strlen(para_merged) == 2 &&
			(int(para_merged[0]) >= 48 && int(para_merged[0]) <= 57) &&
			(int(para_merged[1]) >= 48 && int(para_merged[1]) <= 57) &&
			int(para_merged[0] != int(para_merged[1])))
		{
			para_wierzcholkow[0] = (atoi(para_merged) / 10);
			para_wierzcholkow[1] = (atoi(para_merged) % 10);
			ilosc_krawedzi++;
			//musimy sprawdzic czy w indices nie ma juz takich krawedzi jak podane lub ich inwersji(ich inwersja tez stanowi taka sama krawedz)
			for (int i = 0; i < ilosc_krawedzi * 2; i++) {
				if (((i % 2 == 0) && (indices[i] == para_wierzcholkow[0] && indices[i + 1] == para_wierzcholkow[1])) ||
					((i % 2 == 0) && (indices[i] == para_wierzcholkow[1] && indices[i + 1] == para_wierzcholkow[0])))
				{
					cout << "Taka para juz istnieje, nie udalo sie dodac krawedzi" << endl;
					ilosc_krawedzi--;
					break;
				}
			}
			if (czy_nastapila_zmiana_krawedzi != ilosc_krawedzi) {
				cout << "Pomyslnie utworzono krawedz na wierzcholkach [" << para_wierzcholkow[0] << " - " << para_wierzcholkow[1] << "]\n";
				cout << "Liczba krawedzi wynosi: " << ilosc_krawedzi << endl;
				cout << "--------\n";
			}
		}
		else if ((string)para_merged == "draw_all") {
			unsigned int max_ilosc_krawedzi = (ilosc_wierzcholkow * (ilosc_wierzcholkow - 1)) / 2;
			unsigned int maksymalny_indeks = ilosc_wierzcholkow - 1;
			unsigned int indeks_indicesow = 0;
			int j = 0;
			for (int i = 0; i < max_ilosc_krawedzi - 1; i++)
			{
				//for (j; j < maksymalny_indeks; j++)
				while (j < maksymalny_indeks)
				{
					indices[indeks_indicesow] = i;
					indices[indeks_indicesow + 1] = maksymalny_indeks - j + i;
					//cout << "sprawdzmy to: " << indices[indeks_indicesow] << endl;
					//cout << "sprawdzmy to: " << indices[indeks_indicesow + 1] << endl;
					indeks_indicesow = indeks_indicesow + 2;
					j++;
				}
				j = i + 1;
			}
			ilosc_krawedzi = max_ilosc_krawedzi;
			ilosc_indices = ilosc_krawedzi * 2;
		}
		else if ((string)para_merged == "clear_all") {
			for (int i = 0; i < ilosc_krawedzi * 2; i++) {
				indices[i] = 0;
			}
			ilosc_krawedzi = ilosc_indices = para_wierzcholkow[0] = para_wierzcholkow[1] = 0;
			cout << "--------\n";
			cout << "Wyczyszczono wszystkie laczenia" << endl;
			cout << "--------\n";
		}
		else if ((string)para_merged == "clear") {
			system("CLS");
		}
		//USTAWIANIE ILOSCI WIERZCHOLKOW
		else if ((string)para_merged == "change_vertices") {
			cout << "--------------" << endl;
			cout << "Wprowadz liczbe nowa liczbe wierzcholkow: " << endl;

			ilosc_krawedzi = ilosc_indices = para_wierzcholkow[0] = para_wierzcholkow[1] = 0;
			unsigned int new_v;
			cin >> new_v;
			ilosc_wierzcholkow = new_v;
		}
		else if ((string)para_merged == "vertex_degree") {
			//unsigned int stopien_wierzcholka = 0;
			unsigned int indeks_wierzcholka;

			cout << "--------------" << endl;
			cout << "Wprowadz indeks wierzcholka dla ktorego chcesz sprawdzic jego stopien" << endl;
			cin >> indeks_wierzcholka;

			this->OdswiezStopnieWierzcholkow();

			cout << "--------------" << endl;
			cout << "Stopien wierzcholka o indeksie: " << indeks_wierzcholka << " wynosi: " << stopienie_wierzcholkow[indeks_wierzcholka] << endl;
		}

		else if ((string)para_merged == "vertex_degree_A") {

			this->OdswiezStopnieWierzcholkow();

			cout << "--------------" << endl;
			for (int i = 0; i < ilosc_wierzcholkow; i++)
			{
				cout << "Stopien wierzcholka o indeksie: " << i << " wynosi: " << stopienie_wierzcholkow[i] << endl;
			}

		}
		else if ((string)para_merged == "vertices_adjacention")
		{
			unsigned int w1, w2;

			cout << "--------------" << endl;
			cout << "Wprowadz indeks wierzcholka nr1" << endl;
			cin >> w1;
			cout << "Wprowadz indeks wierzcholka nr2" << endl;
			cin >> w2;

			if (this->CzyWierzcholkiSasiednie(w1, w2)) {
				cout << "Wierzcholki o indeksach: " << w1 << " oraz " << w2 << " sa sasiednie" << endl;
			}
			else {
				cout << "Wierzcholki o indeksach: " << w1 << " oraz " << w2 << " NIE sa sasiednie" << endl;
			}

		}

		else if ((string)para_merged == "spanning_trees") {
			//ZNAJDUJEMY LICZBE DRZEW ROZPINAJACYH
			//ZACZNIEMY OD ODSWIEZENIA LICZBY WIERZCHOLKOW
			this->OdswiezStopnieWierzcholkow();
			//TWORZYMY MACIERZ [MACIERZ KIRHOFA
			int macierz_drzew[10][10];
			int macierz_kirhofa[10][10];
			//PODWOJNA PETLA UZUPENIAJACA WARTOSCI W MACIERZY
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					if (i == j) macierz_drzew[i][j] = stopienie_wierzcholkow[i];
					else {
						if (CzyWierzcholkiSasiednie(i, j)) macierz_drzew[i][j] = -1;
						else macierz_drzew[i][j] = 0;
					}

				}
			}

			//TUTAJ ZAPISUJE DO MIN I MAX INDEKSY WIERZCHOLKOW KTORE MAJA STOPIEN WIEKSZY NIZ 1
			int min, max;

			for (int i = 0; i < ilosc_wierzcholkow; i++)
			{
				if (stopienie_wierzcholkow[i] != 0)
				{
					min = i;
					break;
				}
			}

			for (int i = ilosc_wierzcholkow; i > 0; i--)
			{
				cout << i << endl;

				if (stopienie_wierzcholkow[i] != 0)
				{
					max = i;
					break;
				}
			}

			//TUTAJ WYPISUJEMY MACIERZ KIRHOFFA
			cout << "--------------" << endl;
			cout << "Macierz Kirhoffa:" << endl << endl;

			for (int i = min; i <= max; i++) {
				for (int j = min; j <= max; j++) {
					if(macierz_drzew[i][j]>=0) cout <<" "<< macierz_drzew[i][j] << " ";
					else cout << macierz_drzew[i][j] << " ";

				}
				cout << endl;
			}

			//USUWAMY JEJ JEDEN WIERSZ
			int rozpietosc = max - min;
			cout << "Teraz musimy usunac jeden dowolny wiersz i kolumne" << endl << endl;
			cout << "Macierz Kirhoffa po eliminacji:" << endl << endl;

			for (int i = 0; i <rozpietosc; i++) {
				for (int j = 0; j <rozpietosc; j++) {
					macierz_kirhofa[i][j] = macierz_drzew[i + 1][j + 1];
					if(macierz_kirhofa[i][j]>=0)cout << " " << macierz_kirhofa[i][j]<<" ";
					else cout << macierz_kirhofa[i][j] << " ";
				}
				cout << endl;
			}

			cout << "--------------" << endl;
			cout << "Liczba drzew rozpinajacych: " << determinant(macierz_kirhofa, rozpietosc) << endl;
			cout << "--------------" << endl;


		}

		else if ((string)para_merged == "cayleys_formula")
		{
			unsigned int lw = 1;
			for (int i = 0; i < 9; i++)
			{
				cout << "Dla grafu pelnego o ilosci wierzcholkow rownej: " << lw << " wynosi: " << pow(lw, lw - 2) << endl;
				lw++;
			}
		}

		else if ((string)para_merged == "info") {
			if (indices[0] == 0 && indices[1] == 0) cout << "Nie ma wprowadzonych zadnych krawedzi" << endl;
			else
			{
				cout << "-----LISTA WSZYSTKICH KRAWEDZI:" << endl;
				for (int i = 0; i < ilosc_krawedzi * 2; i = i + 2) {
					cout << "[" << indices[i] << " - " << indices[i + 1] << "]" << endl;
				}
			}
			cout << "LICZBA WIERZCHOLKOW : " << ilosc_wierzcholkow << endl;
			cout << "LICZBA KRAWEDZI : " << ilosc_krawedzi << endl;
			cout << "LICZBA INDICES : " << ilosc_indices << endl;
			cout << "PARA 1 : " << para_wierzcholkow[0] << endl;
			cout << "PARA  2 : " << para_wierzcholkow[1] << endl;
		}


		else if ((string)para_merged == "help") {
			cout << "-----LISTA WSZYSTKICH KOMEND:" << endl;
			cout << "[draw_all] - rysuje wszyskie krawedzie do aktualnej ilosci wierzcholkow na mapie" << endl;
			cout << "[clear_all] - czysci wszyskie krawedzie na mapie" << endl;
			cout << "[info] - wyswietla informacje o grafie [pary krawedzi, ilosc wierzcholkow, ilosc krawedzi etc.]" << endl;
			cout << "[clear] - czysci okienko" << endl;
			cout << "[change_vertices] - zmienia liczbe wierzcholkow na mapie, usuwa przy tym dotychaczas dodane krawedzie!" << endl;
			cout << "[vertex_degree] - Pokazuje stopien podanego wierzcholka" << endl;
			cout << "[vertex_degree_A] - Pokazuje stopnie wszystkich wierzcholkow" << endl;
			cout << "[vertices_adjacention] - Sprawdza czy wprowadzone wierzcholki sa sasiednie" << endl;
			cout << "[spanning_trees] - Wyswietla kroki obliczania liczby drzew rozpinajacych oraz ich ilosc" << endl;
			cout << "[cayleys_formula] - Wyswietla kolejne liczby drzew rozpinajacych dla grafu pelnego n^(n-2)" << endl;
			cout << "-----" << endl;
		}

		else
		{
			cout << "Nieprawidlowo wprowadziles pare :)" << endl;
		}

		//jezeli ta ktorys z pary wierzcholkow wprowadzanych do utworzenia krawedzi jest wiekszy od ilosci wierzcholkow to 
		if (para_wierzcholkow[0] >= ilosc_wierzcholkow || para_wierzcholkow[1] >= ilosc_wierzcholkow)
		{
			//ustaw ilosc_wierzcholkow na ten indeks +1, czyli maja 2 wierzcholki, jak tworzymy polaczenie 0-6 to musimy zmienic mape na 7w
			if (para_wierzcholkow[0] >= para_wierzcholkow[1]) ilosc_wierzcholkow = para_wierzcholkow[0] + 1;
			else ilosc_wierzcholkow = para_wierzcholkow[1] + 1;
		}
}








