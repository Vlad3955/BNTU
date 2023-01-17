#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string.h>



#define PORT 79
#define SERVERADDR "127.0.0.1"
#define CRLF "\r\n"
#define ALL "\\all"
#define ECHO "foobar"
#pragma comment(lib,"ws2_32.lib")

int main(int argc, char* argv[])
{
	char buff[1024];
	//printf("FINGER TCP CLIENT\n");

	// Шаг 1 - инициализация библиотеки Winsock
	if (WSAStartup(0x202, (WSADATA*)&buff[0]))
	{
		printf("WSAStart error %d\n", WSAGetLastError());
		return -1;
	}

	// Шаг 2 - создание сокета
	SOCKET my_sock;
	my_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (my_sock < 0)
	{
		printf("Socket() error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	// Шаг 3 - установка соединения

	// заполнение структуры sockaddr_in
	// указание адреса и порта сервера
	sockaddr_in dest_addr;
	dest_addr.sin_family = AF_INET;
	dest_addr.sin_port = htons(PORT);
	dest_addr.sin_addr.s_addr = inet_addr(SERVERADDR);
	HOSTENT* hst;

	// адрес сервера получен – пытаемся установить соединение 
	if (connect(my_sock, (sockaddr*)&dest_addr, sizeof(dest_addr)))
	{
		printf("Connect error %d\n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	recv(my_sock, buff, sizeof(buff), 0);
	printf(buff);


	scanf("%s", buff);
	if (strcmp(buff, ALL) == 0)
	{
		send(my_sock, CRLF, sizeof(CRLF), 0);
	}
	else
	{
		strcat(buff, CRLF);
		send(my_sock, buff, strlen(buff), 0);
	}

	while (recv(my_sock, buff, sizeof(buff), 0))
	{
		printf(buff);
		send(my_sock, ECHO, sizeof(ECHO), 0);
	}

	printf("Server closed the connection. Press any key to exit.\n", WSAGetLastError());
	system("pause");
	closesocket(my_sock);
	WSACleanup();
	return 1;
}