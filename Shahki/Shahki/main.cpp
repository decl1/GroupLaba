#include <iostream>

// eto shahki
// pupupu

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

}

void Deck::printDeck() {

}


void main() {

}