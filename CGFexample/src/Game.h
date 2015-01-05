#ifndef _GAME_H
#define _GAME_H

#include "Board.h"
#include "Socket.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <string>
#include <sstream>

#define PLAYER1 0
#define PLAYER2 1
#define COMP1	2
#define COMP2	3

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
	void setDiff(int diff);
	void setType(int type);
	int currentplayer;
	void computerPlay();
	//std::string getSocketBoard();

private:
	Board* board;
	//char socketBoard[795];
	int playIndex;
	std::vector<std::string> oldPlays;
	std::map<std::string,BoardPiece*> pieces;
	std::string selectedPiece;
	vector<BoardPiece*> piecesOutOfPlay;

	map<string,BoardPiece*> pieceKilledPiece;
	map<string,string> piecesKilled;
	vector<string> lastPiecesKilled;

	std::vector<std::string> positions;
	CGFappearance* pieceAppearance1;
	CGFappearance* pieceAppearance2;
	Socket* socket;

	int range;
	int difficulty;
	int type;
	std::string possiblemoves;
	vector<int> outOfPlayPos;
};



#endif