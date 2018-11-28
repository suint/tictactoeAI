/*
 * Game.cpp
 *
 *  Created on: Nov 19, 2018
 *      Author: Anna
 */


#include "Game.h"
#include <regex>
#include <string>

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

//prompts player for input
void Game::makeMove(){
	int index;
	if (pointer->isOver()){ //when end detected
		cout <<"END GAME" <<endl;
		pointer->printGameState();
		int a = pointer->findWinner();
		if (a == 0){
			cout << "Tie" << endl;
		} else if (a == 1){
			cout << "Player 1 wins!!" << endl;
		} else {
			cout << "Player 2 wins!!" << endl;
		}
		cout << "Press 9 to play again or any key to exit:" <<endl;
		cin >> index;
		if(index == 9){
			restartGame();
		}
	} else if(player == 1){ //for player one
		cout << "Player "<< player <<"'s turn:"<<endl;
		cin >> index;
		if(index < 0 || index > 8) { //if not valid
			pointer->printGameState();
			cout << "Invalid move" <<endl;
			makeMove();
		}else if(!pointer->isSpaceEmpty(index) ){
			cout << "Space full" <<endl;
			pointer->printGameState();
			makeMove();
		}else{
			pointer = pointer->child[index];
			pointer->printGameState();
			changePlayer();
			makeMove();
		}
	} else if(player == 2){
		cout << "Player "<< player <<"'s turn:"<<endl;
		aiMove();
		pointer->printGameState();
		changePlayer();
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
	int movehere;
	int minScore = 100000;
	for(int i = 0; i < 9; i++){ //minimizes score to win
		if(pointer->child[i] && (pointer->child[i]->giveScore() < minScore) ){ //finds child with lowest score
			cout << minScore<<endl;
			minScore = pointer->child[i]->giveScore();
			movehere = i;
		}
	}
	pointer = pointer->child[movehere];
}
