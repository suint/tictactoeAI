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
#include "Game.h"

int main(int argc, char** argv){

	GameState state = GameState();
	state.printGameState();
	state.setBoard(1,0,2,1,2,0,1,0,2);
	state.printGameState();
	cout << state.isBoardFull() << endl;
	cout << state.isTerminalState() << endl;
	cout << "-----------------------------" <<endl;

	GameTree tree = GameTree();
	//tree.buildTree();
	//tree.printTree();

	Game game = Game();
	game.startGame();



	return 0;
}
