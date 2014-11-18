#include <GL/glew.h>
#include "primitives.h"
#include "math.h"
#include "string.h"

#include <stdlib.h>
double pi = acos(-1.0);

Point calculateTriangleNormal(Point p1, Point p2, Point p3){

	Point vec12 =  Point(p2.getX()-p1.getX(), p2.getY()-p1.getY(), p2.getZ()-p1.getZ());
	Point vec13 =  Point(p3.getX()-p1.getX(), p3.getY()-p1.getY(), p3.getZ()-p1.getZ());
	
	float nx = vec12.getY()*vec13.getZ() - vec12.getZ()*vec13.getY();
	float ny = vec12.getZ()*vec13.getX() - vec12.getX()*vec13.getZ();
	float nz = vec12.getX()*vec13.getY() - vec12.getY()*vec13.getX();

	float m = sqrt(nx*nx + ny*ny + nz*nz);

	Point normal = Point(nx/m, ny/m, nz/m);

	return normal;
}

vector<Point> getTextureCoords(Point p1, Point p2, Point p3){
	float a, b, c;
	float beta;
	float cosBeta;

	a = sqrtf(pow((p3.getX()-p1.getX()),2) + pow((p3.getY()-p1.getY()),2) + pow((p3.getZ()-p1.getZ()),2));
	b = sqrtf(pow((p2.getX()-p1.getX()),2) + pow((p2.getY()-p1.getY()),2) + pow((p2.getZ()-p1.getZ()),2));
	c = sqrtf(pow((p3.getX()-p2.getX()),2) + pow((p3.getY()-p2.getY()),2) + pow((p3.getZ()-p2.getZ()),2));

	cosBeta = (a*a - b*b + c*c)/(2*a*c);

	beta = acos(cosBeta);

	Point t1 = Point(c - a*cosBeta, a*sin(beta), 0);
	Point t2 = Point(0, 0, 0);
	Point t3 = Point(c, 0, 0);

	vector<Point> ret;
	ret.push_back(t1);
	ret.push_back(t2);
	ret.push_back(t3);

	return ret;
}


Primitive::Primitive(Rectangle r) {
	this->rectangle = r;
	this->type = "rectangle";
}
Primitive::Primitive(Triangle t) {
	this->triangle = t;
	this->type = "triangle";
}
Primitive::Primitive(Cylinder c) {
	this->cylinder = c;
	this->type = "cylinder";
}
Primitive::Primitive(Sphere s) {
	this->sphere = s;
	this->type = "sphere";
}
Primitive::Primitive(Torus t) {
	this->torus = t;
	this->type = "torus";
}
Primitive::Primitive(Plane p) {
    this->plane = p;
    this->type = "plane";
}
Primitive::Primitive(Patch pt) {
    this->patch = pt;
    this->type = "patch";
}
Primitive::Primitive(Vehicle v) {
    this->vehicle = v;
    this->type = "vehicle";
}
Primitive::Primitive(Flag f) {
    this->flag = f;
    this->type = "flag";
}
Rectangle Primitive::getRectangle(){
	return rectangle;
}
Triangle Primitive::getTriangle(){
	return triangle;
}
Cylinder Primitive::getCylinder(){
	return cylinder;
}
Sphere Primitive::getSphere(){
	return sphere;
}
Torus Primitive::getTorus(){
	return torus;
}
Vehicle Primitive::getVehicle(){
	return vehicle;
}
Flag Primitive::getFlag(){
	return flag;
}
string Primitive::getType(){
	return type;
}

