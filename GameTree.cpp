/*
 * GameTree.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: kelly
 */


#include "GameTree.h"

void GameTree::getLevelString(string pf, GameState * rt){
			string temp = pf;
			for (int i = 0; i<9; i++){
				if (rt->board[i]){

				} else {

				}
			}
		}

GameTree::GameTree(){
	root = new GameState();
}
GameTree::~GameTree(){

}

//prints tree recursively now, work on formatting print later
void GameTree::printTree(GameState * current){
	cout << "level" << endl;
	for(int i  = 0; i < 9; i++){
		if(current->child[i] != nullptr){
			current->child[i]->printGameState();
			printTree(current->child[i]);
		}
	}
}

void GameTree::printTree(){
	printTree(root);
}


//if child of root, insert board with 100, 010, 001,.. 1 in every position

void GameTree::insertRecursiveChildren(GameState * current, int player){
	for (int i = 0; i < 9; i++){
		if (current->board[i] == 0 && current->isTerminalState() == -1){
			current->child[i] = new GameState(i, player, current->board);
			insertRecursiveChildren(current->child[i], nextPlayer(player));
		}
		//write function to find if a space in the board is empty
		//if yes, insert child for the space
		//recursively run this function on that child
		//if no, end
	}
}

void GameTree::buildTree(){
	this->insertRecursiveChildren(root, 1);
}

int GameTree::nextPlayer(int p){
	return (p == 1) ? 2 : 1; //return 2 if p1 else return 1
}


