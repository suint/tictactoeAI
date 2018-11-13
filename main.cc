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

#include "GameState.hpp"

int main(int argc, char** argv){
	cout << "test" << endl;
	cout << "test2 nyeeeh" << endl;

	GameState Game = GameState();
	Game.PrintGameState();
	Game.SetBoard(1,0,2,1,1,2,1,2,1);
	Game.PrintGameState();
	cout << Game.isBoardFull() << endl;
	cout << Game.isTerminalState() << endl;


	return 0;
}
