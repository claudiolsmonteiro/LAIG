#include "Game.h"

std::vector<Point> calculateControlPoints(std::vector<int> p1, std::vector<int> p2){
	std::vector<Point> ret;
	int cont = 4;

	float xi = p1[0];
	float yi = p1[1];
	float zi = 0;

	printf("inicio:%f, %f, %f\n\n",xi,yi,zi);

	float xf = p2[0];
	float yf = p2[1];
	float zf = 2;

	printf("fim:%f, %f, %f\n\n",xf,yf,zf);

	float distx = (xf-xi)/4;
	float disty = (yf-yi)/4;
	float distz = (zf-zi)/2;

	Point p(xi,yi,zi);
	ret.push_back(p);

	while(cont > 2){
		xi += distx;
		yi += disty;
		zi += distz;
		Point p(xi,yi,zi);
		ret.push_back(p);
		cont--;
	}
	while(cont > 0){
		xi += distx;
		yi += disty;
		zi -= distz;
		Point p(xi,yi,zi);
		ret.push_back(p);
		cont--;
	}
	printf("%f, %f, %f\n\n",xi,yi,zi);
	return ret;
}


Game::Game(CGFobject *bo,CGFappearance* bA, CGFappearance* pA1, CGFappearance* pA2):pieceAppearance1(pA1),pieceAppearance2(pA2){
	socket = new Socket();
	board = new Board(bo,bA);
	playIndex = -1;
		
		//"[['  ', '0','1','2','3','4','5','6','7','8'],[' 0', ' ',' ',' ',' ','E',' ',' ',' ',' '],[' 1', ' ',' ',' ','E',' ','E',' ',' ',' '],[' 2', ' ',' ','E',' ','E',' ','E',' ',' '],[' 3', ' ','E',' ','E',' ','E',' ','E',' '],[' 4', 'E',' ','E',' ','E',' ','E',' ','E'],[' 5', ' ','E',' ','E',' ','E',' ','E',' '],[' 6', 'E',' ','E',' ','E',' ','E',' ','E'],[' 7', ' ','E',' ','E',' ','E',' ','E',' '],[' 8', 'E',' ','E',' ','E',' ','E',' ','E'],[' 9', ' ','E',' ','E',' ','E',' ','E',' '],['10', 'E',' ','E',' ','E',' ','E',' ','E'],['11', ' ','E',' ','E',' ','E',' ','E',' '],['12', 'E',' ','E',' ','E',' ','E',' ','E'],['13', ' ','E',' ','E',' ','E',' ','E',' '],['14', ' ',' ','E',' ','E',' ','E',' ',' '],['15', ' ',' ',' ','E',' ','E',' ',' ',' '],['16', ' ',' ',' ',' ','E',' ',' ',' ',' ']]";
	
	pieces.clear();
	positions.push_back("0, 4");
	positions.push_back("1, 3");
	positions.push_back("1, 5");
	positions.push_back("2, 2");
	positions.push_back("2, 4");
	positions.push_back("2, 6");
	positions.push_back("3, 1");
	positions.push_back("3, 3");
	positions.push_back("3, 5");
	positions.push_back("3, 7");
	positions.push_back("4, 0");
	positions.push_back("4, 2");
	positions.push_back("4, 4");
	positions.push_back("4, 6");
	positions.push_back("4, 8");
	positions.push_back("5, 1");
	positions.push_back("5, 3");
	positions.push_back("5, 5");
	positions.push_back("5, 7");
	positions.push_back("6, 0");
	positions.push_back("6, 2");
	positions.push_back("6, 4");
	positions.push_back("6, 6");
	positions.push_back("6, 8");
	positions.push_back("7, 1");
	positions.push_back("7, 3");
	positions.push_back("7, 5");
	positions.push_back("7, 7");
	positions.push_back("8, 0");
	positions.push_back("8, 2");
	positions.push_back("8, 4");
	positions.push_back("8, 6");
	positions.push_back("8, 8");
	positions.push_back("9, 1");
	positions.push_back("9, 3");
	positions.push_back("9, 5");
	positions.push_back("9, 7");
	positions.push_back("10,0");
	positions.push_back("10,2");
	positions.push_back("10,4");
	positions.push_back("10,6");
	positions.push_back("10,8");
	positions.push_back("11,1");
	positions.push_back("11,3");
	positions.push_back("11,5");
	positions.push_back("11,7");
	positions.push_back("12,0");
	positions.push_back("12,2");
	positions.push_back("12,4");
	positions.push_back("12,6");
	positions.push_back("12,8");
	positions.push_back("13,1");
	positions.push_back("13,3");
	positions.push_back("13,5");
	positions.push_back("13,7");
	positions.push_back("14,2");
	positions.push_back("14,4");
	positions.push_back("14,6");
	positions.push_back("15,3");
	positions.push_back("15,5");
	positions.push_back("16,4");

	currentplayer = PLAYER1;
}

void Game::drawBoard(){
	board->draw();
}

