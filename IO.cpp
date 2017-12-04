#include "IO.h"
#include <vector>

Position IO::moveInput(Board const & gameBoard, cellContent playerContent){
	Position pos;
	string move;
	while (true) {
		cout<<"Enter your move (column row)"<<endl;
		cin>>move;
		pos = Position::positionFromString(move);
		if (pos.isValid()) {
			if (gameBoard.isValidMove(playerContent,pos)) {
				return pos;
			} else {
				cout << "Not a valid move, try again" << endl;
			}
		} else {
			cout << "Not a correct syntax, try again" << endl;
		}
	}
}

void IO::display(Board & board, const Player &player, Position pos){
	cout << endl << endl;
	cout << "Le joueur " << player.toString() << " vient de jouer en : " << pos.toString() << endl;
	//cout << "mise à jour du board " << endl;
	cout << endl << endl;
	boardDisplay(board);
}

void IO::displayWhoPlays(const Player &player, Board const& gameBoard){
	cout << endl << endl << endl;
	cout << "Au joueur " << player.toString() << " de jouer" << endl;
	displayValidMoves(player,gameBoard);
}


void IO::displayFirstTurn(Board & board) {
	boardDisplay(board);
}

void IO::displayValidMoves(const Player &player, Board const& gameBoard) {
	std::vector<Position> v = gameBoard.validMoves(player.getColor());
	cout << "Valid moves : ";
	for (unsigned int i = 0; i<v.size(); i++) {
		if (i != v.size()-1) {
			cout << v[i].toString() << " - ";
		} else {
			cout << v[i].toString() << endl;
		}
	}
}

void IO::displayValidMoves(std::vector<Position> v) {
	if (v.size() == 0) {
		cout << "empty" << endl;
	} else {
		for (unsigned int i = 0; i<v.size(); i++) {
			if (i != v.size()-1) {
				cout << v[i].toString() << " - ";
			} else {
				cout << v[i].toString() << endl;
			}
		}
	}
}

void IO::boardDisplay(Board & board){
	cout<<"       a b c d e f g h  " << endl; //Impression des numéros de ligne
	for(unsigned int line =1; line <= 8; line++){
		cout<< "     "<<(line)<< " "; // Impression des numéros de colonne
		for(unsigned int col = 1; col <=8; col++){
			switch(board.getContentAt(Position(col,line))){
				case Empty: cout << ". "; break;
				case Black: cout << "B "; break;
				case White: cout << "W "; break;
			}
		}
		cout << (line) << endl;
	}
	cout<<"       a b c d e f g h  "<< endl;
}

void IO::displayScore(int blackScore, int whiteScore) {
	cout << "Black score : " << blackScore << " - " << "White score : " << whiteScore << endl;
	if (blackScore>whiteScore) {
		cout << "Victoire du joueur Noir" << endl;
	}
	if (whiteScore>blackScore) {
		cout << "Victoire du joueur Blanc" << endl;
	}
	if (blackScore==whiteScore) {
		cout << "Match nul" << endl;
	}
}




