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
		int board [9];
		int value;
		GameState **child = new GameState*[9]; //array of gamestate pointers, view gamestate as a node

		GameState(int v, int arr[9]){ //this is EXTREMELY awkward... using 9 variables does ensure that the board is the right size, but at what cost?
									 //so i moved this to private since the only case where you would make a gamestate that is not empty would be when you are generating the min/max tree
					for(int i = 0; i < 9; i++){
							board[i] = arr[i];
						}
					for (int i = 0; i < 9; i++){
				        child[i] = nullptr;
					}
					value = v;
		}

	public:
		GameState(){
			for (int i = 0; i < 9; i++){
				board[i] = 0;
		        child[i] = nullptr;
			}
			value = 0;
		}

		~GameState(){
			//delete nodes in children recursively
		}

		bool isEmpty(int index){
			return !(board[index]);
		}

		void addChild(int index, int player, GameState * stem){

		}

		//inserts a GameState at next null node with its board as otherboard with altered value at board[index]
		void insertState(int index, int value, int otherboard[9]){
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

		void printGameState(){
			cout << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|" << endl;
			cout << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|" << endl;
			cout << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|" << endl <<endl;
		}

		string getGameString(){
			string gm = "";
			for (int i = 0; i++; i<3){
				gm = gm + "|";
				for (int j = 0; j++; j<3){
					gm = gm + board[(i*3)+j];
				}
				gm = gm + "\n";
			}
		}

		//maybe for comparing moves / boards? idkkk //why?
		bool boardEqual(int otherboard[9]){
			bool flag = true;
			int i = 0;
			while(i < 9 && flag == true){
				if(board[i] != otherboard[i]){
					flag = false;
				}
			}
			return flag;
		}

		bool isBoardFull(){
			for(int i = 0; i < 9; i++){
				if(board[i] == 0){
					return false;
				}
			} return true;
		}

		int openSpaces(){
			int r = 0;
			for(int i = 0; i < 9; i++){
				if(board[i] == 0){
					r++;
				}
			} return r;
		}

		bool isTerminalState(){ //i would recommend changing this to return which player won (0, 1, 2)
			if((board[0] != 0 && board[0]==board[1] && board[1] == board[2]) ||
			  (board[3] != 0 && board[3]==board[4] && board[4] == board[5])	||
			  (board[6] != 0 && board[6]==board[7] && board[7] == board[8]) ||
			  (board[0] != 0 && board[0]==board[4] && board[4] == board[8]) ||
			  (board[2] != 0 && board[2]==board[4] && board[4] == board[6]) ||
			   this->isBoardFull() ){
				return true;
			} return false;
		}

		bool horizontalEnd(){
			for(int i = 0; i < 2; i++){
				if(board[i] && board[1+i] && board[2+i]) return true;
			}
		}

		void setBoard(int index, int value){
			board[index] = value;
		}
		void copyBoard(int otherboard[9]){
			for(int i = 0; i < 9; i++){
				board[i] = otherboard[i];
			}
		}

		//for testing
		void setBoard(int v0, int v1, int v2, int v3, int v4, int v5, int v6, int v7, int v8){
					board[0] = v0; board[1] = v1; board[2] = v2;
					board[3] = v3; board[4] = v4; board[5] = v5;
					board[6] = v6; board[7] = v7; board[8] = v8;
			}

		friend class GameTree;
};


#endif /* GAMESTATE_HPP_ */
