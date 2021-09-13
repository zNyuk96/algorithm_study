#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winSock2.h>
#define _USE_MATH_DEFINES

#pragma warning(disable : 4996)
#pragma comment(lib, "ws2_32.lib")

// �г����� ����ڿ� �°� ������ �ּ���.
#define NICKNAME "GUMI03_C"

// ��Ÿ���� ���α׷��� ���ÿ��� ������ ��� �������� �ʽ��ϴ�.
#define HOST "127.0.0.1"

// ��Ÿ���� ���α׷��� ����� �� ����ϴ� �ڵ尪���� �������� �ʽ��ϴ�.
#define PORT 1447
#define CODE_SEND 9901

void ErrorHandling(const char* message);

int main()
{
	WSADATA wsaData;
	SOCKET hSocket;
	SOCKADDR_IN sockAddr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup failure.");

	hSocket = socket(PF_INET, SOCK_STREAM, 0);

	if (hSocket == INVALID_SOCKET)
		ErrorHandling("Socket Creating Failure.");

	memset(&sockAddr, 0, sizeof(sockAddr));
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.s_addr = inet_addr(HOST);
	sockAddr.sin_port = htons(PORT);

	printf("Trying Connect: %s:%d\n", HOST, PORT);
	if (connect(hSocket, (SOCKADDR*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR)
		ErrorHandling("Connection Failure.");
	else
		printf("Connected: %s:%d\n", HOST, PORT);

	char sendData[50];

	sprintf(sendData, "%d/%s/", CODE_SEND, NICKNAME);
	send(hSocket, (char*)&sendData, sizeof(sendData), 0);
	printf("Ready to play!\n--------------------");

	closesocket(hSocket);
	WSACleanup();

	return 0;
}

void ErrorHandling(const char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}