void Primitive::draw(int texS, int texL){
	if(type == "rectangle")
			rectangle.draw(texS, texL);
	else if(type == "triangle")
			triangle.draw(texS, texL);
	else if(type == "cylinder"){
			GLUquadric* quadric;
				if((quadric = gluNewQuadric())!=0){
					gluCylinder(quadric,cylinder.getBase(),cylinder.getTop(),cylinder.getHeight(),cylinder.getSlices(),cylinder.getStacks());
					glPushMatrix();
					glRotatef(180.0,0,1,0);
					gluDisk (quadric, 0, cylinder.getBase(), cylinder.getSlices(), cylinder.getStacks());
					glPopMatrix();
					glPushMatrix();
					glTranslatef(0,0,cylinder.getHeight());
					gluDisk (quadric, 0, cylinder.getTop(), cylinder.getSlices(), cylinder.getStacks());
					glPopMatrix();
				}
	}
	else if(type == "sphere"){
			GLUquadric* quadric;
			if((quadric = gluNewQuadric())!=0){
				gluSphere(quadric,sphere.getRadius(),sphere.getSlices(),sphere.getStacks());
			}
	}
	else if(type == "torus")
            torus.DrawTorus();
    else if(type == "plane")
        plane.draw();
	else if(type == "patch")
        patch.draw();
	else if(type == "vehicle")
		vehicle.draw();
	else if(type == "flag")
		flag.draw();
}

Primitive::~Primitive()
{
}


Rectangle::Rectangle(){
}
Triangle::Triangle(){
}
Cylinder::Cylinder(){
}
Torus::Torus(){
}
Sphere::Sphere(){
}

Rectangle::Rectangle(float xi, float yi, float xf, float yf): x1(xi), y1(yi), x2(xf), y2(yf){
}

float Rectangle::getFirstX(){
	return x1;
}
float Rectangle::getFirstY(){
	return y1;
}
float Rectangle::getLastX(){
	return x2;
}
float Rectangle::getLastY(){
	return y2;
}
void Rectangle::draw(float s, float t){

	float tmp;
	if(x1 > x2){
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	if(y1 > y2){
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}

	if(s == 0 || t == 0){
		glBegin(GL_POLYGON);

		glNormal3f(x1, y1, 1);
		glVertex3f(x1, y1, 0);

		glNormal3f(x2, y1, 1);
		glVertex3f(x2, y1, 0);

		glNormal3f(x2, y2, 1);
		glVertex3f(x2, y2, 0);

		glNormal3f(x1, y2, 1);
		glVertex3f(x1, y2, 0);

		glEnd();
		return;
	}

	float h = y2-y1;
	float l = x2-x1;

	glBegin(GL_POLYGON);

		glNormal3f(x1, y1, 1);
		glTexCoord2f(0, 0); 
		glVertex3f(x1, y1, 0);

		glNormal3f(x2, y1, 1);
		glTexCoord2f(l/s, 0); 
		glVertex3f(x2, y1, 0);

		glNormal3f(x2, y2, 1);
		glTexCoord2f(l/s, h/t); 
		glVertex3f(x2, y2, 0);

		glNormal3f(x1, y2, 1);
		glTexCoord2f(0, h/t); 
		glVertex3f(x1, y2, 0);

	glEnd();
}

Rectangle::~Rectangle(){
}

Point::Point(){
}

Point::Point(float x, float y, float z): px(x), py(y), pz(z){
}

float Point::getX(){
	return px;
}

float Point::getY(){
	return py;
}

float Point::getZ(){
	return pz;
}

Triangle::Triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3): p1x(x1), p1y(y1), p1z(z1), p2x(x2), p2y(y2), p2z(z2), p3x(x3), p3y(y3), p3z(z3){
	p1 = Point(p1x, p1y, p1z);
	p2 = Point(p2x, p2y, p2z);
	p3 = Point(p3x, p3y, p3z);
}

Point Triangle::getP1(){
	return p1;
}

Point Triangle::getP2(){
	return p2;
}

Point Triangle::getP3(){
	return p3;
}

void Triangle::draw(float s, float t){

	Point normal = calculateTriangleNormal(p1, p2, p3);
	vector<Point> texC = getTextureCoords(p1, p2, p3);

	if(s == 0 || t == 0){
		glBegin(GL_POLYGON);
			glNormal3f(normal.getX(),normal.getY(),normal.getZ());
			glVertex3f(p1.getX(), p1.getY(), p1.getZ());
			glVertex3f(p2.getX(), p2.getY(), p2.getZ());
			glVertex3f(p3.getX(), p3.getY(), p3.getZ());
		glEnd();
		return;
	}
	else{
		glBegin(GL_POLYGON);
			glNormal3f(normal.getX(),normal.getY(),normal.getZ());
			glTexCoord2f(texC[0].getX()/s, texC[0].getY()/t);
			glVertex3f(p1.getX(), p1.getY(), p1.getZ());
			glTexCoord2f(texC[1].getX()/s, texC[1].getY()/t);
			glVertex3f(p2.getX(), p2.getY(), p2.getZ());
			glTexCoord2f(texC[2].getX()/s, texC[2].getY()/t);
			glVertex3f(p3.getX(), p3.getY(), p3.getZ());
		glEnd();
	}
}

