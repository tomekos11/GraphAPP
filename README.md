<h1>1. OPIS PROJEKTU</h1>
    <b>Graph APP</b> - dwuwątkowa aplikacja CLI + wyświetlacz, stworzona na potrzeby szkolnego projektu z języka C++. Wyświetla ona w czasie rzeczywistym, jak wygląda graf zbudowany na podanych przez nas krawędziach. W aplikacji możemy sprawdzać stopnie każdego z wierzchołków, ilość możliwych do stworzenia drzew rozpinających, a także inne istotne informacje o tworzonym przez nas grafie - ilość krawędzi, wierzchołków itd.
    Aplikacja obrazuje tak naprawdę początek mojej przygody z programowaniem obiektowym oraz podziałem na wątki. Sam zamysł aplikacji pojawił się z dwóch powodów:<br>

    - Grafy to struktury za pomocą których jesteśmy w stanie opisać większość zjawisk - po prostu je lubie
    - postanowiłem, że taka aplikacja, przy odpowiednim jej rozwoju, może mieć duże walory edukacyjne, szczególnie dla przyszłych studentów

<br>
<h1 id="drugi_dzial">2. OPIS FUNKCJONALNOŚCI</h1>

1. Aplikacja wita nas komunikatami o poprawnym zainicjalizowaniu się obiektów, a następnie prosi o wprowadzenie orientacyjnej liczby wierzchołków(orientacyjnej, ponieważ w razie potrzeby będzie się ona powiększała).<br>
2. Odpowiadamy jej na to liczbą całkowitą z przedziału <0-10>.
3. Kolejnym etapem jest prośba aplikacji o podanie pary wierzchołków, na której zbudowana ma być krawędź.
4. W tym momencie mamy kilka możliwości. Najbardziej naturalną jest podanie dwóch cyfr w formacie "xy", gdzie obie są indeksami wierzchołków.<br>
><b>Wierzechołki są numerowane od 0 do 9.</b><br><br>
<b>Przykład 1:</b><br>
Podaliśmy programowi na wejściu cyfry <b>03</b><br>
Program potwierdza wprowadzenie do systemu krawędzi, wypisuje aktualną liczbę wszystkich krawędzi, a w międzyczasie rysuje ją w oknie graficznym.
<br><br>
<b>Przykład 2:</b><br>
Podaliśmy programowi na wejściu cyfry <b>031</b> (lub jakąkolwiek niedozwoloną kombinację znaków)<br>
Program informuje nas o błędzie i wracamy do momentu wprowadzania krawędzi.

<br>
5. Alternatywą do wprowadzania krawędzi jest używanie dostępnych w programie komend opisanych w <a href="#trzeci_dzial">trzecim dziale</a>.

><b>Przykład 3:</b><br>
Podaliśmy programowi na wejściu komendę <b>help</b><br>
Program reaguje na nią, wypisując na ekranie wszystkie dostępne komendy.

<br>
<h1 id="trzeci_dzial">3. ZDEFINIOWANE KOMENDY</h1>

1. <b>[draw_all]</b> - Rysuje wszyskie możliwe krawedzie dla każdego z aktualnie dostępnych wierzcholkow na mapie(tworzy graf pełny)
2. <b>[clear_all]</b> - Czyści wszyskie krawedzie na mapie
3. <b>[info]</b> - Wyświetla informacje o grafie [pary krawedzi, ilosc wierzcholkow, ilosc krawedzi etc.]
4. <b>[clear]</b> - Czyści konsolę
5. <b>[change_vertices]</b> - Zmienia liczbę wierzchołków na mapie, usuwa przy tym dotychaczas dodane krawedzie!
6. <b>[vertex_degree]</b> - Pokazuje stopień podanego wierzcholka
7. <b>[vertex_degree_A]</b> - Pokazuje stopnie wszystkich wierzchołków
8. <b>[vertices_adjacention]</b> - Sprawdza czy wprowadzone wierzchołki sa sąsiednie
9. <b>[spanning_trees]</b> - Wyświetla ilość drzew rozpinających oraz kolejne kroki obliczania tej liczby
10. <b>[cayleys_formula]</b> - Wyswietla kolejne liczby drzew rozpinajacych dla grafu pelnego n^(n-2)

<h1>4. Jak testować: </h1>
Pobieramy folder ".Exe" i otwieramy plik GraphAPP.exe - aplikacja powinna się uruchomić. Następnie wykonujemy kroki z <a href="#drugi_dzial">drugiego działu</a>


  
<br><br><br>