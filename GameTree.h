/*
 * GameTree.h
 *
 *  Created on: Nov 17, 2018
 *      Author: kelly
 */

#ifndef FILES_GAMETREE_H_
#define FILES_GAMETREE_H_
#include "GameState.h"

using namespace std;

class GameTree{
	private:
		GameState* root;
		void getLevelString(string pf, GameState * rt);
	public:
		GameTree();
		~GameTree();
		void printTree(int i);
		void insertState(int index, int value);
		void insertRecursiveChildren(GameState * root, int player);
		int nextPlayer(int p);
		void insertChildren();

};



#endif /* FILES_GAMETREE_H_ */
