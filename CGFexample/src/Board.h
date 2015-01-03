#ifndef _BOARD_H
#define _BOARD_H

#include "CGFscene.h"
#include "CGFobject.h"
#include "math.h"
#include <vector>
#include <map>
#include "Animation.h"

#define PI acos(-1.0);

//hexagons that compose the board
class BoardObject: public CGFobject {
	public:
		void draw();
};

//pieces to play with
class BoardPiece: public CGFobject {
	public:
		void draw();
		void setPosition(int x, int y);
		void setAppearance(CGFappearance* pA);
		void setAnimation(LinearAnimation *a);
		void updateAnimation(unsigned long t);
		std::vector<int> getPosition();
private:
	int line, column;
	CGFappearance* pieceAppearance;
	LinearAnimation* animation;
};

//board made of hexagons
class Board{
	public:
		Board(CGFobject *bo,CGFappearance* bA);
		void drawBoard(int x, int y);
		void drawBoardComplete(int line, int x, int y, int limit);
		void draw();
private:
	std::map<int,int> hexgs;
	CGFobject* bObject;
	CGFappearance* boardAppearance;
};





#endif