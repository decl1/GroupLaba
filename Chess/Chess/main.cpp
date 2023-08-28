#include <iostream>
#include <Windows.h>


class Deck {
public:
	char DeckArr[64] =  {}; // uziika
public:
	void PrintDeck() {
		// uziika
	}
	bool Hod(int place_from, int place_to, bool player2) { // player 2 маленькими буквами
		// dimasik возвращать 0 - если ход невозможен
	}
	bool TryWin(bool* player2winflag) {
		// dimasik // функция возвращает 1 если кто то на доске победил флаг 2 поднимается если победил игрок 2
	}
};

void inputplaces(int* place_from, int* place_to) {
	// maksim
}

int main() {
	Deck GameDeck;
	int place_from = -1;
	int place_to = -1;
	bool player2hod = true;
	bool player2winflag = false;

	while(1) {
		player2hod *= -1;
		inputplaces(&place_from, &place_to);
		GameDeck.Hod(place_from, place_to, player2hod);
		if (GameDeck.TryWin(&player2winflag) == 1) {
			break;
		}
	}
}