#include "HumanPlayer.h"
#include "IO.h"

/*!
 *  \brief HumanPlayer's constructor
 *
 *  Construct an HumanPlayer of the given color.

 *  \param color : the player's color
 *  \return none
 */
HumanPlayer::HumanPlayer(cellContent color) : Player(color){
}

/*!
 *  \brief get the player's next move through keyboard entry
 *
 *  Loop until the next move can be read in the file.
 *
 *  \param game : a reference to the game that can be used to validate the player's move
 *  \return the player's next position
 */
Position HumanPlayer::getMove(Board gameBoard, int turn) {
	Position pos = IO::moveInput(gameBoard, playerColor);
	return pos;
}

