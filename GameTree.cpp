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

//maybe works now??, work on formatting print later
void GameTree::printTree(GameState * current){
	cout << "level" << endl;
	current->printGameState();
	for(int i  = 0; i < 9; i++){
		if(current->child[i] != nullptr){
			printTree(current->child[i]);
		}
	}
}

void GameTree::printTree(){
	printTree(root);
}


//inserts children nodes until hits end game state, sets leaf min-max values
void GameTree::insertRecursiveChildren(GameState * current, int player){
	for (int i = 0; i < 9; i++){
		if (current->isSpaceEmpty(i) && !(current->isOver())){
			current->child[i] = new GameState(i, player, current->board);
			//current->child[i]->value = current->child[i]->findWinner();	//sets leaf nodes to min-max value
			insertRecursiveChildren(current->child[i], nextPlayer(player));
		}
	}
}


//only setting second to last row's scores, my recursion or smth's off
//probably need depth-first traversal instead??
/*void GameTree::giveScore(GameState * current){
	for (int i = 0; i < 9; i++){
		if(current->child[i] != nullptr && current->child[i]->value != 0){
			current->value += current->child[i]->value;
		}else if(current->child[i] != nullptr){
			giveScore(current->child[i]);
		}
}
}
*/
void GameTree::buildTree(){
	this->insertRecursiveChildren(root, 1);
}

int GameTree::nextPlayer(int p){
	return (p == 1) ? 2 : 1; //return 2 if p1 else return 1
}


