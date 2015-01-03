
%tabuleiro vazio
tabuleiroLetra([['  ', '0','1','2','3','4','5','6','7','8'],
				[' 0', ' ',' ',' ',' ','E',' ',' ',' ',' '],
				[' 1', ' ',' ',' ','E',' ','E',' ',' ',' '], 
				[' 2', ' ',' ','E',' ','E',' ','E',' ',' '], 
				[' 3', ' ','E',' ','E',' ','E',' ','E',' '],
				[' 4', 'E',' ','E',' ','E',' ','E',' ','E'], 
				[' 5', ' ','E',' ','E',' ','E',' ','E',' '], 
				[' 6', 'E',' ','E',' ','E',' ','E',' ','E'], 
				[' 7', ' ','E',' ','E',' ','E',' ','E',' '], 
				[' 8', 'E',' ','E',' ','E',' ','E',' ','E'], 
				[' 9', ' ','E',' ','E',' ','E',' ','E',' '], 
				['10', 'E',' ','E',' ','E',' ','E',' ','E'], 
				['11', ' ','E',' ','E',' ','E',' ','E',' '], 
				['12', 'E',' ','E',' ','E',' ','E',' ','E'], 
				['13', ' ','E',' ','E',' ','E',' ','E',' '], 
				['14', ' ',' ','E',' ','E',' ','E',' ',' '], 
				['15', ' ',' ',' ','E',' ','E',' ',' ',' '], 
				['16', ' ',' ',' ',' ','E',' ',' ',' ',' ']]).

%tabuleiro pre-definido		   
tabuleiroPF([	['  ','0','1','2','3','4','5','6','7','8'],
				[' 0',' ',' ',' ',' ','B',' ',' ',' ',' '],
				[' 1',' ',' ',' ','P',' ','B',' ',' ',' '], 
				[' 2',' ',' ','P',' ','P',' ','P',' ',' '], 
				[' 3',' ','B',' ','B',' ','B',' ','B',' '],
				[' 4','P',' ','P',' ','B',' ','B',' ','B'], 
				[' 5',' ','P',' ','P',' ','P',' ','P',' '], 
				[' 6','B',' ','B',' ','B',' ','P',' ','P'], 
				[' 7',' ','P',' ','B',' ','B',' ','P',' '], 
				[' 8','B',' ','P',' ','P',' ','P',' ','B'], 
				[' 9',' ','P',' ','B',' ','P',' ','B',' '], 
				['10','P',' ','B',' ','B',' ','B',' ','P'], 
				['11',' ','P',' ','P',' ','B',' ','P',' '], 
				['12','B',' ','B',' ','P',' ','P',' ','E'], 
				['13',' ','B',' ','B',' ','B',' ','B',' '], 
				['14',' ',' ','P',' ','P',' ','P',' ',' '], 
				['15',' ',' ',' ','B',' ','B',' ',' ',' '], 
				['16',' ',' ',' ',' ','P',' ',' ',' ',' ']]).

%possivel estado final utlizado para testes		
tabuleiroFinal([['  ','0','1','2','3','4','5','6','7','8'],
                [' 0',' ',' ',' ',' ','B',' ',' ',' ',' '],
                [' 1',' ',' ',' ','E',' ','E',' ',' ',' '], 
                [' 2',' ',' ','E',' ','B',' ','E',' ',' '], 
                [' 3',' ','E',' ','E',' ','E',' ','E',' '],
                [' 4','E',' ','B',' ','E',' ','E',' ','B'], 
                [' 5',' ','P',' ','E',' ','B',' ','E',' '], 
                [' 6','E',' ','E',' ','E',' ','P',' ','E'], 
                [' 7',' ','E',' ','E',' ','P',' ','P',' '], 
                [' 8','E',' ','E',' ','E',' ','E',' ','E'], 
                [' 9',' ','P',' ','E',' ','E',' ','B',' '], 
                ['10','E',' ','E',' ','P',' ','P',' ','E'], 
                ['11',' ','E',' ','E',' ','E',' ','E',' '], 
                ['12','E',' ','E',' ','B',' ','E',' ','E'], 
                ['13',' ','B',' ','P',' ','E',' ','B',' '], 
                ['14',' ',' ','E',' ','E',' ','E',' ',' '], 
                ['15',' ',' ',' ','E',' ','E',' ',' ',' '], 
                ['16',' ',' ',' ',' ','E',' ',' ',' ',' ']]).

