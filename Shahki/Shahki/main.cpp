#include "ClassesAndFunc.h"

void main() {
	//debug zone

	//debug zone

	Deck gdeck;
	bool player_queue = 0; // 0 - white, 1 - black;
	char xs;
	int ys;
	char xe;
	int ye;
	int move;
	while (gdeck.getblacks() != 0 || gdeck.getwhites() != 0) {
		gdeck.printDeck();
		std::cout << "Queue: " << ((player_queue == 0) ? "W " : "B ") 
			<< "______ W - " << (12 - gdeck.getblacks()) <<":"<< (12 - gdeck.getwhites()) << " - B " << std::endl;
		std::cout << "Enter checker to move: ";
		std::cin >> xs >> ys;
		std::cout << "Enter move: ";
		std::cin >> xe >> ye;
		move = gdeck.hodshashi(deckcoordcounter(xs, ys), deckcoordcounter(xe, ye), player_queue);
		if (move == 0)
			std::cout << "Incorrect move";
		if (move == 1) {
			std::cout << "Correct move";
			player_queue = !(player_queue);
		}
		if (move == 2) {
			std::cout << "Correct move";
		}
		std::cout << std::endl;
		system("pause");
		system("cls");
	}
}