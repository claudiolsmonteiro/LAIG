#include "Game.h"

std::vector<Point> calculateControlPoints(std::vector<int> p1, std::vector<int> p2){
	std::vector<Point> ret;
	int cont = 4;

	float xi = p1[0];
	float yi = p1[1];
	float zi = 0;


	float xf = p2[0];
	float yf = p2[1];
	float zf = 2;


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
	return ret;
}

int GetDirectionInt(std::string p1, std::string p2){
	
	int line1 = stoi(p1);
	char c = p1[3];
	int column1 = c - '0';

	int line2 = stoi(p2);
	c = p2[3];
	int column2 = c - '0';

	//Para Norte
	if(line1 > line2){
		//A Norte
		if(column1 == column2)
			return 1;
		//A Nordeste
		else if(column1 < column2)
			return 2;
		//A Noroeste
		else
			return 3;
	}
	//Para Sul
	else if(line1 < line2){
		//A Sul
		if(column1 == column2)
			return 4;
		//A Sudeste
		else if(column1 < column2)
			return 5;
		//A Sudoeste
		else
			return 6;
	}
	else
		return -1;
}
bool StringContains(std::string s, int num){
	char n = num + '0';

	for(unsigned int i = 0; i < s.size(); i++){
		if(s[i] == n)
			return true;
	}
	return false;
}
std::string GetDestination(std::string p, int dir, int range){

	int x = stoi(p);
	char c = p[3];
	int y = c - '0';

	std::string ret;
	std::stringstream ss;

	switch(dir){
		//Norte
		case 1:
			x = x - (range*2);
			break;
		//Nordeste
		case 2:
			x = x - range;
			y = y + range;
			break;
		//Noroeste
		case 3:
			x = x - range;
			y = y - range;
			break;
		//Sul
		case 4:
			x = x + (range*2);
			break;
		//Sudeste
		case 5:
			x = x + range;
			y = y + range;
			break;
		//Sudoeste
		case 6:
			x = x + range;
			y = y - range;
			break;
	}
	ss << x << ',';
	if(x < 10)
		ss << ' ' << y;
	else
		ss << y;
	ret = ss.str();
	return ret;
}

Game::Game(CGFobject *bo,CGFappearance* bA, CGFappearance* pA1, CGFappearance* pA2):pieceAppearance1(pA1),pieceAppearance2(pA2){
	socket = new Socket();
	board = new Board(bo,bA);
	playIndex = -1;

	outOfPlayPos.push_back(-3);
	outOfPlayPos.push_back(0);
	outOfPlayPos.push_back(1);

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
		LinearAnimation *a = new LinearAnimation(line,column,0);
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
		LinearAnimation *a = new LinearAnimation(line,column,0);
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

	playIndex++;
	oldPlays.push_back(socketString);
}

void Game::drawPieces(){
	for (std::map<std::string,BoardPiece*>::iterator it=pieces.begin(); it!=pieces.end(); ++it)
		it->second->draw();
	for(unsigned int i = 0; i < piecesOutOfPlay.size(); i++)
		piecesOutOfPlay[i]->draw();
}

void Game::undo(){
	if(playIndex < 0){
		return;
	}

	oldPlays.erase(oldPlays.begin()+playIndex);
	playIndex--;

	string pos1,pos2;
	int p1x,p1y,p2x,p2y;

	pos1 = lastPiecesKilled[lastPiecesKilled.size()-1];
	pos2 = piecesKilled[pos1];

	p1x = stoi(pos1);
	char c = pos1[3];
	p1y = c - '0';

	p2x = stoi(pos2);
	char c2 = pos2[3];
	p2y = c2 - '0';

	LinearAnimation* a = new LinearAnimation(p1x, p1y, 0);
	LinearAnimation* a2 = new LinearAnimation(p2x, p2y, 0);

	piecesOutOfPlay[piecesOutOfPlay.size()-1]->setAnimation(a2);
	pieceKilledPiece[pos2]->setAnimation(a);

	pieces[pos1] = pieces[pos2];
	pieces[pos2] = piecesOutOfPlay[piecesOutOfPlay.size()-1];

	piecesKilled.erase(pos1);
	pieceKilledPiece.erase(pos2);
	piecesOutOfPlay.erase(piecesOutOfPlay.begin() + piecesOutOfPlay.size() - 1);
	lastPiecesKilled.erase(lastPiecesKilled.begin() + lastPiecesKilled.size() - 1);

	if(currentplayer == PLAYER2)
		currentplayer = PLAYER1;
	else if(currentplayer == COMP1)
		currentplayer = COMP2;
	else if(currentplayer == PLAYER1 && type == 0)
		currentplayer = PLAYER2;
	else if(currentplayer == PLAYER1 && type == 1)
		currentplayer = COMP2;
	else if(currentplayer == COMP2 && type == 1)
		currentplayer = PLAYER1;
	else if(currentplayer == COMP2 && type == 2)
		currentplayer = COMP1;
}