%tabuleiro de teste				
tabuleiroTeste([['  ','0','1','2','3','4','5','6','7','8'],
                [' 0',' ',' ',' ',' ','B',' ',' ',' ',' '],
                [' 1',' ',' ',' ','E',' ','E',' ',' ',' '], 
                [' 2',' ',' ','E',' ','B',' ','E',' ',' '], 
                [' 3',' ','E',' ','E',' ','E',' ','E',' '],
                [' 4','E',' ','B',' ','E',' ','E',' ','B'], 
                [' 5',' ','P',' ','B',' ','B',' ','E',' '], 
                [' 6','E',' ','E',' ','E',' ','P',' ','E'], 
                [' 7',' ','E',' ','E',' ','P',' ','P',' '], 
                [' 8','E',' ','E',' ','E',' ','E',' ','E'], 
                [' 9',' ','P',' ','E',' ','E',' ','B',' '], 
                ['10','E',' ','E',' ','P',' ','P',' ','E'], 
                ['11',' ','E',' ','B',' ','E',' ','P',' '], 
                ['12','E',' ','E',' ','B',' ','E',' ','E'], 
                ['13',' ','B',' ','P',' ','P',' ','B',' '], 
                ['14',' ',' ','B',' ','E',' ','P',' ',' '], 
                ['15',' ',' ',' ','E',' ','E',' ',' ',' '], 
                ['16',' ',' ',' ',' ','E',' ',' ',' ',' ']]).

%funcoes para imprimir o tabuleiro(lista de listas)		   
printBoards([]).
printBoards([FirstList|OtherLists]) :-
printBoard(FirstList),
printBoards(OtherLists).

printBoard([]) :- nl.
printBoard([FirstElem|OtherElems]) :-
write(FirstElem),write(' '),
printBoard(OtherElems).

% funcao que verifica se uma peca C existe para um dado X,Y no tabuleiro
validaPos(Tab, X, Y, C):-
	elemento(Tab, X, Pos),
	nth0(Y, Pos, C).

	
/******************************
**           Jogar           **
*******************************/

%funcao que retorna a lista de direcoes validas para uma dada peca
validMoves(Tabuleiro,X,Y,C,D,Return5):-
        getRange(Tabuleiro,X,Y,C,Range),
        Range1 is Range*2,
        Xn is X-Range1,
        Xbf is X-Range,
        Xs is X+Range1,
        Xaf is X+Range,
        Ye is Y+Range,
        Yw is Y-Range,
        (validaPos(Tabuleiro, Xn, Y, D)->addValue([1],[],Return);Return = []), %checkNorth
        (validaPos(Tabuleiro, Xbf, Ye, D)->addValue([2],Return,Return1);Return1 = Return), %checkNorthEast
        (validaPos(Tabuleiro, Xbf, Yw, D)->addValue([3],Return1,Return2);Return2 = Return1), %checkNorthWest
        (validaPos(Tabuleiro, Xs, Y, D)->addValue([4],Return2,Return3 );Return3 = Return2), %checkSouth
        (validaPos(Tabuleiro, Xaf, Ye, D)->addValue([5],Return3, Return4);Return4 = Return3), %checkSouthEast
        (validaPos(Tabuleiro, Xaf, Yw, D)->addValue([6],Return4,Return5);Return5 = Return4). %checkSouthEast.

%funcao utilizada para adicionar um valor a cabeca de uma lista
addValue(Value, List, Return):-
        List1 = [Value|List],
        Return = List1.
	
