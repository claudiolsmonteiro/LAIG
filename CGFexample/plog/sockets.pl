%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%                 Sockets                   %%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

:-use_module(library(sockets)).

port(60070).

% launch me in sockets mode
server:-
	port(Port),
	socket_server_open(Port, Socket),
	socket_server_accept(Socket, _Client, Stream, [type(text)]),
	write('Accepted connection'), nl,
	serverLoop(Stream),
	socket_server_close(Socket).

% wait for commands
serverLoop(Stream) :-
	repeat,
	read(Stream, ClientMsg),
	write('Received: '), write(ClientMsg), nl,
	parse_input(ClientMsg, MyReply),
	format(Stream, '~q.~n', [MyReply]),
	write('Wrote: '), write(MyReply), nl,
	flush_output(Stream),
	(ClientMsg == quit; ClientMsg == end_of_file), !.


parse_input(valida(Arg1, Arg2, Arg3, Arg4), Answer) :-
	valida(Arg1, Arg2,Arg3,Arg4, Answer).

parse_input(movespossible(Arg1,Arg2,Arg3,Arg4,Arg5),Answer):-
	movespossible(Arg1,Arg2,Arg3,Arg4,Arg5,Answer).
	
parse_input(gocheck(Arg1,Arg2,Arg3,Arg4,Arg5),Answer):-
	gocheck(Arg1,Arg2,Arg3,Arg4,Arg5,Answer).	
	
parse_input(range(Arg1,Arg2,Arg3,Arg4),Answer):-
	range(Arg1,Arg2,Arg3,Arg4,Answer).
	
parse_input(quit, ok-bye) :- !.

%verifica se uma peca existe naquele x,y
valida(Arg1, Arg2,Arg3,Arg4, Answer) :-
	validaPos(Arg1,Arg2,Arg3,Arg4),!,
	Answer = 'Y'.
	
valida(Arg1, Arg2,Arg3,Arg4, Answer) :-
	Answer = 'N'.

%lista de jogadas possiveis para dada posicao	
movespossible(Arg1,Arg2,Arg3,Arg4,Arg5,Answer):-
	validMoves(Arg1,Arg2,Arg3,Arg4,Arg5,Return5),
	reverseL(Return5, Answer, []).

range(Arg1,Arg2,Arg3,Arg4,Answer):-
	getRange(Arg1,Arg2,Arg3,Arg4,Answer).
	
%verifica o gameover
gocheck(Arg1,Arg2,Arg3,Arg4,Arg5,Answer):-
	allMovesPossible(Arg1,Arg2,Arg3,Arg4,Arg5,[],[]),!,
	Answer = 'N'.
gocheck(Arg1,Arg2,Arg3,Arg4,Arg5,Answer):-
	Answer = 'Y'.		
	
