/*
 * GameState.hpp
 *
 *  Created on: Nov 1, 2018
 *      Author: Anna Wu & Kelly Mi
 */
#ifndef GAMESTATE_HPP_
#define GAMESTATE_HPP_

#include <iostream>
using namespace std;


//0 empty square, 1 players moves, 2 computers moves
//said smth about creating tree of all poss moves in constructor, create an insert function to insert at next null node, insert / create board recursively
//GameState is the tree of possibilities, Game class will point to a tree node / a Gamestate
//recursively make the board, if 9 open spaces > 9 children with 1 player

class GameState{
	private:
		int* board;
		int boardsize = 9;
		int value;
		GameState **children = new GameState*[9]; //array of gamestate pointers, view gamestate as a node

	public:
		GameState(){
			board = new int[boardsize];
			for (int i = 0; i < boardsize; i++){
				board[i] = 0;
			}
			value = 0;
		}

		~GameState(){
			delete[] board;
		}

		void PrintGameState(){
			cout << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|" << endl;
			cout << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|" << endl;
			cout << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|" << endl <<endl;
		}

		//maybe for comparing moves / boards? idkkk
		bool BoardEqual(int* otherboard){
			bool flag = true;
			int i = 0;
			while(i < boardsize && flag == true){
				if(board[i] != otherboard[i]){
					flag = false;
				}
			}
			return flag;
		}

		bool isBoardFull(){
			for(int i = 0; i < boardsize; i++){
				if(board[i] == 0){
					return false;
				}
			} return true;
		}

		int openSpaces(){
			int r = 0;
			for(int i = 0; i < boardsize; i++){
				if(board[i] == 0){
					r++;
				}
			} return r;
		}

		bool isTerminalState(){
			if((board[0] != 0 && board[0]==board[1] && board[1] == board[2]) ||
			  (board[3] != 0 && board[3]==board[4] && board[4] == board[5])	||
			  (board[6] != 0 && board[6]==board[7] && board[7] == board[8]) ||
			  (board[0] != 0 && board[0]==board[4] && board[4] == board[8]) ||
			  (board[2] != 0 && board[2]==board[4] && board[4] == board[6]) ||
			   this->isBoardFull() ){
				return true;
			} return false;
		}

		void SetBoard(int index, int value){
			board[index] = value;
		}

		//for testing
		void SetBoard(int v0, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8){
					board[0] = v0; board[1] = v1; board[2] = v2;
					board[3] = v3; board[4] = v4; board[5] = v5;
					board[6] = v6; board[7] = v7; board[8] = v8;
			}



};



#endif /* GAMESTATE_HPP_ */