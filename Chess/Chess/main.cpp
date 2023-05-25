#include <iostream>


class Figure {
	int f_type; // -1 (none) - 0 (white) - 1 (black)
};

class King : public Figure {};   // Король
class Queen : public Figure {};  // Ферзь
class Rook : public Figure {};   // Ладья
class Bishop : public Figure {}; // Слон
class Knight : public Figure {}; // Конь
class Pawns : public Figure {};  // Пешка

class Deck {
	Figure figure[8][8];
};

//Тут бы Я