/*
 * GameState.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: kelly
 */

#include <string>
#include <iostream>
#include "GameState.h"

GameState::GameState(int v, int arr[9]){ //this is EXTREMELY awkward... using 9 variables does ensure that the board is the right size, but at what cost?
							 //so i moved this to private since the only case where you would make a gamestate that is not empty would be when you are generating the min/max tree
			for(int i = 0; i < 9; i++){
					board[i] = arr[i];
				}
			for (int i = 0; i < 9; i++){
				child[i] = nullptr;
			}
			value = v;
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
	return !(board[index]);
}

void GameState::addChild(int index, int player, GameState * stem){

}

//inserts a GameState at next null node with its board as otherboard with altered value at board[index]
void GameState::insertState(int index, int value, int otherboard[9]){
			for (int i = 0; i < 9; i++){
				if(child[i] == nullptr ){//&& otherboard[index] == 0){
					child[i] = new GameState();
					child[i]->copyBoard(otherboard); //probably sets child board to point to otherboard? , change one change the other
					if(otherboard[index] == 0){
						child[i]->board[index] = value;
					}return;
				}
			}
		}

void GameState::printGameState(){
	std::cout << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|" << std::endl;
	std::cout << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|" << std::endl;
	std::cout << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|" << std::endl;
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

bool GameState::isTerminalState(){ //i would recommend changing this to return which player won (0, 1, 2)
	if((board[0] != 0 && board[0]==board[1] && board[1] == board[2]) ||
	  (board[3] != 0 && board[3]==board[4] && board[4] == board[5])	||
	  (board[6] != 0 && board[6]==board[7] && board[7] == board[8]) ||
	  (board[0] != 0 && board[0]==board[4] && board[4] == board[8]) ||
	  (board[2] != 0 && board[2]==board[4] && board[4] == board[6]) ||
	   this->isBoardFull() ){
		return true;
	} return false;
}

bool GameState::horizontalEnd(){
	for(int i = 0; i < 2; i++){
		if (board[i] && board[1+i] && board[2+i]){
			return true;
		}
	}
	return false;
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