Triangle::~Triangle(){
}

Cylinder::Cylinder(float b, float t, float h, int sl, int st): base(b), top(t), height(h), slices(sl), stacks(st){
}

float Cylinder::getBase(){
	return base;
}
float Cylinder::getTop(){
	return top;
}
float Cylinder::getHeight(){
	return height;
}
int Cylinder::getSlices(){
	return slices;
}
int Cylinder::getStacks(){
	return stacks;
}

Cylinder::~Cylinder(){
}

Sphere::Sphere(float r, int sl, int st): radius(r), slices(sl), stacks(st){
}

float Sphere::getRadius(){
	return radius;
}
int Sphere::getSlices(){
	return slices;
}
int Sphere::getStacks(){
	return stacks;
}

Sphere::~Sphere(){
}

Torus::Torus(float i, float o, int sl, int l): inner(i), outer(o), slices(sl), loops(l){

}

void Torus::DrawTorus() {
  double  iradius = inner, oradius = outer, phi, psi, dpsi, dphi;
  double *vertex, *normal;
  int    i, j;
  double spsi, cpsi, sphi, cphi ;


  if ( slices < 1 ) slices = 1;
  if ( loops < 1 ) loops = 1;

  /* Increment the number of sides and rings to allow for one more point than surface */
  slices ++ ;
  slices ++ ;

  /* Allocate the vertices array */
  vertex = (double *)calloc( sizeof(double), 3 * slices * loops );
  normal = (double *)calloc( sizeof(double), 3 * slices * loops );

  glPushMatrix();

  dpsi =  2.0 * pi / (double)(loops - 1) ;
  dphi = -2.0 * pi / (double)(slices - 1) ;
  psi  = 0.0;

  for( j=0; j<loops; j++ )
  {
    cpsi = cos ( psi ) ;
    spsi = sin ( psi ) ;
    phi = 0.0;

    for( i=0; i<slices; i++ )
    {
      int offset = 3 * ( j * slices + i ) ;
      cphi = cos ( phi ) ;
      sphi = sin ( phi ) ;
      *(vertex + offset + 0) = cpsi * ( oradius + cphi * iradius ) ;
      *(vertex + offset + 1) = spsi * ( oradius + cphi * iradius ) ;
      *(vertex + offset + 2) =                    sphi * iradius  ;
      *(normal + offset + 0) = cpsi * cphi ;
      *(normal + offset + 1) = spsi * cphi ;
      *(normal + offset + 2) =        sphi ;
      phi += dphi;
    }

    psi += dpsi;
  }

    glBegin( GL_QUADS );
  for( i=0; i<slices-1; i++ )
  {
    for( j=0; j<loops-1; j++ )
    {
      int offset = 3 * ( j * slices + i ) ;
      glNormal3dv( normal + offset );
      glVertex3dv( vertex + offset );
      glNormal3dv( normal + offset + 3 );
      glVertex3dv( vertex + offset + 3 );
      glNormal3dv( normal + offset + 3 * slices + 3 );
      glVertex3dv( vertex + offset + 3 * slices + 3 );
      glNormal3dv( normal + offset + 3 * slices );
      glVertex3dv( vertex + offset + 3 * slices );
    }
  }

  glEnd();

  free ( vertex ) ;
  free ( normal ) ;
  glPopMatrix();
	//glutSolidTorus(inner, outer, slices, loops);
}

float Torus::getInner(){
	return inner;
}
float Torus::getOuter(){
	return outer;
}
int Torus::getSlices(){
	return slices;
}
int Torus::getLoops(){
	return loops;
}
Torus::~Torus(){
}

