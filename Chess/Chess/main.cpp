#include <iostream>


class Figure {
	int f_type; // -1 (none) - 0 (white) - 1 (black)
};

class King : public Figure {};   // ������
class Queen : public Figure {};  // �����
class Rook : public Figure {};   // �����
class Bishop : public Figure {}; // ����
class Knight : public Figure {}; // ����
class Pawns : public Figure {};  // �����

class Deck {
	Figure figure[8][8];
};

//��� �� �