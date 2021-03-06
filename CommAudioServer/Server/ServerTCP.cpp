#include "ServerTCP.h"

/*------------------------------------------------------------------------------------------------------------------
-- FUNCTION:	InitializeSocket
--
-- DATE:		Febuary 28th, 2016		REVISIONS:
--
-- DESIGNER:	Ruoqi Jia				PROGRAMMER:	Ruoqi Jia
--
-- INTERFACE:	virtual int InitializeSocket(short port) = 0;
--						~port: port number of peer host
--
-- RETURNS: void
--
-- NOTES: Initialize socket, server address to lookup to, and connect to the server
--------------------------------------------------------------------------------------------------------------------*/
bool ServerTCP::InitializeSocket(short port)
{
    // Create a WSA v2.2 session
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        printf("WSAStartup failed with error %d\n", WSAGetLastError());
        return false;
    }

    // Create socket for listening
    if ((SocketInfo.Socket = socket(AF_INET,SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
    {
        printf("WSASocket() failed with error %d\n", WSAGetLastError());
        return false;
    }

    // Initialize address structure
    LocalAddr.sin_family = AF_INET;
    LocalAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    LocalAddr.sin_port = htons(DEFAULT_PORT);

    // Bind address to the listening socket
    if (bind(SocketInfo.Socket, (PSOCKADDR)&LocalAddr, sizeof(LocalAddr)) == SOCKET_ERROR)
    {
        printf("bind() failed with error %d\n", WSAGetLastError());
        return false;
    }

    // listens for only 1 connection
    if (listen(SocketInfo.Socket, MAX_CLIENTS) == SOCKET_ERROR)
    {
        printf("listen() failed with error %d\n", WSAGetLastError());
        return false;
    }
    return true;
}

bool ServerTCP::Accept(void)
{

}



bool ServerTCP::Broadcast(char *message, LPDWORD lpNumberOfBytesSent)
{
    return true;
}

void ServerTCP::Send(LPSOCKET_INFORMATION SockInfo, char * message)
{

}

void ServerTCP::RoutineManager(DWORD Error, DWORD BytesTransferred, LPWSAOVERLAPPED Overlapped, DWORD InFlags)
{

}