Plane::Plane(void)
{
    _numDivisions = 1;
}

Plane::Plane(int n)
{
    _numDivisions = n;
}

Plane::~Plane(void)
{
}
GLfloat ctrlpoints[4][3] = {{  0.5, 0.0, -0.5},
							{  0.5, 0.0, 0.5},
							{ -0.5, 0.0, -0.5},
							{ -0.5, 0.0, 0.5} };


GLfloat nrmlcompon[4][3] = {{  0.0, 1.0, 0.0},
                            {  0.0, 1.0, 0.0},
                            {  0.0, 1.0, 0.0},
                            {  0.0, 1.0, 0.0} };



GLfloat textpoints[4][2] = {{ 0.0, 0.0},
                            { 0.0, 1.0},
                            { 1.0, 0.0},
                            { 1.0, 1.0} };
void Plane::draw()
{

    glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &ctrlpoints[0][0]);
    glMap2f(GL_MAP2_NORMAL,   0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &nrmlcompon[0][0]);
    glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textpoints[0][0]);
    
    glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_MAP2_NORMAL);
    glEnable(GL_MAP2_TEXTURE_COORD_2);
    
    glMapGrid2f(_numDivisions, 0.0,1.0, _numDivisions, 0.0,1.0);
    
    
    glEvalMesh2(GL_FILL, 0,_numDivisions, 0,_numDivisions);
    
    glDisable(GL_AUTO_NORMAL);   
}

Patch::Patch(void)
{
}

Patch::Patch(int order, int partsU,int partsV,char *compute, std::vector<Point> vp):order(order),partsU(partsU),partsV(partsV),compute(compute),controlPoints(vp)
{
	double o = order+1;
	npoints = (int)pow(o, 2);
	std::reverse(controlPoints.begin(),controlPoints.end());
}

