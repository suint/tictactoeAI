/*
 * main.cc
 *
 *  Created on: Oct 31, 2018
 *      Author: kelly & anna
 */

//USEFUL LINKS (probably)
// https://www.ocf.berkeley.edu/~yosenl/extras/alphabeta/alphabeta.html

#include <iostream>
using namespace std;
#include "GameState.h"
#include "GameTree.h"

int main(int argc, char** argv){

	GameState Game = GameState();
	Game.printGameState();
	Game.setBoard(2,0,2,1,2,0,1,0,2);
	Game.printGameState();
	cout << Game.isBoardFull() << endl;
	cout << Game.isTerminalState() << endl;
	cout << "-----------------------------" <<endl;

	GameTree tree = GameTree();
	tree.insertChildren();
	tree.printTree(0);



	return 0;
}