%Move a peca C para Norte caso seja possivel
validMovement(Tabuleiro, X, Y, C, D, Range, 1, NovoTabuleiro1):-
	Range1 is Range*2,
	Xn is X-Range1,
	(validaPos(Tabuleiro, Xn, Y, D)->replace(Tabuleiro, Xn ,Y ,C ,NovoTabuleiro),	
									replace(NovoTabuleiro, X ,Y ,'E' ,NovoTabuleiro1);
		write('Jogava invalida.'), nl,
		write('Em que direcao deseja mover a peca selecionada?'), nl,
		write('1- Norte'), nl,
		write('2- Nordeste'), nl,
		write('3- Noroeste'), nl,
		write('4- Sul'), nl,
		write('5- Sudeste'), nl,
		write('6- Sudoeste'), nl,
		read(Option),
		validMovement(Tabuleiro, X, Y, C, D, Range, Option, NovoTabuleiro1)).

%Move a peca C para Nordeste caso seja possivel		
validMovement(Tabuleiro, X, Y, C, D, Range, 2, NovoTabuleiro1):-
	Xbf is X-Range,
	Ye is Y+Range,
	(validaPos(Tabuleiro, Xbf, Ye, D)->replace(Tabuleiro, Xbf, Ye, C,NovoTabuleiro),	
									replace(NovoTabuleiro, X ,Y ,'E' ,NovoTabuleiro1);
		write('Jogava invalida.'), nl,
		write('Em que direcao deseja mover a peca selecionada?'), nl,
		write('1- Norte'), nl,
		write('2- Nordeste'), nl,
		write('3- Noroeste'), nl,
		write('4- Sul'), nl,
		write('5- Sudeste'), nl,
		write('6- Sudoeste'), nl,
		read(Option),
		validMovement(Tabuleiro, X, Y, C, D, Range, Option, NovoTabuleiro1)).

%Move a peca C para Noroeste caso seja possivel		
validMovement(Tabuleiro, X, Y, C, D, Range, 3, NovoTabuleiro1):-
	Xbf is X-Range,
	Yw is Y-Range,
	(validaPos(Tabuleiro, Xbf, Yw, D)->replace(Tabuleiro, Xbf ,Yw ,C ,NovoTabuleiro),	
									replace(NovoTabuleiro, X ,Y ,'E' ,NovoTabuleiro1);
		write('Jogava invalida.'), nl,
		write('Em que direcao deseja mover a peca selecionada?'), nl,
		write('1- Norte'), nl,
		write('2- Nordeste'), nl,
		write('3- Noroeste'), nl,
		write('4- Sul'), nl,
		write('5- Sudeste'), nl,
		write('6- Sudoeste'), nl,
		read(Option),
		validMovement(Tabuleiro, X, Y, C, D, Range, Option, NovoTabuleiro1)).

%Move a peca C para Sul caso seja possivel		
validMovement(Tabuleiro, X, Y, C, D, Range, 4, NovoTabuleiro1):-
	Range1 is Range*2,
	Xs is X+Range1,
	(validaPos(Tabuleiro, Xs, Y, D)->replace(Tabuleiro, Xs ,Y ,C ,NovoTabuleiro),	
									replace(NovoTabuleiro, X ,Y ,'E' ,NovoTabuleiro1);
		write('Jogava invalida.'), nl,
		write('Em que direcao deseja mover a peca selecionada?'), nl,
		write('1- Norte'), nl,
		write('2- Nordeste'), nl,
		write('3- Noroeste'), nl,
		write('4- Sul'), nl,
		write('5- Sudeste'), nl,
		write('6- Sudoeste'), nl,
		read(Option),
		validMovement(Tabuleiro, X, Y, C, D, Range, Option, NovoTabuleiro1)).

%Move a peca C para Sudeste caso seja possivel		
validMovement(Tabuleiro, X, Y, C, D, Range, 5, NovoTabuleiro1):-
	Xaf is X+Range,
	Ye is Y+Range,
	(validaPos(Tabuleiro, Xaf, Ye, D)->replace(Tabuleiro, Xaf ,Ye ,C ,NovoTabuleiro),	
									replace(NovoTabuleiro, X ,Y ,'E' ,NovoTabuleiro1);
		write('Jogava invalida.'), nl,
		write('Em que direcao deseja mover a peca selecionada?'), nl,
		write('1- Norte'), nl,
		write('2- Nordeste'), nl,
		write('3- Noroeste'), nl,
		write('4- Sul'), nl,
		write('5- Sudeste'), nl,
		write('6- Sudoeste'), nl,
		read(Option),
		validMovement(Tabuleiro, X, Y, C, D, Range, Option, NovoTabuleiro1)).