void Patch::draw(){

	glFrontFace(GL_CW);
	glEnable(GL_AUTO_NORMAL);

	if(order == 1){
		GLfloat controlPts[4][3] = {{controlPoints[0].getX(), controlPoints[0].getY(), controlPoints[0].getZ()},
									{controlPoints[1].getX(), controlPoints[1].getY(), controlPoints[1].getZ()},
									{controlPoints[2].getX(), controlPoints[2].getY(), controlPoints[2].getZ()},
									{controlPoints[3].getX(), controlPoints[3].getY(), controlPoints[3].getZ()}};

		GLfloat textPts[4][2] = {{ 0.0, 1.0},
								 { 1.0, 1.0},
								 { 0.0, 0.0},
								 { 1.0, 0.0} };

		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 2,  0.0, 1.0, 6, 2,  &controlPts[0][0]);
		glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 2,  0.0, 1.0, 4, 2,  &textPts[0][0]);
	}
	else if(order == 2){
		GLfloat controlPts[9][3] = {{controlPoints[0].getX(), controlPoints[0].getY(), controlPoints[0].getZ()},
									{controlPoints[1].getX(), controlPoints[1].getY(), controlPoints[1].getZ()},
									{controlPoints[2].getX(), controlPoints[2].getY(), controlPoints[2].getZ()},
									{controlPoints[3].getX(), controlPoints[3].getY(), controlPoints[3].getZ()},
									{controlPoints[4].getX(), controlPoints[4].getY(), controlPoints[4].getZ()},
									{controlPoints[5].getX(), controlPoints[5].getY(), controlPoints[5].getZ()},
									{controlPoints[6].getX(), controlPoints[6].getY(), controlPoints[6].getZ()},
									{controlPoints[7].getX(), controlPoints[7].getY(), controlPoints[7].getZ()},
									{controlPoints[8].getX(), controlPoints[8].getY(), controlPoints[8].getZ()}};

		GLfloat textPts[9][2] = {{ 0.0, 1.0},
								 { 0.5, 1.0},
								 { 1.0, 1.0},
						         { 0.0, 0.5},
								 { 0.5, 0.5},
								 { 1.0, 0.5},
								 { 0.0, 0.0},
								 { 0.5, 0.0},
								 { 1.0, 0.0} };

		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3,  0.0, 1.0, 9, 3,  &controlPts[0][0]);
		glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 3,  0.0, 1.0, 6, 3,  &textPts[0][0]);
	}
	else if(order == 3){
		GLfloat controlPts[16][3] = {{controlPoints[0].getX(), controlPoints[0].getY(), controlPoints[0].getZ()},
									 {controlPoints[1].getX(), controlPoints[1].getY(), controlPoints[1].getZ()},
									 {controlPoints[2].getX(), controlPoints[2].getY(), controlPoints[2].getZ()},
									 {controlPoints[3].getX(), controlPoints[3].getY(), controlPoints[3].getZ()},
									 {controlPoints[4].getX(), controlPoints[4].getY(), controlPoints[4].getZ()},
									 {controlPoints[5].getX(), controlPoints[5].getY(), controlPoints[5].getZ()},
									 {controlPoints[6].getX(), controlPoints[6].getY(), controlPoints[6].getZ()},
									 {controlPoints[7].getX(), controlPoints[7].getY(), controlPoints[7].getZ()},
									 {controlPoints[8].getX(), controlPoints[8].getY(), controlPoints[8].getZ()},
									 {controlPoints[9].getX(), controlPoints[9].getY(), controlPoints[9].getZ()},
									 {controlPoints[10].getX(), controlPoints[10].getY(), controlPoints[10].getZ()},
									 {controlPoints[11].getX(), controlPoints[11].getY(), controlPoints[11].getZ()},
									 {controlPoints[12].getX(), controlPoints[12].getY(), controlPoints[12].getZ()},
									 {controlPoints[13].getX(), controlPoints[13].getY(), controlPoints[13].getZ()},
									 {controlPoints[14].getX(), controlPoints[14].getY(), controlPoints[14].getZ()},
									 {controlPoints[15].getX(), controlPoints[15].getY(), controlPoints[15].getZ()}};

		GLfloat textPts[16][2] = {{ 0.0, 1.0},
								  { 0.333, 1.0},
								  { 0.666, 1.0},
							   	  { 1.0, 1.0},
								  { 0.0, 0.666},
								  { 0.333, 0.666},
								  { 0.666, 0.666},
								  { 1.0, 0.666},
								  { 0.0, 0.333},
								  { 0.333, 0.333},
								  { 0.666, 0.333},
								  { 1.0, 0.333},
								  { 0.0, 0.0},
								  { 0.333, 0.0},
								  { 0.666, 0.0},
								  { 1.0, 0.0} };

		glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4,  0.0, 1.0, 12, 4,  &controlPts[0][0]);
		glMap2f(GL_MAP2_TEXTURE_COORD_2,  0.0, 1.0, 2, 4,  0.0, 1.0, 8, 4,  &textPts[0][0]);
	}

	glEnable(GL_MAP2_VERTEX_3);
    glEnable(GL_MAP2_NORMAL);
    glEnable(GL_MAP2_TEXTURE_COORD_2);

	glMapGrid2f(partsU, 0.0,1.0, partsV, 0.0,1.0);

	if(strcmp(compute,"point")==0)	{
		glEvalMesh2(GL_LINE, 0, partsU, 0, partsV);
	} else if (strcmp(compute,"line")==0) {
		glEvalMesh2(GL_POINT, 0, partsU, 0, partsV);
	} else if(strcmp(compute,"fill")==0){
		glEvalMesh2(GL_FILL, 0, partsU, 0, partsV);
	}

	glFrontFace(GL_CCW);
	glDisable(GL_AUTO_NORMAL);
}
Patch::~Patch(void)
{
}

Vehicle::Vehicle(void)
{
	float ambA[3] = {0.2, 0.2, 0.2};
	float difA[3] = {0.9, 0.9, 0.9};
	float specA[3] = {0, 0.2, 0.3};
	float shininessA = 100.f;



	ovniHeadTex = new CGFappearance(ambA,difA,specA,shininessA);
	ovniHeadTex->setTexture("azul.jpg");
	ovniHeadTex->setTextureWrap(GL_CLAMP,GL_CLAMP);

	ovniBodyTex = new CGFappearance(ambA,difA,specA,shininessA);
	ovniBodyTex->setTexture("wall.png");
	ovniBodyTex->setTextureWrap(GL_CLAMP,GL_CLAMP);
}

