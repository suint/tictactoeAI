/*
 * TTTList.hpp
 *
 *  Created on: Nov 12, 2018
 *      Author: kelly
 */

#ifndef GameTree_HPP_
#define GameTree_HPP_

#include "GameState.hpp"

using namespace std;

class GameTree{
	private:
		GameState* root;

	public:
	GameTree(){
		root = new GameState();
	}
	~GameTree(){

	}

	//only printing children of root for now, get it to work later
	void printTree(int i){ //prints from root init with 0 lol
		cout << "level";
		cout << i << endl;


	}

	void insertState(int index, int value){
		root->insertState(index,value, root->board);
	}
	//if child of root, insert board with 100, 010, 001,.. 1 in every position

	void insertRecursiveChildren(GameState * root, int player){
		for (int i = 0; i < 9; i++){
			//ill work on this lol
		}
	}

	//doesn't totally work yet
	void insertChildren(){
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


};



#endif /* GAMELIST_HPP_ */