%Move a peca C para Sudoeste caso seja possivel		
validMovement(Tabuleiro, X, Y, C, D, Range, 6, NovoTabuleiro1):-
	Xaf is X+Range,
	Yw is Y-Range,
	(validaPos(Tabuleiro, Xaf, Yw, D)->replace(Tabuleiro, Xaf ,Yw ,C ,NovoTabuleiro),	
									replace(NovoTabuleiro, X ,Y ,'E' ,NovoTabuleiro1);
		write('Jogava invalida.'), nl,
		write('Em que direcao deseja mover a peca selecionada?'), nl,
		write('1- Norte'), nl,
		write('2- Nordeste'), nl,
		write('3- Noroeste'), nl,
		write('4- Sul'), nl,
		write('5- Sudeste'), nl,
		write('6- Sudoeste'), nl,
		read(Option),
		validMovement(Tabuleiro, X, Y, C, D, Range, Option, NovoTabuleiro1)).

jogarComp1(Tabuleiro):-
	allMovesPossible(Tabuleiro, 1, 5,'B','P', [], []),
	!.		

%Funcao do computador 1, que gera uma jogada aleatoria que se for possivel e executada		
jogarComp1(Tabuleiro):-
	repeat,
	random(1,18,X),
	random(1,10,Y),
	validaPos(Tabuleiro, X, Y, 'B'),
	\+validMoves(Tabuleiro, X, Y, 'B', 'P', []),
	!,
	getRange(Tabuleiro, X, Y, 'B', Range),
	validMoves(Tabuleiro, X, Y, 'B', 'P', Directions),
	random_member(Direc, Directions),
	elemento(Direc, 0, Dir),
	validMovement(Tabuleiro, X, Y, 'B', 'P', Range, Dir, NovoTabuleiro).


jogarComp2(Tabuleiro):-
	allMovesPossible(Tabuleiro, 1, 5,'P','B', [], []),
	!.

%Funcao do computador 2, que gera uma jogada aleatoria que se for possivel e executada  
jogarComp2(Tabuleiro):-
	repeat,
	random(1,18,X),
	random(1,10,Y),
	validaPos(Tabuleiro, X, Y, 'P'),
	\+validMoves(Tabuleiro, X, Y, 'P', 'B', []),
	!,
	getRange(Tabuleiro, X, Y, 'P', Range),
	validMoves(Tabuleiro, X, Y, 'P', 'B', Directions),
	random_member(Direc, Directions),
	elemento(Direc, 0, Dir),
	validMovement(Tabuleiro, X, Y, 'P', 'B', Range, Dir, NovoTabuleiro).

%Retorna o numero de casas que uma peca C se pode mover		
getRange(Tabuleiro, X, Y, C, Range):-
	N is 0,
	Xn is X-2,
	Xbf is X-1,
	Xs is X+2,
	Xaf is X+1,
	Ye is Y+1,
	Yw is Y-1,
	(validaPos(Tabuleiro, Xn, Y, C)->N1 is N+1; N1 is N), %checkNorth
	(validaPos(Tabuleiro, Xbf, Ye, C)->N2 is N1+1; N2 is N1), %checkNorthEast
	(validaPos(Tabuleiro, Xbf, Yw, C)->N3 is N2+1; N3 is N2), %checkNorthWest
	(validaPos(Tabuleiro, Xs, Y, C)->N4 is N3+1; N4 is N3), %checkSouth
	(validaPos(Tabuleiro, Xaf, Ye, C)->N5 is N4+1; N5 is N4), %checkSouthEast
	(validaPos(Tabuleiro, Xaf, Yw, C)->N6 is N5+1; N6 is N5), %checkSouthEast.
	Range = N6.