Vehicle::~Vehicle(void)
{
}
void Vehicle::draw() {
	glPushMatrix();
	glTranslated(5, 5, 5);
	glRotated(-90, 0, 0, 1);
	ovniBodyTex->apply();
	drawUpperBody();
	glPushMatrix();
	glRotated(180, 0, 0, 1);
	glScaled(3, 1, 1);
	drawUpperBody();
	glPopMatrix();
	ovniHeadTex->apply();
	drawHead();
	glPopMatrix();
}

void Vehicle::drawUpperBody(){
	std::vector<Point> patcherpoints;

	patcherpoints.push_back(Point(0, 0, -6));
	patcherpoints.push_back(Point(0, -6, -2));
	patcherpoints.push_back(Point(0, -6, 2));
	patcherpoints.push_back(Point(0, 0, 6));

	patcherpoints.push_back(Point(0, 0, -6));
	patcherpoints.push_back(Point(-1, -1, -2));
	patcherpoints.push_back(Point(-1, -1, 2));
	patcherpoints.push_back(Point(0, 0, 6));

	patcherpoints.push_back(Point(0, 0, -6));
	patcherpoints.push_back(Point(-1, 1, -2));
	patcherpoints.push_back(Point(-1, 1, 2));
	patcherpoints.push_back(Point(0, 0, 6));

	patcherpoints.push_back(Point(0, 0, -6));
	patcherpoints.push_back(Point(0, 6, -2));
	patcherpoints.push_back(Point(0, 6, 2));
	patcherpoints.push_back(Point(0, 0, 6));



	Patch p(3, 6, 6, "fill", patcherpoints);
	p.draw();
}

void Vehicle::drawHead(){
	std::vector<Point> patcherpoints;

	patcherpoints.push_back(Point(0, 0, -2));
	patcherpoints.push_back(Point(0, -2, -1));
	patcherpoints.push_back(Point(0, -2, 1));
	patcherpoints.push_back(Point(0, 0, 2));

	patcherpoints.push_back(Point(0, 0, -2));
	patcherpoints.push_back(Point(-4, -1, -1));
	patcherpoints.push_back(Point(-4, -1, 1));
	patcherpoints.push_back(Point(0, 0, 2));

	patcherpoints.push_back(Point(0, 0, -2));
	patcherpoints.push_back(Point(-4, 1, -1));
	patcherpoints.push_back(Point(-4, 1, 1));
	patcherpoints.push_back(Point(0, 0, 2));

	patcherpoints.push_back(Point(0, 0, -2));
	patcherpoints.push_back(Point(0, 2, -1));
	patcherpoints.push_back(Point(0, 2, 1));
	patcherpoints.push_back(Point(0, 0, 2));



	Patch p(3, 6, 6, "fill", patcherpoints);
	p.draw();
}

Flag::Flag() {

}
Flag::Flag(char * texture)
{
	string t(texture);
	this->texture = t;
}

Flag::~Flag(void)
{
}
void Flag::draw() {
	fshader->bind();
	Plane::draw();
	fshader->unbind();
}

FlagShader::FlagShader(char * app) {
	init("../data/shader.vert", "../data/shader.frag");

	CGFshader::bind();

	normScale=0.0;

	scaleLoc = glGetUniformLocation(id(), "normScale");

	baseTexture=new CGFtexture("../bin/flag.jpg");


	glUniform1i(baseImageLoc, 0);
}

void FlagShader::bind(void)
{
	CGFshader::bind();

	// update uniforms
	glUniform1f(scaleLoc, normScale);

	// make sure the correct texture unit is active
	glActiveTexture(GL_TEXTURE0);

	// apply/activate the texture you want, so that it is bound to GL_TEXTURE0
	baseTexture->apply();

}
void FlagShader::unbind()
{
	CGFshader::unbind();
}
FlagShader::~FlagShader(void)
{
}