void Game::movePiece(std::string p1, std::string p2){
	 
	selectedPiece.clear();

	std::vector<int> p1Position = pieces[p1]->getPosition();
	std::vector<int> p2Position = pieces[p2]->getPosition();

	//animation for piece1
	std::vector<Point> ctrlPoints = calculateControlPoints(p1Position, p2Position);
	LinearAnimation* a = new LinearAnimation("anim",2.0,ctrlPoints);

	//animation for piece2
	LinearAnimation* a2 = new LinearAnimation(outOfPlayPos[0],outOfPlayPos[1],outOfPlayPos[2]);

	outOfPlayPos[1]++;
	if(outOfPlayPos[1] > 8){
		outOfPlayPos[1] = 0;
		outOfPlayPos[0]-=2;
	}

	pieces[p2]->setAnimation(a2);
	piecesOutOfPlay.push_back(pieces[p2]);

	pieceKilledPiece[p2] = pieces[p1];
	piecesKilled[p1] = p2;
	lastPiecesKilled.push_back(p1);

	//replace
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

	newPlay[stringIndex] = player;
	oldPlays.push_back(newPlay);
	playIndex++;
	if(currentplayer == PLAYER2)
		currentplayer = PLAYER1;
	else if(currentplayer == COMP1)
		currentplayer = COMP2;
	else if(currentplayer == PLAYER1 && type == 0)
		currentplayer = PLAYER2;
	else if(currentplayer == PLAYER1 && type == 1)
		currentplayer = COMP2;
	else if(currentplayer == COMP2 && type == 1)
		currentplayer = PLAYER1;
	else if(currentplayer == COMP2 && type == 2)
		currentplayer = COMP1;
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
	stringstream e;
	if(selectedPiece.size() > 0){

		if(currentplayer == PLAYER1) {
			e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'P').\n";
			string env = e.str();
			socket->envia(env,env.size() );
			char ans[6];
			socket->recebe(ans);

			if(strcmp(ans,"'N'.\r") == 0 ) {
				cout << "Tem de escolher uma peca do oponente"<< endl;
				return;
			}
			int direction = GetDirectionInt(selectedPiece, s);
			if(!StringContains(possiblemoves,direction)){
				cout << "Nao pode mover a peça nessa direcao!\n";
				return;
			}
			std::string dest = GetDestination(selectedPiece, direction, range);
			if(s != dest){
				cout << "A peca so se pode mover "<< range << " casas!\n";
				return;
			}
		}
		else if(currentplayer == PLAYER2) {
			e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'B').\n";
			string env = e.str();
			socket->envia(env,env.size() );
			char ans[6];
			socket->recebe(ans);
			if(strcmp(ans,"'N'.\r") == 0 ) {
				cout << "Tem de escolher uma peca do oponente"<< endl;
				return;
			}
			int direction = GetDirectionInt(selectedPiece, s);
			if(!StringContains(possiblemoves,direction)){
				cout << "Nao pode mover a peça nessa direcao!\n";
				return;
			}
			std::string dest = GetDestination(selectedPiece, direction, range);
			if(s != dest){
				cout << "A peca só se pode mover "<< range << " casas!\n";
				return;
			}
		}
		e.str(std::string());
		movePiece(selectedPiece, s);
	}
	else {
		if(currentplayer == PLAYER1) {
			e.str(std::string());
			e << "gocheck("<< oldPlays[playIndex]<< "," <<1<< "," <<5<< ",'B','P').\n";
			string env = e.str();
			env = e.str();
			socket->envia(env,env.size() );
			char ans4[6];
			socket->recebe(ans4);
			if(strcmp(ans4,"'N'.\r") == 0 ) {
				cout << "GameOver"<< endl;
				socket->quit();
				return;
			}
			e.str(std::string());
			e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'B').\n";
			env = e.str();
			socket->envia(env,env.size() );
			char ans[6];
			socket->recebe(ans);

			if(strcmp(ans,"'N'.\r") == 0 ) {
				cout << "Tem de escolher uma das suas pecas"<< endl;
				return;
			}
			e.str(std::string());
			e << "movespossible("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'B','P').\n";
			env = e.str();
			socket->envia(env,env.size() );
			char ans2[50];
			socket->recebe(ans2);
			possiblemoves = string(ans2);
			if(possiblemoves.size() < 5){
				cout << "Essa peca nao tem jogadas possiveis!\n";
				return;
			}
			e.str(std::string());
			e << "range("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'B').\n";
			env = e.str();
			socket->envia(env,env.size() );
			char ans3[4];
			socket->recebe(ans3);
			range = atoi(ans3);
			
		}


		else if(currentplayer == PLAYER2) {

			e.str(std::string());
			e << "gocheck("<< oldPlays[playIndex]<< "," <<1<< "," <<5<< ",'P','B').\n";
			string env = e.str();
			env = e.str();
			socket->envia(env,env.size() );
			char ans4[6];
			socket->recebe(ans4);
			if(strcmp(ans4,"'N'.\r") == 0 ) {
				cout << "GameOver"<< endl;
				socket->quit();
				return;
			}
			e.str(std::string());
			e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'P').\n";
			env = e.str();
			socket->envia(env,env.size() );
			char ans[6];
			socket->recebe(ans);
			if(strcmp(ans,"'N'.\r") == 0 ) {
				cout << "Tem de escolher uma das suas pecas"<< endl;
				return;
			}
			e.str(std::string());
			e << "movespossible("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'P','B').\n";
			env = e.str();
			socket->envia(env,env.size() );
			char ans2[50];
			socket->recebe(ans2);
			possiblemoves = string(ans2);
			if(possiblemoves.size() < 5){
				cout << "Essa peca nao tem jogadas possiveis!\n";
				return;
			}
			e.str(std::string());
			e << "range("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'P').\n";
			env = e.str();
			socket->envia(env,env.size() );
			char ans3[4];
			socket->recebe(ans3);
			range = atoi(ans3);

		}

		selectedPiece = s;

	}
}
void Game::computerPlay(){
	int x,y;
	std::string env;
	srand(time(NULL));
	x = rand() % 17;
	srand(time(NULL));
	y = rand() % 9;
	
	stringstream e;
	if(currentplayer == COMP1) {
		e.str(std::string());		
		e << "gocheck("<< oldPlays[playIndex]<< "," <<1<< "," <<5<< ",'B','P').\n";
		string env = e.str();
		env = e.str();
		socket->envia(env,env.size() );
		char ans4[6];
		socket->recebe(ans4);
		if(strcmp(ans4,"'N'.\r") == 0 ) {
			cout << "GameOver"<< endl;
			socket->quit();
			return;
		}
		e.str(std::string());
		e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'B').\n";
		env = e.str();
		socket->envia(env,env.size() );
		char ans[6];
		socket->recebe(ans);

		e.str(std::string());
		e << "movespossible("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'B','P').\n";
		env = e.str();
		socket->envia(env,env.size() );
		char ans2[50];
		socket->recebe(ans2);
		possiblemoves = string(ans2);

		while(strcmp(ans,"'N'.\r") == 0 || possiblemoves.size()<5){
			cout << "Generating possible computer move" << endl;
			srand(time(NULL));
			x = rand() % 17;
			srand(time(NULL));
			y = rand() % 9;

			e.str(std::string());
			e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'B').\n";
			env = e.str();
			socket->envia(env,env.size() );
			socket->recebe(ans);

			e.str(std::string());
			e << "movespossible("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'B','P').\n";
			env = e.str();
			socket->envia(env,env.size() );
			socket->recebe(ans2);
			possiblemoves = string(ans2);
		}
		selectPiece(x,y);

		e.str(std::string());
		e << "range("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'B').\n";
		env = e.str();
		socket->envia(env,env.size() );
		char ans3[4];
		socket->recebe(ans3);
		range = atoi(ans3);

		srand(time(NULL));
		int dir = rand() % 6 + 1;

		while(!StringContains(possiblemoves,dir)){
			srand(time(NULL));
			dir = rand() % 6 + 1;
		}
		stringstream ss;
		ss << x << ',';
		if(x < 10)
			ss << ' ' << y;
		else
			ss << y;
		std::string d = ss.str();
		std::string dest = GetDestination(d,dir,range);
		std::vector<int> destPosition = pieces[dest]->getPosition();
		selectPiece(destPosition[0],destPosition[1]);
	}

	else if(currentplayer == COMP2) {
		e.str(std::string());
		e << "gocheck("<< oldPlays[playIndex]<< "," <<1<< "," <<5<< ",'P','B').\n";
		string env = e.str();
		env = e.str();
		socket->envia(env,env.size() );
		char ans4[6];
		socket->recebe(ans4);
		if(strcmp(ans4,"'N'.\r") == 0 ) {
			cout << "GameOver"<< endl;
			socket->quit();
			return;
		}
		e.str(std::string());
		e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'P').\n";
		env = e.str();
		socket->envia(env,env.size() );
		char ans[6];
		socket->recebe(ans);

		e.str(std::string());
		e << "movespossible("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'P','B').\n";
		env = e.str();
		socket->envia(env,env.size() );
		char ans2[50];
		socket->recebe(ans2);
		possiblemoves = string(ans2);

		while(strcmp(ans,"'N'.\r") == 0 || possiblemoves.size()<5){
			srand(time(NULL));
			x = rand() % 17;
			srand(time(NULL));
			y = rand() % 9;

			e.str(std::string());
			e << "valida("<< oldPlays[playIndex]<< ", " <<x+1<< ", " <<y+1<< ", 'P').\n";
			env = e.str();
			socket->envia(env,env.size() );
			socket->recebe(ans);

			e.str(std::string());
			e << "movespossible("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'P','B').\n";
			env = e.str();
			socket->envia(env,env.size() );
			socket->recebe(ans2);
			possiblemoves = string(ans2);
		}
		selectPiece(x,y);

		e.str(std::string());
		e << "range("<< oldPlays[playIndex]<< "," <<x+1<< "," <<y+1<< ",'P').\n";
		env = e.str();
		socket->envia(env,env.size() );
		char ans3[4];
		socket->recebe(ans3);
		range = atoi(ans3);

		srand(time(NULL));
		int dir = rand() % 6 + 1;

		while(!StringContains(possiblemoves,dir)){
			srand(time(NULL));
			dir = rand() % 6 + 1;
		}
		stringstream ss;
		ss << x << ',';
		if(x < 10)
			ss << ' ' << y;
		else
			ss << y;
		std::string d = ss.str();
		std::string dest = GetDestination(d,dir,range);
		std::vector<int> destPosition = pieces[dest]->getPosition();
		selectPiece(destPosition[0],destPosition[1]);
	}
}
void Game::updateAnims(unsigned long t){
	for (std::map<std::string,BoardPiece*>::iterator it=pieces.begin(); it!=pieces.end(); ++it)
		it->second->updateAnimation(t);
}
void Game::setDiff(int diff) {
	difficulty = diff;
}
void Game::setType(int type) {
	this->type = type;



	if(type == 0){
		if(currentplayer == COMP1)
			currentplayer = PLAYER1;
		else if(currentplayer == COMP2)
			currentplayer = PLAYER2;
		else
			currentplayer = PLAYER1;
	}
	else if(type == 1){
		if(currentplayer == COMP1)
			currentplayer = PLAYER1;
		else if(currentplayer == PLAYER2)
			currentplayer = COMP2;
		else
			currentplayer = PLAYER1;
	}
	else if(type == 2){
		if(currentplayer == PLAYER1)
			currentplayer = COMP1;
		else if(currentplayer == PLAYER2)
			currentplayer = COMP2;
		else
			currentplayer = COMP1;
	}
}