%grupo de funcoes que gera a lista de todas as jogadas possiveis de um determinado jogador, usada para verficar o fim de jogo
allMovesPossible(Tabuleiro, 17, 5, 'B', 'P', ListOfMoves, ListOfAllMoves):-
        \+ validaPos(Tabuleiro, 17, 5, 'B'),
		ListOfAllMoves = ListOfMoves,
        !.

allMovesPossible(Tabuleiro, 17, 5, 'B', 'P', ListOfMoves, ListOfAllMoves):-
        validMoves(Tabuleiro, 17, 5, 'B', 'P',[]),
		ListOfAllMoves = ListOfMoves,
        !.

allMovesPossible(Tabuleiro, 17, 5, 'B', 'P', ListOfMoves, ListOfAllMoves):-
        validMoves(Tabuleiro, 17 ,5 , 'B', 'P',Return),
        addValue(Return, ListOfMoves, ListOfAllMoves),
		printBoards(ListOfAllMoves),
        !.
	
allMovesPossible(Tabuleiro, X, Y, 'B', 'P', ListOfMoves, ListOfAllMoves):-
        \+ validaPos(Tabuleiro, X, Y, 'B'),
        nextPosition(X, Y, NextX, NextY),
        !,
        allMovesPossible(Tabuleiro, NextX, NextY, 'B', 'P', ListOfMoves, ListOfAllMoves).

allMovesPossible(Tabuleiro, X, Y, 'B', 'P', ListOfMoves, ListOfAllMoves):-
        validMoves(Tabuleiro,X,Y,'B','P',[]),
        nextPosition(X, Y, NextX, NextY),
        !,
        allMovesPossible(Tabuleiro, NextX, NextY, 'B', 'P', ListOfMoves, ListOfAllMoves).

allMovesPossible(Tabuleiro, X, Y, 'B', 'P', ListOfMoves, ListOfAllMoves):-
        validMoves(Tabuleiro,X,Y,'B','P',Return),
        addValue(Return, ListOfMoves, ListOfMoves1),
        nextPosition(X, Y, NextX, NextY),
        !,
        allMovesPossible(Tabuleiro, NextX, NextY, 'B', 'P', ListOfMoves1, ListOfAllMoves).


allMovesPossible(Tabuleiro, 17, 5, 'P', 'B', ListOfMoves, ListOfAllMoves):-
        \+ validaPos(Tabuleiro, 17, 5, 'P'),
		ListOfAllMoves = ListOfMoves,
        !.

allMovesPossible(Tabuleiro, 17, 5, 'P', 'B', ListOfMoves, ListOfAllMoves):-
        validMoves(Tabuleiro, 17, 5, 'P', 'B',[]),
		ListOfAllMoves = ListOfMoves,
        !.

allMovesPossible(Tabuleiro, 17, 5, 'P', 'B', ListOfMoves, ListOfAllMoves):-
		validMoves(Tabuleiro, 17 ,5 , 'P', 'B',Return),
        addValue(Return, ListOfMoves, ListOfAllMoves),
		printBoards(ListOfAllMoves),
        !.
		
allMovesPossible(Tabuleiro, X, Y, 'P', 'B', ListOfMoves, ListOfAllMoves):-
        \+ validaPos(Tabuleiro, X, Y, 'P'),
        nextPosition(X, Y, NextX, NextY),
        !,
        allMovesPossible(Tabuleiro, NextX, NextY, 'P', 'B', ListOfMoves, ListOfAllMoves).

allMovesPossible(Tabuleiro, X, Y, 'P', 'B', ListOfMoves, ListOfAllMoves):-
        validMoves(Tabuleiro,X,Y,'P','B',[]),
        nextPosition(X, Y, NextX, NextY),
        !,
        allMovesPossible(Tabuleiro, NextX, NextY, 'P', 'B', ListOfMoves, ListOfAllMoves).

allMovesPossible(Tabuleiro, X, Y, 'P', 'B', ListOfMoves, ListOfAllMoves):-
        validMoves(Tabuleiro,X,Y,'P','B',Return),
        addValue(Return, ListOfMoves, ListOfMoves1),
        nextPosition(X, Y, NextX, NextY),
        !,
        allMovesPossible(Tabuleiro, NextX, NextY, 'P', 'B', ListOfMoves1, ListOfAllMoves).

