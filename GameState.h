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

using namespace std;

class GameState{
private:
	int board[9];
	GameState **child = new GameState*[9];
	GameState(int index, int move, int arr[9]);
	int numChildren();
	bool findVertWin(int p);
	bool findHorizWin(int p);
	bool findDiagWin(int p);
public:
	GameState();
	~GameState();
	bool isEmpty(int index);
	void printGameState();
	bool isBoardFull();
	bool isSpaceEmpty(int i);
	int openSpaces();
	bool isOver();
	int giveScore();
	int findWinner();
	void copyBoard(int otherboard[9]);
	void setBoard(int v0, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8); //for testing remove later
	friend class GameTree;
	friend class Game;
};


#endif /* FILES_GAMESTATE_H_ */
