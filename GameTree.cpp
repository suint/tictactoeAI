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
	deleteNodes(root);
}

void GameTree::deleteNodes(GameState * root){ //recursively delete nodes in tree
	if (!(root->isOver())){
		for (int i = 0; i < 9; i++){
			if (root->child[i]){
				deleteNodes(root->child[i]);
			}
		}
	} else {
		delete root;
	}
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


//inserts children nodes until hits end game state
void GameTree::insertRecursiveChildren(GameState * current, int player){
	for (int i = 0; i < 9; i++){
		if (current->isSpaceEmpty(i) && !(current->isOver())){
			current->child[i] = new GameState(i, player, current->board);
			insertRecursiveChildren(current->child[i], nextPlayer(player));
		}
	}
}

void GameTree::buildTree(){
	this->insertRecursiveChildren(root, 1);
}

int GameTree::nextPlayer(int p){
	return (p == 1) ? 2 : 1; //return 2 if p1 else return 1
}


