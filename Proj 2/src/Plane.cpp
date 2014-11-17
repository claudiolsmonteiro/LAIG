#include "Plane.h"
#include <GL/glu.h>


Plane::Plane(void)
{
	_numDivisions = 1;
	_ratio = 1.0;
}

Plane::Plane(int n)
{
	_numDivisions = n;
	_ratio = 1.0;
}

Plane::Plane(int n, double ratio){
	_numDivisions = n;
	_ratio = ratio;
}

Plane::~Plane(void)
{
}

void Plane::draw()
{
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(bx/(double)_numDivisions, 0);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2d((bx+1)/(double)_numDivisions, (bz/(double)_numDivisions) / (double)_ratio);
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d(bx/(double)_numDivisions, ((bz+1)/(double)_numDivisions) / (double)_ratio);
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2d(((bx+1)/(double)_numDivisions), 1.0);
		glVertex3d(bx+ 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();

}

void Plane::draw(int s, int t){
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d((bx/(double)_numDivisions)*s, 0);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2d(((bx+1)/(double)_numDivisions)*s, ((bz/(double)_numDivisions) / (double)_ratio)*t);
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d((bx/(double)_numDivisions)*s, (((bz+1)/(double)_numDivisions) / (double)_ratio)*t);
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2d(((bx+1)/(double)_numDivisions)*s, 1.0*t);
		glVertex3d(bx+ 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();
}

void Plane::drawWindowWall(){

	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);
	double s = 2, t = 2;
	float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(2, s);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2d(t, s-(3/_numDivisions));
			glVertex3f(bx + 1, 0, bz);
			t-=3/_numDivisions;
			glTexCoord2d(t, s);
			glVertex3f(bx, 0, bz + 1);
		}
		s-=3/_numDivisions;
		glTexCoord2d(-1, s);
		glVertex3d(bx+ 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();
}

void Plane::drawWindowWallOpen(){
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glNormal3f(0,-1,0);

	float color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
	double tx = -0.886, ty = 0.953;
	//Top
	glBegin(GL_QUADS);

	glTexCoord2d(tx, ty);
	glVertex3d(0.66666, 0.0, 0.0);

	ty+=0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(1.0, 0.0, 0.0);

	tx+=3*0.924;
	glTexCoord2d(tx, ty);
	glVertex3d(1.0, 0.0, 1.0);

	ty -= 0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(0.66666, 0.0, 1.0);
	glEnd();

	//Right
	glBegin(GL_QUADS);
	ty -= 0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(0.33333, 0.0, 1.0);

	tx -= 0.924;
	glTexCoord2d(tx, ty);
	glVertex3d(0.33333, 0.0, 0.66666);

	ty += 0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(0.66666, 0.0, 0.66666);

	tx += 0.924;
	glTexCoord2d(tx, ty);
	glVertex3d(0.66666, 0.0, 1.0);
	glEnd();

	//Bottom
	glBegin(GL_QUADS);
	ty -= 2*0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(0.0, 0.0, 1.0);

	tx -= 3*0.924;
	glTexCoord2d(tx, ty);
	glVertex3d(0.0, 0.0, 0.0);

	ty += 0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(0.33333, 0.0, 0.0);

	tx += 3*0.924;
	glTexCoord2d(tx, ty);
	glVertex3d(0.33333, 0.0, 1.0);
	glEnd();


	//Left
	glBegin(GL_QUADS);
	//glNormal3f(0,-1,0);
	tx -= 3*0.924;
	glTexCoord2d(tx, ty);
	glVertex3d(0.33333, 0.0, 0.0);

	ty += 0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(0.66666, 0.0, 0.0);

	tx += 0.924;
	glTexCoord2d(tx, ty);
	glVertex3d(0.66666, 0.0, 0.33333);

	ty -= 0.906;
	glTexCoord2d(tx, ty);
	glVertex3d(0.33333, 0.0, 0.33333);

	glEnd();
	glPopMatrix();
}