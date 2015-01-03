#include "Board.h"

void BoardObject::draw(){
	float ang = PI;
	float inc = ang/3;
	float a;
	double x,y;
	double op,adj;
	std::vector<double> pointsx;
	std::vector<double> pointsy;
	std::vector<double> texcoordsx;
	std::vector<double> texcoordsy;
	for(int i = 0; i < 6; i++){
		a = i * inc;
		x = cos(a);
		y = sin(a);
		pointsx.push_back(x);
		pointsy.push_back(y);
	}
	op = 0.5 * sin(inc/2);
	adj = 0.5 * cos(inc/2);
	//p1
	texcoordsx.push_back(1);
	texcoordsy.push_back(0.5);
	//p2
	texcoordsx.push_back(op+0.5);
	texcoordsy.push_back(adj+0.5);
	//p3
	texcoordsx.push_back(0.5-op);
	texcoordsy.push_back(adj+0.5);
	//p4
	texcoordsx.push_back(0);
	texcoordsy.push_back(0.5);
	//p5
	texcoordsx.push_back(0.5-op);
	texcoordsy.push_back(0.5-adj);
	//p6
	x += 0.5;
	texcoordsx.push_back(0.5+op);
	texcoordsy.push_back(0.5-adj);
	glBegin(GL_POLYGON);
	for(int i = 0,j=0; i < 6; i++,j++){
		if (j == 6)
			j=0;
		glTexCoord2d(texcoordsx[j],texcoordsy[j]);
		glVertex3d(pointsx[i],pointsy[i],0);
	}
	glEnd();
}
void BoardPiece::setPosition(int x, int y){
	line = x;
	column = y;
}

void BoardPiece::setAppearance(CGFappearance* pA){
	pieceAppearance = pA;
}

void BoardPiece::setAnimation(LinearAnimation* a){
	animation = a;
}

void BoardPiece::draw(){
	glPushMatrix();
	glLoadName(line);
	glPushName(column);
	glTranslatef(0, animation->getPosY()*1.6, 0);
	glTranslatef(animation->getPosX()*0.93,0,0);
	glTranslatef(0,0,animation->getPosZ());
	pieceAppearance->apply();
	GLUquadric* quadric;
	if((quadric = gluNewQuadric())!=0){
		gluCylinder(quadric,0.6,0.6,0.5,10,5);
		glPushMatrix();
		glRotatef(180.0,0,1,0);
		gluDisk (quadric, 0, 0.6, 10, 5);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0,0,0.5);
		gluDisk (quadric, 0, 0.6, 10, 5);
		glPopName();
		glPopMatrix();
	}
	glPopMatrix();
	line = animation->getPosX();
	column = animation->getPosY();
}

std::vector<int> BoardPiece::getPosition(){
	std::vector<int> ret;
	ret.push_back(line);
	ret.push_back(column);
	return ret;
}

void BoardPiece::updateAnimation(unsigned long t){
	animation->update(t);
}

Board::Board(CGFobject *bo,CGFappearance* bA):bObject(bo),boardAppearance(bA){
	
}

void Board::drawBoard(int x, int y){
	boardAppearance->apply();
		glPushMatrix();
		glLoadName(x);
		glPushName(y);
		glTranslatef(0, y*1.6, 0);
		glPushMatrix();
		glTranslatef(x*0.93,0,0);
		glRotatef(90,0,0,1);
		bObject->draw();
		glPopName();
		glPopMatrix();
		glPopMatrix();
}

void Board::drawBoardComplete(int line, int x, int y, int limit){
	if(line == 16)
		return;

	if ( hexgs.find(x) != hexgs.end() )
		if (y == hexgs[x])
			return;
	
	// top board
	if (line < 3) {
		drawBoard(x,y);
		hexgs[x] = y;

		line++;
		drawBoardComplete(line, x+1, y-1,limit);
		drawBoardComplete(line, x+1, y+1,limit);
	}
	//middle board
	else if (line == 3) {
		drawBoard(x,y);
		hexgs[x] = y;

		line++;
		drawBoardComplete(line, x+1, y-1,limit);
		drawBoardComplete(line, x+1, y+1,limit);
		drawBoardComplete(line, x+2, y,limit);
	}
	else if (line < 8) {
		drawBoard(x,y);
		hexgs[x] = y;

		line++;
		drawBoardComplete(line, x+2, y,limit);
	}
	//bottomboard
	else{
		if(y>limit)
			return;
		drawBoard(x,y);
		hexgs[x] = y;
		limit--;
		line++;
		drawBoardComplete(line, x+1, y+1,limit);
	}
}

void Board::draw(){
	hexgs.clear();
	drawBoardComplete(0,0,4,8);
}