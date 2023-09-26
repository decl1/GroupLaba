#pragma once
#include "Libs.h"

class shahka {
protected:
	int type; // -1 black, 0 neutral, 1 white
	bool queen; // 0 neutal, 1 - queen
public:
	shahka() : type(0), queen(0) {}
	shahka(int t) : type(t), queen(abs(0 * t)) {};
	shahka(const shahka& sh) : type(sh.type), queen(sh.queen) {}
	int gettype() {
		return type;
	};
	bool getqueen() {
		return queen;
	};
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
	int blacks;
	int whites;
public:
	Deck() : blacks(12), whites(12) {
		for (int i = 0; i < 8; i++) {
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
	void deckgivequeen(int x, int y) {
		deck[x][y].givequeen();
	}
	bool getqueenn(int x, int y) {
		return deck[x][y].getqueen();
  }
	int getblacks() {
		return blacks;
	}
	int getwhites() {
		return whites;
	}
	int hodshashi(int start, int end, bool player_queue);
};

int Deck::hodshashi(int start, int end, bool player_queue) {

	int xs = start / 8;
	int ys = start % 8;
	int xe = end / 8;
	int ye = end % 8;
	if (deck[xs][ys].getqueen() == 0) {
		if (deck[xs][ys].gettype() == 0) {
			return 0;
		}
		else if (deck[xs][ys].gettype() == 1 && player_queue == 0) {
			if ((xs - xe == 1) && (abs(ys - ye) == 1)) {
				if (abs(deck[xe][ye].gettype() == 1)) {
					return 0;
				}
				if (abs(deck[xe][ye].gettype() == 0)) {
					deck[xs][ys].changetype(0);
					deck[xe][ye].changetype(1);
					return 1;
				}
			}
			else if ((xs - xe == 2) && (abs(ys - ye) == 2)) {
				if (deck[abs(xs - 1)][(ys + ye) / 2].gettype() == -1) {
					deck[xs][ys].changetype(0);
					deck[abs(xs - 1)][(ys + ye) / 2].changetype(0);
					deck[xe][ye].changetype(1);
					return 2;
				}
				else {
					return 0;
				}

			}
			else {
				return 0;
			}
		}
		else if ((deck[xs][ys].gettype() == -1) && player_queue == 1) {
			if ((xe - xs == 1) && (abs(ye - ys) == 1)) {
				if (abs(deck[xe][ye].gettype() == 1)) {
					return 0;
				}
				if (abs(deck[xe][ye].gettype() == 0)) {
					deck[xs][ys].changetype(0);
					deck[xe][ye].changetype(-1);
					return 1;
				}
			}
			else if ((xe - xs == 2) && (abs(ys - ye) == 2)) {
				if (deck[abs(xe - 1)][(ys + ye) / 2].gettype() == 1) {
					deck[xs][ys].changetype(0);
					deck[abs(xe - 1)][(ys + ye) / 2].changetype(0);
					deck[xe][ye].changetype(-1);
					return 2;
				}
				else {
					return 0;
				}
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}

	else if (deck[xs][ys].getqueen() == 1) {
		if (deck[xs][ys].gettype() == 0) {
			return 0;
		}
		else if (deck[xs][ys].gettype() == 1 && player_queue == 0) {
			if (xs == xe || ys == ye) {
				return 0;
			}
			else {
				if (abs(deck[xe][ye].gettype()) == 1) {
					return 0;
				}
				else if (abs(deck[xe][ye].gettype()) == 0) {
					if (ys < ye) {
						int xss = xs - 1;
						int yss = ys + 1;
						int numW = 0;
						int numB = 0;
						std::vector<int> coords;
						while (xss != xe && yss != ye) {
							xss -= 1;
							yss += 1;
							if (deck[xss][yss].gettype() == 1) {
								numW++;
							}
							else if (deck[xss][yss].gettype() == -1) {
								numB++;
								coords.push_back(xss);
								coords.push_back(yss);
							}
						}
						if (numW == 0 && numB == 0) {
							deck[xs][ys].changetype(0);
							deck[xe][ye].changetype(1);
							return 1;
						}
						else if (numW != 0 || numB > 1) {
							return 0;
						}
						else if (numB == 1) {
							deck[xs][ys].changetype(0);
							deck[coords[0]][coords[1]].changetype(0);
							deck[xe][ye].changetype(1);
							return 2;
						}
						coords.clear();
					}
					else if (ys > ye) {
						int XSS = xs - 1;
						int YSS = ys - 1;
						int nW = 0;
						int nB = 0;
						std::vector<int> Coords;
						while (XSS != xe && YSS != ye) {
							XSS -= 1;
							YSS -= 1;
							if (deck[XSS][YSS].gettype() == 1) {
								nW++;
							}
							else if (deck[XSS][YSS].gettype() == -1) {
								nB++;
								Coords.push_back(XSS);
								Coords.push_back(XSS);
							}
						}
						if (nW == 0 && nB == 0) {
							deck[xs][ys].changetype(0);
							deck[xe][ye].changetype(1);
							return 1;
						}
						else if (nW != 0 || nB > 1) {
							return 0;
						}
						else if (nB == 1) {
							deck[xs][ys].changetype(0);
							deck[Coords[0]][Coords[1]].changetype(0);
							deck[xe][ye].changetype(1);
							return 2;
						}
						Coords.clear();
					}
				}
			}
		}

		else if (deck[xs][ys].gettype() == -1 && player_queue == 1) {
			if (xs == xe || ys == ye) {
				return 0;
			}
			else {
				if (abs(deck[xe][ye].gettype() == 1)) {
					return 0;
				}
				else {
					if (ys < ye) {
						int xS = xs + 1;
						int yS = ys + 1;
						int NW = 0;
						int NB = 0;
						std::vector<int> coordS;
						while (xS != xe && yS != ye) {
							xS += 1;
							yS += 1;

							if (deck[xS][yS].gettype() == 1) {
								coordS.push_back(xS);
								coordS.push_back(yS);
								NW++;
							}
							else if (deck[xS][yS].gettype() == -1) {
								NB++;
							}
						}
						if (NW > 1 && NB != 0) {
							return 0;
						}
						else if (NW == 0 && NB == 0) {
							deck[xs][ys].changetype(0);
							deck[xe][ye].changetype(-1);
							return 1;
						}
						else if (NW == 1) {
							deck[xs][ys].changetype(0);
							deck[coordS[0]][coordS[1]].changetype(0);
							deck[xe][ye].changetype(-1);
							return 2;
						}
						coordS.clear();
					}
					else if (ys > ye) {
						int XS = xs + 1;
						int YS = ys - 1;
						int nw = 0;
						int nb = 0;
						std::vector<int> cOords;
						while (XS != xs && YS != ys) {
							XS += 1;
							YS -= 1;
							if (deck[XS][YS].gettype() == 1) {
								nw++;
								cOords.push_back(XS);
								cOords.push_back(YS);
							}
							else if (deck[XS][YS].gettype() == -1) {
								nb++;
							}
						}
						if (nw > 1 && nb != 0) {
							return 0;
						}
						else if (nw == 0 && nb == 0) {
							deck[xs][ys].changetype(0);
							deck[xe][ye].changetype(-1);
							return 1;
						}
						else if (nw == 1) {
							deck[xs][ys].changetype(0);
							deck[cOords[0]][cOords[1]].changetype(0);
							deck[xe][ye].changetype(-1);
							return 2;
						}
						cOords.clear();
					}
					else {
						return 0;
					}
				}
			}
		}
		else {
			return 0;
		}
	}

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
						if (deck[x / 4][y / 4].gettype() == 1)
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
			return ((y - 1) * 8 + (x - 5)%10);
		if (x >= 97 && x <= 104)
			return ((y - 1) * 8 + (x - 7)%10);
	}
	else {
		return -1;
	}
}