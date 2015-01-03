:- use_module(library(lists)),
	use_module(library(random)),
	use_module(library(sockets)),
	consult('Quantum_Leap3'),
	consult('sockets').

user:runtime_entry(start):-
	server.