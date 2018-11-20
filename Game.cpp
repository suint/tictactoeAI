/*
 * Game.cpp
 *
 *  Created on: Nov 19, 2018
 *      Author: Anna
 */


#include "Game.h"

Game::Game(){
	tree = GameTree();
	tree.buildTree();
	pointer = tree.root;
	player = 1;
}
Game::~Game(){
}

void Game::startGame(){
	cout << "Please select one of the following spaces to make your move." << endl;
	cout << "|0|1|2|"<<endl << "|3|4|5|" <<endl <<"|6|7|8|"<<endl;
	makeMove();
}
void Game::makeMove(){
	int index;
	cout << "Player "<< player <<"'s turn:"<<endl;
	cin >> index;
	if(index >= 0 && index <= 8){
		if(!pointer->isSpaceEmpty(index) ){
			cout << "Space full" <<endl;
			makeMove();
		}else{ //make move, update pointer, update player, etc...
			cout<< "Chose space " << index << endl;
			pointer = pointer->child[index];
			if( pointer->isTerminalState() != -1){
				pointer->printGameState();
				cout << "Game won" <<endl;
			}else{
				pointer->printGameState();
				makeMove();
			}
		}
	}else{
		cout << "Invalid move" << endl;
		makeMove();
	}
}
