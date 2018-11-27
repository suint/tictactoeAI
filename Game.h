/*
 * Game.h
 *
 *  Created on: Nov 19, 2018
 *      Author: Anna
 */

#ifndef TICTACTOEAI_GAME_H_
#define TICTACTOEAI_GAME_H_

#include "GameTree.h"

class Game{
private:
	GameTree tree;
	GameState* pointer;
	int player;
public:
	Game();
	~Game();
	void startGame();
	void makeMove();
	void changePlayer();
	void restartGame();
	void aiMove();

};


#endif /* TICTACTOEAI_GAME_H_ */
