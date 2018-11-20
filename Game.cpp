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

//between 2 players, need check if player2 then make ai move, -1 restarts game
void Game::makeMove(){
	int index;
	cout << "Player "<< player <<"'s turn:"<<endl;
	cin >> index;
	if(index >= 0 && index <= 8){
		if(!pointer->isSpaceEmpty(index) ){
			cout << "Space full" <<endl;
			pointer->printGameState();
			makeMove();
		}else{ //make move, update pointer, update player, etc...
			cout<< "Chose space " << index << endl;
			pointer = pointer->child[index];
			cout << "sgsdfgdfG"<< endl;
			changePlayer();
			if (pointer->isOver()){
				cout <<"end found" <<endl;
				pointer->printGameState();
				int a = pointer->findWinner();
				if (a == 0){
					cout << "tie" << endl;
				} else if (a == 1){
					cout << "p1 wins" << endl;
				} else {
					cout << "p2 wins" << endl;
				}
			} else {
				cout << "no end found"<< endl;
				pointer->printGameState();
				makeMove();
			}
		}
	}else if(index == -1){
		restartGame();	//for testing
	}else{
		cout << "Invalid move" << endl;
		makeMove();
	}
}

void Game::changePlayer(){
	if(player == 1){
		player = 2;
	}else
		player = 1;
}

void Game::restartGame(){
	pointer = tree.root;
	player = 1;
	startGame();
}

void Game::aiMove(){
	//go through children of current pointer
	//find index of one w/ largest min-max value
	//set pointer to that child
}

