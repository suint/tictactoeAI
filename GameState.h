/*
 * GameState.h
 *
 *  Created on: Nov 17, 2018
 *      Author: kelly
 */

#ifndef FILES_GAMESTATE_H_
#define FILES_GAMESTATE_H_

#include <string>
#include <iostream>
class GameState{
private:
	int board[9];
	int value;
	GameState **child = new GameState*[9];
	GameState(int index, int move, int arr[9]);
public:
	GameState();
	~GameState();
	bool isEmpty(int index);
	void addChild(int index, int player, GameState * stem);
	void printGameState();
	std::string getGameString();
	bool boardEqual(int otherboard[9]);
	bool isBoardFull();
	int openSpaces();
	int isTerminalState();
	void setBoard(int index, int value);
	void copyBoard(int otherboard[9]);
	void setBoard(int v0, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8); //for testing remove later

	friend class GameTree;
};


#endif /* FILES_GAMESTATE_H_ */
