/*
 * GameTree.cpp
 *
 *  Created on: Nov 17, 2018
 *      Author: kelly
 */


#include "GameTree.h"

void GameTree::getLevelString(string pf, GameState * rt){
			string temp = pf;
			for (int i = 0; i++; i<9){
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

//only printing children of root for now, get it to work later
void GameTree::printTree(int i){ //prints from root init with 0 lol
	cout << "level";
	cout << i << endl;


}

void GameTree::insertState(int index, int value){
	root->insertState(index,value, root->board);
}
//if child of root, insert board with 100, 010, 001,.. 1 in every position

void GameTree::insertRecursiveChildren(GameState * root, int player){
	for (int i = 0; i < 9; i++){
		if (root->isEmpty(i)){
			root->insertState(i,player,root->board);
			insertRecursiveChildren(root->child[i], nextPlayer(player));
		}
		//write function to find if a space in the board is empty
		//if yes, insert child for the space
		//recursively run this function on that child
		//if no, end
	}
}

int GameTree::nextPlayer(int p){
	return (p == 1) ? 2 : 1; //return 2 if p1 else return 1
}

//doesn't totally work yet
void GameTree::insertChildren(){
	for(int i = 0; i < 9; i++){
		root->insertState(i, 1, root->board);
	}
	for(int i = 0; i<9; i++){
		for(int j = 0; j < 9; j++){
				if(root->child[i]){
					root->child[i]->insertState(j,2,root->child[i]->board);
				}
		}
	}
}