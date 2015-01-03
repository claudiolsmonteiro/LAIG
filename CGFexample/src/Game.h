#ifndef _GAME_H
#define _GAME_H

#include "socket.h"
#include "Board.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <sstream>

#define PLAYER1 0
#define PLAYER2 1
class Game{
public:
	Game(CGFobject *bo,CGFappearance* bA, CGFappearance* pA1, CGFappearance* pA2);
	void fillBoard();
	void drawBoard();
	void drawPieces();
	void undo();
	void movePiece(std::string p1, std::string p2);
	void selectPiece(int x, int y);
	void updateAnims(unsigned long t);
	//std::string getSocketBoard();

private:
	Board* board;
	//char socketBoard[795];
	int playIndex;
	std::vector<std::string> oldPlays;
	std::map<std::string,BoardPiece*> pieces;
	std::string selectedPiece;
	//std::map<std::string,BoardPiece*> piecesOutOfPlay;
	std::vector<std::string> positions;
	CGFappearance* pieceAppearance1;
	CGFappearance* pieceAppearance2; 
	Socket *socket;
	int currentplayer;
};



#endif