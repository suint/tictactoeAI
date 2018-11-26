/*
 * GameTree.h
 *
 *  Created on: Nov 17, 2018
 *      Author: kelly
 */

#ifndef FILES_GAMETREE_H_
#define FILES_GAMETREE_H_
#include "GameState.h"

class GameTree{
	private:
		GameState* root;
		void getLevelString(string pf, GameState * rt);
	public:
		GameTree();
		~GameTree();
		void printTree(GameState * current);
		void printTree();
		void insertState(int index, int value);
		void insertRecursiveChildren(GameState * current, int player);
		int nextPlayer(int p);
		void insertChildren();
		void buildTree();
		friend class Game;
};



#endif /* FILES_GAMETREE_H_ */
