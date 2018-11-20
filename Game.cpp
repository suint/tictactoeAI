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
	cout << index << endl;
}
