#include "ClassesAndFunc.h"

int main() {
	//console
	system("title Shahochki");
	system("mode con cols=60 lines=40");
	//console

	Deck gdeck(1); // debug - gdeck(1)
	bool player_queue = 0; // 0 - white, 1 - black;
	char xs;
	int ys;
	char xe;
	int ye;
	int move;
	while (gdeck.getblacks() != 0 && gdeck.getwhites() != 0) {
		gdeck.printDeck();
		std::cout << "Queue: " << ((player_queue == 0) ? "W " : "B ") 
			<< "______ W - " << (12 - gdeck.getblacks()) <<":"<< (12 - gdeck.getwhites()) << " - B " << std::endl;
		std::cout << "Enter checker to move: ";
		std::cin >> xs >> ys;
		std::cout << "Enter move: ";
		std::cin >> xe >> ye;
		move = gdeck.hodshashi(deckcoordcounter(xs, ys), deckcoordcounter(xe, ye), player_queue);
		if (move == 0) {
			std::cout << "Incorrect move";
			system("pause");
		}
		if (move == 1) {
			std::cout << "Correct move";
			system("pause");
			gdeck.checkqueen(ye-1,deckcoordcounter(xe,1), player_queue);
			player_queue = !(player_queue);
		}
		if (move == 2) {
			gdeck.checkqueen(ye - 1, deckcoordcounter(xe, 1), player_queue);
			std::cout << "Correct move";
		}
		std::cout << std::endl;
		system("cls");

		if (gdeck.getblacks() == 0) {
			gdeck.printDeck();
			std::cout << " WHITE WINS!!! " << "W - " << (12 - gdeck.getblacks()) << ":" << (12 - gdeck.getwhites()) << " - B " << std::endl;;
			system("pause");
		}
		else if (gdeck.getwhites() == 0) {
			gdeck.printDeck();
			std::cout << " BLACK WINS!!! " << "W - " << (12 - gdeck.getblacks()) << ":" << (12 - gdeck.getwhites()) << " - B " << std::endl;;
			system("pause");
		}
	}
}