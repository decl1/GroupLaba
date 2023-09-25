#include <iostream>

class shahka {
protected:
	int type; // -1 black, 0 neutral, 1 white
	bool queen; // 0 neutal, 1 - queen
public:
	int gettype() {};
	bool getqueen() {};
};
class Deck {
protected:
	shahka deck[8][8]; 
public:
	void printDeck();
	int hodshashi(int start, int end, const class shahka& sh);
};

int Deck::hodshashi(int start, int end, const class shahka& sh) {
	return 0;
}

void Deck::printDeck() {

}

int deckcoordcounter(char x, int y) {
	if (y >= 1 && y <= 8) {
		if (x >= 65 && x <= 72)
			return ((x - 4) % 10 * y) - 1;
		if (x >= 97 && x <= 104)
			return ((x - 6) % 10 * y) - 1;
	}
	else {
		return -1;
	}
}

void main() {
	//debug zone

	//debug zone
}