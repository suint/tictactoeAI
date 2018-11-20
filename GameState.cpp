/*
 * GameState.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: kelly
 */

#include "GameState.h"

GameState::GameState(int index, int move, int arr[9]){
		for(int i = 0; i < 9; i++){
			board[i] = arr[i];
			child[i] = nullptr;
		}
		board[index] = move;
		value = 0;
}

GameState::GameState(){
	for (int i = 0; i < 9; i++){
		board[i] = 0;
		child[i] = nullptr;
	}
	value = 0;
}

GameState::~GameState(){
	//delete nodes in children recursively
}

bool GameState::isEmpty(int index){
	return (board[index] == 0);
}

bool GameState::isSpaceEmpty(int i){
	return (board[i] == 0);
}

void GameState::addChild(int index, int player, GameState * stem){

}

void GameState::printGameState(){
	cout << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|" << endl;
	cout << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|" << endl;
	cout << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|" << endl << endl;
}

std::string GameState::getGameString(){
	std::string gm = "";
	for (int i = 0; i<3; i++){
		gm = gm + "|";
		for (int j = 0; j<3; j++){
			gm = gm + std::to_string(board[(i*3)+j]);
		}
		gm = gm + "\n";
	}
	return gm;
}

//maybe for comparing moves / boards? idkkk //why?
bool GameState::boardEqual(int otherboard[9]){
	bool flag = true;
	int i = 0;
	while(i < 9 && flag == true){
		if(board[i] != otherboard[i]){
			flag = false;
		}
	}
	return flag;
}

bool GameState::isBoardFull(){
	for(int i = 0; i < 9; i++){
		if(board[i] == 0){
			return false;
		}
	} return true;
}

int GameState::openSpaces(){
	int r = 0;
	for(int i = 0; i < 9; i++){
		if(board[i] == 0){
			r++;
		}
	} return r;
}

//returns player # if player wins, 0 if tie, -1 if no winner
int GameState::isTerminalState(){
	for(int i = 0; i < 3; i++){
		if( (board[i*3] != 0 && board[i*3] == board[1+i*3] && board[1+i*3] == board[2+i*3]) ||
			(board[i] != 0 && board[i] == board[3+i] && board[3+i] == board[6+i]) ){
				return board[i];
		}
	}
	if((board[4] != 0 && board[0] == board[4] && board[4] == board[8])||
	   (board[4] != 0 && board[2] == board[4] && board[4] == board[6])){
			return board[4];
	}else if (isBoardFull()){
		return 0;
	}else
		return -1;
}

bool GameState::isOver(){
	return (this->numChildren() == 0 || this->whoWon() != 0); // find if leaf node or win found
}

//0 if no win found, -1 if player 2 won, 1 if player 1 won
int GameState::findWinner(){
	if (this->findDiagWin(2) == -1 || this->findHorizWin(2) == -1 || this->findVertWin(2) == -1){ //find if p2 won
		return -1;
	} else if (this->findDiagWin(1) == 1 || this->findHorizWin(1) == 1 || this->findVertWin(1) == 1){ //find if p1
		return 1;
	} else {
		return 0; //tie
	}
}

bool GameState::findDiagWin(int p){
	return ((board[0] == p && board[4] == p && board[8] == p) || (board[2] == p && board[4] == p && board[6] == p));
}

bool GameState::findHorizWin(int p){
	bool win = false;
	for (int i = 0; i++; i<3){
		win = true;
		for (int j = 0; j++; j<3){
			if (board[i+j] != p){
				win = false;
			}
		}
		if (win){
			return win;
		}
	}
	return false;
}

bool GameState::findVertWin(int p){
	return 230492;
}

void GameState::setBoard(int index, int value){
	board[index] = value;
}
void GameState::copyBoard(int otherboard[9]){
	for(int i = 0; i < 9; i++){
		board[i] = otherboard[i];
	}
}

//for testing
void GameState::setBoard(int v0, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8){
			board[0] = v0; board[1] = v1; board[2] = v2;
			board[3] = v3; board[4] = v4; board[5] = v5;
			board[6] = v6; board[7] = v7; board[8] = v8;
	}

int GameState::numChildren(){
	int i = 0;
	for (int i = 0; i<9; i++){
		(board[i])? i++ : i = i+0;
	}
	return i;
}
