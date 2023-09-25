#include <iostream>
#include <windows.h>
#include <conio.h>
#include <math.h>

// eto shahki
// pupupu

class shahka {
protected:
	int type; // -1 black, 0 neutral, 1 white
	bool queen; // 0 neutal, 1 - queen
public:
	int gettype() {
		return type;
	}
	bool getqueen() {
		return queen;
	}

};
class Deck {
protected:
	shahka deck[8][8]; 
public:
	void printDeck();
	int hodshashi(int start, int end, class shahka& sh);
};

int Deck::hodshashi(int start, int end, class shahka& sh) {

	int xs = start / 8; // dec[x][y] для старта
	int ys = start % 8;
	int xe = end / 8; // dec[x][y] для хода
	int ye = end % 8;
	if (deck[xs][ys].getqueen() == 0) { // проверка, что не королева
		if (deck[xs][ys].gettype() == 0) { //проверка, что клетка не пустая
			return 0;
		}
		else if (deck[xs][ys].gettype() == 1) { //белая фишкa
			if ((xs - xe == 1) && (abs(ys - ye) == 1)) { // проверка хода в соседнюю клетку
				if (abs(deck[xe][ye].gettype() == 1)) { // если клетка занята. то хода нет
					return 0;
				}
				if (abs(deck[xe][ye].gettype() == 0)) { // верный ход
					return 1;
				}
			}
			else if ((xs - xe == 2) && (abs(ys-ye) == 2)) { //съедание
				if (deck[abs(xs-1)][(ys+ye)/2].gettype() == -1) { // получилось съесть
					return 2;
				}
				else {
					return 0;
				}

			}
		}
		else if ((deck[xs][ys].gettype() == -1)) { //черная фишка
			if ((xe - xs == 1) && (abs(ye - ys) == 1)) {//проверка хода в соседнюю
				if (abs(deck[xe][ye].gettype() == 1)) {
					return 0;
				}
				if (abs(deck[xe][ye].gettype() == 0)) { // верный ход
					return 1;
				}
			}
			else if ((xe - xs == 2) && (abs(ys - ye) == 2)) {
				if (deck[abs(xe - 1)][(ys + ye) / 2].gettype() == 1) {// съедание
					return 2;
				}
				else {
					return 0;
				}
			}

		}
	}

	else if (deck[xs][ys].getqueen() == 1) { // фишка - королева
		if (deck[xs][ys].gettype() == 0) { // клетка пустая
			return 0;
		}
		else if (deck[xs][ys].gettype() == 1) { //фишка белая
			if (xs == xe || ys == ye) { // вертикаль и горизонталь
				return 0;
			}
			else {
				if (abs(deck[xe][ye].gettype() == 1)) { // клетка занята
					return 0;
				}
				else if (abs(deck[xe][ye].gettype() == 0)){
					if (ys < ye) {
						int xss = xs - 1;
						int yss = ys + 1;
						int numW = 0; // количество белых на пути
						int numB = 0; // количество черных на пути
						while (xss != xe && yss != ye) {
							xss -= 1;
							yss += 1;
							if (deck[xss][yss].gettype() == 1) {
								numW++;
							}
							else if (deck[xss][yss].gettype() == -1) {
								numB++;
							}
						}
						if (numW == 0 && numB == 0) { //никого на пути
							return 1;
						}
						else if (numW != 0 || numB > 1) { // не может так походить
							return 0;
						}
						else if (numB == 1) { // поедание черной
							return 2;
						}
					}
					else if (ys > ye) {
						int XS = xs - 1;
						int YS = ys - 1;
						int nW = 0; // количество белых на пути
						int nB = 0; // количество черных на пути
						while (XS != xe && YS != ye) {
							XS -= 1;
							YS -= 1;
							if (deck[XS][YS].gettype() == 1) {
								nW++;
							}
							else if (deck[XS][YS].gettype() == -1) {
								nB++;
							}
						}
						if (nW== 0 && nB == 0) { //никого на пути
							return 1;
						}
						else if (nW != 0 || nB > 1) { // не может так походить
							return 0;
						}
						else if (nB == 1) { // поедание черной
							return 2;
						}
					}
				}
			}
		}

		else if (deck[xs][ys].gettype() == -1) {// черная королева
			if (xs == xe || ys == ye) { // вертикаль и горизонталь
				return 0;
			}
			else {
				if (abs(deck[xe][ye].gettype() == 1)) { // клетка занята
					return 0;
				}
				else {
					if (ys < ye) {
						int xS = xs + 1;
						int yS = ys + 1;
						int NW = 0;
						int NB = 0;
						while (xS != xe && yS != ye) {
							xS += 1;
							yS += 1;

							if (deck[xS][yS].gettype() == 1) {
								NW++;
							}
							else if (deck[xS][yS].gettype() == -1) {
								NB++;
							}
						}
						if (NW > 1 && NB != 0) {// нельзя
							return 0;
						}
						else if (NW == 0 && NB == 0) {//никого на пути
							return 1;
						}
						else if (NW == 1) {//кушать
							return 2;
						}
					}
					else if (ys > ye) {
						int XS = xs + 1;
						int YS = ys - 1;
						int nw = 0;
						int nb = 0;
						while (XS != xs && YS != ys) {
							XS += 1;
							YS -= 1;
							if (deck[XS][YS].gettype() == 1) {
								nw++;
							}
							else if (deck[XS][YS].gettype() == -1) {
								nb++;
							}
						}
						if (nw > 1 && nb != 0) {// нельзя
							return 0;
						}
						else if (nw == 0 && nb == 0) {//никого на пути
							return 1;
						}
						else if (nw == 1) {//кушать
							return 2;
						}
					}
				}
			}

		}
	}


}

void Deck::printDeck() {

}


void main() {
}