#include <string>
#include <utility>      // std::pair, std::make_pair
#include <string>       // std::string
#include <iostream>     // std::cout

#include "Game.h"
#include "IO.h"
using namespace std;


int main(int argc, char **argv)
{
		
	Game *game = new Game();
	
	vector<Position> v = game->validMoves(White);
	cout << "Valid moves : ";
	for (int i = 0; i<v.size(); i++) {
		if (i != v.size()-1) {
			cout << v[i].toString() << " - ";
		} else {
			cout << v[i].toString() << endl;
		}
	}
	IO::moveInput();
	
	delete game;
	
	return 0;
}
