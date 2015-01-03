#include "ExampleObject.h"

void ExampleObject::draw() 
{
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

void ExampleObject::drawPiece() 
{
	GLUquadric* quadric;
	if((quadric = gluNewQuadric())!=0){
		gluCylinder(quadric,0.25,0.25,0.3,10,5);
		glPushMatrix();
		glRotatef(180.0,0,1,0);
		gluDisk (quadric, 0, 0.25, 10, 5);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0,0,0.3);
		gluDisk (quadric, 0, 0.25, 10, 5);
		glPopMatrix();
	}
}