void Game::fillBoard(){
	int blacks = 30, whites = 30;
	int index=0, numPositions=positions.size();
	char socketString[] = "[['  ', '0','1','2','3','4','5','6','7','8'],[' 0', ' ',' ',' ',' ','E',' ',' ',' ',' '],[' 1', ' ',' ',' ','E',' ','E',' ',' ',' '],[' 2', ' ',' ','E',' ','E',' ','E',' ',' '],[' 3', ' ','E',' ','E',' ','E',' ','E',' '],[' 4', 'E',' ','E',' ','E',' ','E',' ','E'],[' 5', ' ','E',' ','E',' ','E',' ','E',' '],[' 6', 'E',' ','E',' ','E',' ','E',' ','E'],[' 7', ' ','E',' ','E',' ','E',' ','E',' '],[' 8', 'E',' ','E',' ','E',' ','E',' ','E'],[' 9', ' ','E',' ','E',' ','E',' ','E',' '],['10', 'E',' ','E',' ','E',' ','E',' ','E'],['11', ' ','E',' ','E',' ','E',' ','E',' '],['12', 'E',' ','E',' ','E',' ','E',' ','E'],['13', ' ','E',' ','E',' ','E',' ','E',' '],['14', ' ',' ','E',' ','E',' ','E',' ',' '],['15', ' ',' ',' ','E',' ','E',' ',' ',' '],['16', ' ',' ',' ',' ','E',' ',' ',' ',' ']]";
	while(whites > 0){
		numPositions = positions.size();
		srand(time(NULL));
		index = rand() % numPositions;

		int line = stoi(positions[index]);
		char c = positions[index][3];
		int column = c - '0';

		BoardPiece* ba = new BoardPiece();
		LinearAnimation *a = new LinearAnimation(line,column);
		ba->setPosition(line, column);
		ba->setAppearance(pieceAppearance1);
		ba->setAnimation(a);
		pieces[positions[index]] = ba;
		ba->draw();
		positions.erase(positions.begin()+index);

		int nextline = line*44;
		int nextcolumn = column*4;
		int stringIndex = 53 + nextline + nextcolumn;
		socketString[stringIndex] = 'B';
		whites--;
	}
	while(blacks > 0){
		numPositions = positions.size();
		srand(time(NULL));
		index = rand() % numPositions;

		int line = stoi(positions[index]);
		char c = positions[index][3];
		int column = c - '0';

		BoardPiece* ba = new BoardPiece();
		LinearAnimation *a = new LinearAnimation(line,column);
		ba->setPosition(line, column);
		ba->setAppearance(pieceAppearance2);
		ba->setAnimation(a);
		pieces[positions[index]] = ba;
		ba->draw();
		positions.erase(positions.begin()+index);

		int nextline = line*44;
		int nextcolumn = column*4;
		int stringIndex = 53 + nextline + nextcolumn;
		socketString[stringIndex] = 'P';
		blacks--;
	}
	/*for(unsigned int i=0; i < 795; i++){
		socketBoard[i] = socketString[i];
	}*/

	playIndex++;
	oldPlays.push_back(socketString);
	std::cout << oldPlays[playIndex] << '\n';
}

void Game::drawPieces(){
	for (std::map<std::string,BoardPiece*>::iterator it=pieces.begin(); it!=pieces.end(); ++it)
		it->second->draw();
}

void Game::undo(){
	oldPlays.erase(oldPlays.begin()+playIndex);
	playIndex--;
}

void Game::movePiece(std::string p1, std::string p2){
	 
	selectedPiece.clear();
	std::vector<int> p1Position = pieces[p1]->getPosition();
	std::vector<int> p2Position = pieces[p2]->getPosition();
	std::vector<Point> ctrlPoints = calculateControlPoints(p1Position, p2Position);
	LinearAnimation* a = new LinearAnimation("anim",5.0,ctrlPoints);
	pieces[p2] = pieces[p1];
	pieces[p2]->setAnimation(a);
	pieces[p1]->setPosition(p2Position[0], p2Position[1]);
	pieces.erase(p1);

	std::string newPlay = oldPlays[playIndex];
	

	int line = p1Position[0]*44;
	int column = p1Position[1]*4;
	int stringIndex = 53 + line + column;
	char player = newPlay[stringIndex];
	newPlay[stringIndex] = 'E';

	line = p2Position[0]*44;
	column = p2Position[1]*4;
	stringIndex = 53 + line + column;
	stringstream e;
	if(currentplayer == PLAYER1) {
		e << "valida("<< newPlay<< ", " <<p2Position[0]+1<< ", " <<p2Position[1]+1<< ", 'P').\n";
		string env = e.str();
		socket->envia(env,env.size() );
		char ans[128];
		socket->recebe(ans);
		cout << "prolog answered: " << ans << endl;
		if(strcmp(ans,"'N'") == 0 )
			return;
	}
	else if(currentplayer == PLAYER2) {
		e << "valida("<< newPlay<< ", " <<p2Position[0]+1<< ", " <<p2Position[1]+1<< ", 'B').\n";
		string env = e.str();
		socket->envia(env,env.size() );
		char ans[128];
		socket->recebe(ans);
		cout << "prolog answered: " << ans << endl;
		if(strcmp(ans,"'N'") == 0 )
			return;
	}

	newPlay[stringIndex] = player;
	oldPlays.push_back(newPlay);
	playIndex++;
	if(currentplayer == PLAYER2)
		currentplayer = PLAYER1;
	else
		currentplayer = PLAYER2;
	std::cout << oldPlays[playIndex] << '\n';
}

void Game::selectPiece(int x, int y){
	std::string s;
	std::stringstream ss;
	
	ss << x << ',';
	if(x < 10)
		ss << ' ' << y;
	else
		ss << y;
	s = ss.str();
	if(selectedPiece.size() > 0){
		movePiece(selectedPiece, s);
	}
	else
		selectedPiece = s;
}

void Game::updateAnims(unsigned long t){
	for (std::map<std::string,BoardPiece*>::iterator it=pieces.begin(); it!=pieces.end(); ++it)
		it->second->updateAnimation(t);
}