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
	void givequeen(int i) {
		queen = i;
	}
};
class Deck {
protected:
	shahka deck[8][8];
	int blacks;
	int whites;
public:

	/// debug

	Deck(int k) : blacks(1), whites(1) {
		deck[1][1].changetype(k);
		deck[6][6].changetype(-1);
	};

	/// debug

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
	void checkqueen(int xe, int ye, bool queue) {
		if (queue == 0 && xe == 0) {
			deck[xe][ye].givequeen(1);
		}
		if (queue == 1 && xe == 7) {
			deck[xe][ye].givequeen(1);
		}
	}
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
					deck[xe][ye].changetype(1);
					deck[xe][ye].givequeen(deck[xs][ys].getqueen());
					deck[xs][ys].changetype(0);
					return 1;
				}
			}
			else if ((xs - xe == 2) && (abs(ys - ye) == 2)) {
				if (deck[abs(xs - 1)][(ys + ye) / 2].gettype() == -1) {
					deck[xe][ye].changetype(1);
					deck[xe][ye].givequeen(deck[xs][ys].getqueen());
					deck[abs(xs - 1)][(ys + ye) / 2].changetype(0);
					deck[xs][ys].changetype(0);
					blacks--;
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
					deck[xe][ye].changetype(-1);
					deck[xe][ye].givequeen(deck[xs][ys].getqueen());
					deck[xs][ys].changetype(0);
					return 1;
				}
			}
			else if ((xe - xs == 2) && (abs(ys - ye) == 2)) {
				if (deck[abs(xe - 1)][(ys + ye) / 2].gettype() == 1) {
					deck[xe][ye].changetype(-1);
					deck[xe][ye].givequeen(deck[xs][ys].getqueen());
					deck[abs(xe - 1)][(ys + ye) / 2].changetype(0);
					deck[xs][ys].changetype(0);
					whites--;
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
					if (ys < ye && xs > xe) {
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
							deck[xe][ye].changetype(1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW != 0 || numB > 1) {
							return 0;
						}
						else if (numB == 1) {
							deck[xe][ye].changetype(1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							blacks--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
					}
					else if (ys < ye && xs < xe) {
						int xss = xs + 1;
						int yss = ys + 1;
						int numW = 0;
						int numB = 0;
						std::vector<int> coords;
						while (xss != xe && yss != ye) {
							xss += 1;
							yss += 1;

							if (deck[xss][yss].gettype() == 1) {
								coords.push_back(xss);
								coords.push_back(yss);
								numW++;
							}
							else if (deck[xss][yss].gettype() == -1) {
								numB++;
							}
						}
						if (numW == 0 && numB == 0) {
							deck[xe][ye].changetype(1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW != 0 || numB > 1) {
							return 0;
						}
						else if (numB == 1) {
							deck[xe][ye].changetype(1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							blacks--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
					}
					else if (ys > ye && xs < xe) {
						int xss = xs + 1;
						int yss = ys - 1;
						int numW = 0;
						int numB = 0;
						std::vector<int> coords;
						while (xss != xs && yss != ys) {
							xss += 1;
							yss -= 1;
							if (deck[xss][yss].gettype() == 1) {
								numW++;
								coords.push_back(xss);
								coords.push_back(yss);
							}
							else if (deck[xss][yss].gettype() == -1) {
								numB++;
							}
						}
						if (numW > 1 && numB != 0) {
							return 0;
						}
						else if (numW == 0 && numB == 0) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW == 1) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							whites--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
					}
					else if (ys > ye && xs > xe) {
						int xss = xs - 1;
						int yss = ys - 1;
						int numW = 0;
						int numB = 0;
						std::vector<int> coords;
						while (xss != xe && yss != ye) {
							xss -= 1;
							yss -= 1;
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
							deck[xe][ye].changetype(1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW != 0 || numB > 1) {
							return 0;
						}
						else if (numB == 1) {
							deck[xe][ye].changetype(1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							blacks--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
					}
					else {
						return 0;
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
					if (ys < ye && xs < xe) {
						int xss = xs + 1;
						int yss = ys + 1;
						int numW = 0;
						int numB = 0;
						std::vector<int> coords;
						while (xss != xe && yss != ye) {
							xss += 1;
							yss += 1;

							if (deck[xss][yss].gettype() == 1) {
								coords.push_back(xss);
								coords.push_back(yss);
								numW++;
							}
							else if (deck[xss][yss].gettype() == -1) {
								numB++;
							}
						}
						if (numW > 1 && numB != 0) {
							return 0;
						}
						else if (numW == 0 && numB == 0) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW == 1) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							whites--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
					}
					else if (ys < ye && xs > xe) {
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
						if (numW > 1 && numB != 0) {
							return 0;
						}
						else if (numW == 0 && numB == 0) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW == 1) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							whites--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
					}
					else if (ys > ye && xs > xe) {
						int xss = xs - 1;
						int yss = ys - 1;
						int numW = 0;
						int numB = 0;
						std::vector<int> coords;
						while (xss != xe && yss != ye) {
							xss -= 1;
							yss -= 1;
							if (deck[xss][yss].gettype() == 1) {
								numW++;
							}
							else if (deck[xss][yss].gettype() == -1) {
								numB++;
								coords.push_back(xss);
								coords.push_back(yss);
							}
						}
						if (numW > 1 && numB != 0) {
							return 0;
						}
						else if (numW == 0 && numB == 0) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW == 1) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							whites--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
					}
					else if (ys > ye  && xs < xe) {
						int xss = xs + 1;
						int yss = ys - 1;
						int numW = 0;
						int numB = 0;
						std::vector<int> coords;
						while (xss != xs && yss != ys) {
							xss += 1;
							yss -= 1;
							if (deck[xss][yss].gettype() == 1) {
								numW++;
								coords.push_back(xss);
								coords.push_back(yss);
							}
							else if (deck[xss][yss].gettype() == -1) {
								numB++;
							}
						}
						if (numW > 1 && numB != 0) {
							return 0;
						}
						else if (numW == 0 && numB == 0) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[xs][ys].changetype(0);
							return 1;
						}
						else if (numW == 1) {
							deck[xe][ye].changetype(-1);
							deck[xe][ye].givequeen(deck[xs][ys].getqueen());
							deck[coords[0]][coords[1]].changetype(0);
							deck[xs][ys].changetype(0);
							whites--;
							return 2;
						}
						coords.clear();
						coords.shrink_to_fit();
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
						if (deck[x / 4][y / 4].gettype() == 1 && deck[x / 4][y / 4].getqueen() == 0)
							std::cout << " W";
						if (deck[x / 4][y / 4].gettype() == -1 && deck[x / 4][y / 4].getqueen() == 0)
							std::cout << " B";
						if (deck[x / 4][y / 4].gettype() == 0)
							std::cout << "  ";
						if (deck[x / 4][y / 4].gettype() == 1 && deck[x / 4][y / 4].getqueen() == 1)
							std::cout << "+W";
						if (deck[x / 4][y / 4].gettype() == -1 && deck[x / 4][y / 4].getqueen() == 1)
							std::cout << "+B";
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