%funcoes usadas para auxiliar a funcao allMovesPossible		
nextPosition(1, 5, X, Y):-
	X = 2,
	Y = 4.
	
nextPosition(2, 4, X, Y):-
	X = 2,
	Y = 6.
	
nextPosition(2, 6, X, Y):-
	X = 3,
	Y = 3.
	
nextPosition(3, 3, X, Y):-
	X = 3,
	Y = 5.
	
nextPosition(3, 5, X, Y):-
	X = 3,
	Y = 7.

nextPosition(3, 7, X, Y):-
	X = 4,
	Y = 2.
	
nextPosition(4, 2, X, Y):-
	X = 4,
	Y = 4.
	
nextPosition(4, 4, X, Y):-
	X = 4,
	Y = 6.
	
nextPosition(4, 6, X, Y):-
	X = 4,
	Y = 8.
	
nextPosition(4, 8, X, Y):-
	X = 5,
	Y = 1.
	
nextPosition(5, 1, X, Y):-
	X = 5,
	Y = 3.
		
nextPosition(5, 3, X, Y):-
	X = 5,
	Y = 5.
		
nextPosition(5, 5, X, Y):-
	X = 5,
	Y = 7.
		
nextPosition(5, 7, X, Y):-
	X = 5,
	Y = 9.
		
nextPosition(5, 9, X, Y):-
	X = 6,
	Y = 2.
			
nextPosition(6, 2, X, Y):-
	X = 6,
	Y = 4.
				
nextPosition(6, 4, X, Y):-
	X = 6,
	Y = 6.
				
nextPosition(6, 6, X, Y):-
	X = 6,
	Y = 8.
				
nextPosition(6, 8, X, Y):-
	X = 7,
	Y = 1.
					
nextPosition(7, 1, X, Y):-
	X = 7,
	Y = 3.
						
nextPosition(7, 3, X, Y):-
	X = 7,
	Y = 5.
						
nextPosition(7, 5, X, Y):-
	X = 7,
	Y = 7.
						
nextPosition(7, 7, X, Y):-
	X = 7,
	Y = 9.
						
nextPosition(7, 9, X, Y):-
	X = 8,
	Y = 2.
							
nextPosition(8, 2, X, Y):-
	X = 8,
	Y = 4.
								
nextPosition(8, 4, X, Y):-
	X = 8,
	Y = 6.
								
nextPosition(8, 6, X, Y):-
	X = 8,
	Y = 8.
							
nextPosition(8, 8, X, Y):-
	X = 9,
	Y = 1.	
								
nextPosition(9, 1, X, Y):-
	X = 9,
	Y = 3.
									
nextPosition(9, 3, X, Y):-
	X = 9,
	Y = 5.
										
nextPosition(9, 5, X, Y):-
	X = 9,
	Y = 7.
										
nextPosition(9, 7, X, Y):-
	X = 9,
	Y = 9.
										
nextPosition(9, 9, X, Y):-
	X = 10,
	Y = 2.
										
nextPosition(10, 2, X, Y):-
	X = 10,
	Y = 4.
											
nextPosition(10, 4, X, Y):-
	X = 10,
	Y = 6.
											
nextPosition(10, 6, X, Y):-
	X = 10,
	Y = 8.
											
nextPosition(10, 8, X, Y):-
	X = 11,
	Y = 1.
	
nextPosition(11, 1, X, Y):-
	X = 11,
	Y = 3.
		
nextPosition(11, 3, X, Y):-
	X = 11,
	Y = 5.
		
nextPosition(11, 5, X, Y):-
	X = 11,
	Y = 7.
		
nextPosition(11, 7, X, Y):-
	X = 11,
	Y = 9.
		
nextPosition(11, 9, X, Y):-
	X = 12,
	Y = 2.
		
nextPosition(12, 2, X, Y):-
	X = 12,
	Y = 4.
			
nextPosition(12, 4, X, Y):-
	X = 12,
	Y = 6.
			
nextPosition(12, 6, X, Y):-
	X = 12,
	Y = 8.
			
