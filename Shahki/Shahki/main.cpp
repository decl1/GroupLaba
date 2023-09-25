#include <iostream>

class shahka {
protected:
	int type; // -1 black, 0 neutral, 1 white
	bool queen; // 0 neutal, 1 - queen
public:
	shahka() : type(0), queen(0) {}
	shahka(int t) : type(t), queen(abs(0 * t)) {};
	shahka(const shahka& sh): type(sh.type), queen(sh.queen) {}
	int gettype() {
		return type;
	};
	bool getqueen() {};
	void changetype(int t) {
		type = t;
		queen = abs(queen * t);
	}
	void givequeen() {
		queen = 1;
	}
};
class Deck {
protected:
	shahka deck[8][8]; 
public:
	Deck() {
		for (int i = 0; i<8;i++){
			for (int j = 0; j < 8; j++) {
				if (i < 3) {
				if (i % 2 == 0 && j % 2 != 0)
					deck[i][j].changetype(-1);
				else if (i % 2 != 0 && j % 2 == 0)
					deck[i][j].changetype(-1);
				}
				if (i > 4) {
					if (i % 2 == 0 && j % 2 != 0)
						deck[i][j].changetype(1);
					else if (i % 2 != 0 && j % 2 == 0)
						deck[i][j].changetype(1);
				}
			}
		}
	}
	void printDeck();
	int hodshashi(int start, int end, const class shahka& sh);
};

int Deck::hodshashi(int start, int end, const class shahka& sh) {
	return 0;
}

void Deck::printDeck() {
	for (int x = 0; x < 31; x++) {
		if ((x + 1) % 4 == 0) {
			for (int y = 0; y < 27; y++) {
					std::cout << " #";
			}
		}
		else {
			for (int y = 0; y < 31; y++) {
				if ((y + 1) % 4 == 0) {
					std::cout << "#";
				}
				else {
					if ((y + 1) % 2 == 0 && (x + 1) % 2 == 0) {
						if(deck[x / 4][y / 4].gettype() == 1)
							std::cout << " W";
						if (deck[x / 4][y / 4].gettype() == -1)
							std::cout << " B";
						if (deck[x / 4][y / 4].gettype() == 0)
							std::cout << "  ";
					}
					else {
						std::cout << "  ";
					}
				}
			}
		}
		std::cout << std::endl;
	}
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
	Deck deck;
	deck.printDeck();
	//debug zone
}