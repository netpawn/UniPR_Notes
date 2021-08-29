/*
Scrivo un programma che legge le "parole" contenute in due
file di testo e stampa in ordine alfabetico quelle che
occorrono in entrambe
*/
#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <fstream>

using Strings = std::vector<std::string>;

// Funzione per eliminare la punteggiatura e i caratteri
// speciali all'inizio e alla fine della stringa.
std::string normalizza(const std::string& s) {

    auto res = s;

    // Uso un espressione lambda per vedere se ci sono caratteri da eliminare
    auto left = std::find_if(res.begin(), res.end(),
                             [](char c) {
                             return !std::ispunct(c);});

    auto right = std::find_if(res.begin(), res.end(),
                             [](char c) {
                             return std::ispunct(c);});

    res.erase(res.begin(), left);
    res.erase(right, res.end());

    return res;
}

Strings leggi(const std::string& nomefile) {

	Strings res;

	std::ifstream fs(nomefile);
	std::istream_iterator<std::string> i(fs), i_end;

	std::transform(i, i_end, std::back_inserter(res), normalizza);

	// Ordino e elimino i duplicati
	std::sort(res.begin(), res.end());
	auto last = std::unique(res.begin(), res.end());
	res.erase(last, res.end());

	return res;
}

int main() {

	Strings cs1 = leggi("alg_iter.cpp");
	//Strings cs2 = leggi("file2");

	std::ostream_iterator<std::string> out(std::cout, "\n");
	std::copy(cs1.begin(), cs1.end(), out);

	return 0;
}