nextPosition(12, 8, X, Y):-
	X = 13,
	Y = 1.
			
nextPosition(13, 1, X, Y):-
	X = 13,
	Y = 3.
			
nextPosition(13, 3, X, Y):-
	X = 13,
	Y = 5.
				
nextPosition(13, 5, X, Y):-
	X = 13,
	Y = 7.
				
nextPosition(13, 7, X, Y):-
	X = 13,
	Y = 9.
				
nextPosition(13, 9, X, Y):-
	X = 14,
	Y = 2.
				
nextPosition(14, 2, X, Y):-
	X = 14,
	Y = 4.
				
nextPosition(14, 4, X, Y):-
	X = 14,
	Y = 6.
					
nextPosition(14, 6, X, Y):-
	X = 14,
	Y = 8.
					
nextPosition(14, 8, X, Y):-
	X = 15,
	Y = 3.
					
nextPosition(15, 3, X, Y):-
	X = 15,
	Y = 5.
						
nextPosition(15, 5, X, Y):-
	X = 15,
	Y = 7.
						
nextPosition(15, 7, X, Y):-
	X = 16,
	Y = 4.
						
nextPosition(16, 4, X, Y):-
	X = 16,
	Y = 6.
						
nextPosition(16, 6, X, Y):-
	X = 17,
	Y = 5.
%funcao de gameover do jogador 1
gameOver('B',Tabuleiro):-
	printBoards(Tabuleiro),nl,
	write('O Jogador 1 nao tem mais jogadas possiveis.'),nl,
	write('*****************************'),nl,
	write('* O Jogador 2 venceu o jogo *'),nl,
	write('*****************************'),nl,
	write('Deseja comecar um novo jogo?'),nl,
	write('1- sim'),nl,
	write('2- nao'),nl,
	repeat, read(Opcao), Opcao >= 1, Opcao =< 2,!,
	newGame(Opcao).

%funcao de gameover do jogador 2	
gameOver('P',Tabuleiro):-
	printBoards(Tabuleiro),nl,
	write('O Jogador 2 nao tem mais jogadas possiveis.'),nl,
	write('*****************************'),nl,
	write('* O Jogador 1 venceu o jogo *'),nl,
	write('*****************************'),nl,
	repeat,
	write('Deseja comecar um novo jogo?'),nl,
	write('1- sim'),nl,
	write('2- nao'),nl,
	repeat, read(Opcao), Opcao >= 1, Opcao =< 2,!,
	newGame(Opcao).	

newGame(1):-
	start.
	
newGame(2):-
	abort.
/******************************
**          Start            **
*******************************/

start:-
        tabuleiroLetra(Tabuleiro),
        displayMenu(0,Tabuleiro).		
	
/******************************
**    Auxiliar Functions     **
*******************************/
	

%funcao que retorna o elemento de uma lista numa dada posicao
elemento([Lista|_], 0, Lista).
elemento([_|Tail], Linha, Lista):-
	Linha > -1,
	ProximaLinha is Linha-1,
	elemento(Tail, ProximaLinha, Lista),
	!.

%funcao que inverte uma lista
reverseL([],Z,Z).

reverseL([H|T], Z, R):-
        reverseL(T,Z,[H|R]).


replace( [L|Ls] , 0 , Y , Z , [R|Ls] ) :- % once we find the desired row,
  replace_column(L,Y,Z,R).                % - we replace specified column, and we're done.

replace( [L|Ls] , X , Y , Z , [L|Rs] ) :- % if we haven't found the desired row yet
  X > 0 ,                                 % - and the row offset is positive,
  X1 is X-1 ,                             % - we decrement the row offset
  replace( Ls , X1 , Y , Z , Rs ).         % - and recurse down

replace_column( [_|Cs] , 0 , Z , [Z|Cs] ) .  % once we find the specified offset, just make the substitution and finish up.
replace_column( [C|Cs] , Y , Z , [C|Rs] ) :- % otherwise,
  Y > 0 ,                                    % - assuming that the column offset is positive,
  Y1 is Y-1 ,                                % - we decrement it
  replace_column( Cs , Y1 , Z , Rs ).         % - and recurse down.