#include "socket.h"

Socket::Socket() {// Initialize Winsock.
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != NO_ERROR)
		printf("Client: Error at WSAStartup().\n");
    else
        printf("Client: WSAStartup() is OK.\n");

	// Create a socket.
    m_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_socket == INVALID_SOCKET) {
        printf("Client: socket() - Error at socket(): %ld\n", WSAGetLastError());
        WSACleanup();
        throw exception();
    }
	else
       printf("Client: socket() is OK.\n");

    // Connect to a server.
    sockaddr_in clientService;
    clientService.sin_family = AF_INET;
    // Just test using the localhost, you can try other IP address
    clientService.sin_addr.s_addr = inet_addr(IPADDRESS);
    clientService.sin_port = htons(PORT);

    if (connect(m_socket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) {
        printf("Client: connect() - Failed to connect.\n");
        WSACleanup();
        throw exception();
    }
    else {
       printf("Client: connect() is OK.\n");
       printf("Client: Can start sending and receiving data...\n");
    }

    // Send and receive data.
	printf("Connected\n");
}

void Socket::envia(string s, int len) {
	s += ".\n";
	const char* env = s.c_str();
	int bytesSent = send(m_socket, env, len, 0);
	if(bytesSent == SOCKET_ERROR)
		printf("Client: send() error %ld.\n", WSAGetLastError());
}

void Socket::recebe(char *ans) {
	int bytesRecv = SOCKET_ERROR;
	int pos = 0;
	while (true) {
		recv(m_socket, &ans[pos], 1, 0);
		if (ans[pos] == '\n')
			break;
		pos++;
	}
	ans[pos] = 0;
}

void Socket::quit() {
	cout << "Asking prolog to quit" << endl;
	char buff[] = "quit.\n";
	envia(buff, 6);
	char ans[128];
	recebe(ans);
}
Socket::~Socket(){
	quit();
};
/*
int main() {
	socketConnect();
	char *s = "comando(1, 2).\n";
	envia(s, strlen(s));
	char ans[128];
	recebe(ans);
	quit();
	getchar();
	return 0;
}*/