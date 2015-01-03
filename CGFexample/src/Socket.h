#ifndef socket_H
#define socket_H

#include <winsock2.h>
#include <iostream>
#include <string>
#define IPADDRESS "127.0.0.1"
#define PORT 60070

using namespace std;





class Socket{
protected:
	SOCKET m_socket;
	public:
		Socket();
		void envia(string s, int len);
		void recebe(char *ans);
		void quit();
		~Socket();

};

#endif