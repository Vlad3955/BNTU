#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <string.h>
using namespace std;
#pragma comment(lib,"ws2_32.lib")

#define FINGER_PORT    79 // Порт, который слушает сервер


// макрос для печати количества активных
// пользователей 
#define PRINTNUSERS if (nclients)\
  printf("%d users\n",nclients);\
  else printf("No users\n");

							   // прототип функции, обслуживающий
							   // подключившихся пользователей
DWORD WINAPI WorkWithClient(LPVOID client_socket);


// глобальная переменная – количество
// активных пользователей 
int nclients = 0;

int main(int argc, char* argv[])
{
	char buff[1024];    // Буфер для различных нужд

	printf("Starting up server...\n");

	// Шаг 1 - Инициализация Библиотеки Сокетов
	if (WSAStartup(0x0202, (WSADATA*)&buff[0]))
	{
		// Ошибка!
		printf("Error during WSAStartup %d\n",
			WSAGetLastError());
		return -1;
	}

	// Шаг 2 - создание сокета
	SOCKET mysocket;
	// AF_INET     - сокет Интернета
	// SOCK_STREAM  - потоковый сокет (с установкой соединения)
	// 0      - по умолчанию выбирается TCP протокол
	if ((mysocket = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		// Ошибка!
		printf("Error during socket creation: %d\n", WSAGetLastError());
		WSACleanup();
		// Деиницилизация библиотеки Winsock
		return -1;
	}

	// Шаг 3 связывание сокета с локальным адресом
	sockaddr_in local_addr;
	local_addr.sin_family = AF_INET;
	local_addr.sin_port = htons(FINGER_PORT);
	local_addr.sin_addr.s_addr = 0;
	// сервер принимает подключения
	// на все IP-адреса

	// вызываем bind для связывания
	if (bind(mysocket, (sockaddr*)&local_addr, sizeof(local_addr)))
	{
		// Ошибка
		printf("Binding error: %d\n", WSAGetLastError());
		closesocket(mysocket);  // закрываем сокет!
		WSACleanup();
		return -1;
	}

	// Шаг 4 ожидание подключений
	// размер очереди – 0x100
	if (listen(mysocket, 20))
	{
		// Ошибка
		printf("Error during listen: %d\n", WSAGetLastError());
		closesocket(mysocket);
		WSACleanup();
		return -1;
	}

	printf("Server started successfully. Waiting for clients...\n");

	// Шаг 5 извлекаем сообщение из очереди
	SOCKET client_socket[20];    // сокет для клиента
	sockaddr_in client_addr;    // адрес клиента
								// (заполняется системой)

								// функции accept необходимо передать размер
								// структуры
	int client_addr_size = sizeof(client_addr);

	// цикл извлечения запросов на подключение из
	// очереди
	/* accept - держит управление и не даёт циклу вращаться
	(то есть не даёт потоку- нити выполняться вообще)
	пока не поступит очередной запрос на соединение*/
	while ((client_socket[nclients] = accept(mysocket, (sockaddr*)&client_addr, &client_addr_size)))
	{
		nclients++;      // увеличиваем счетчик
						 // подключившихся клиентов

						 // пытаемся получить имя хоста
		HOSTENT* hst;
		hst = gethostbyaddr((char*)&client_addr.sin_addr.s_addr, 4, AF_INET);

		// вывод сведений о клиенте
		printf("+%s [%s] User connected!\n", (hst) ? hst->h_name : "", inet_ntoa(client_addr.sin_addr));
		PRINTNUSERS

			// Вызов нового потока для обслужвания клиента
			// Да, для этого рекомендуется использовать
			// _beginthreadex но, поскольку никаких вызов
			// функций стандартной Си библиотеки поток не
			// делает, можно обойтись и CreateThread
			DWORD thID;

		CreateThread(NULL, NULL, WorkWithClient, client_socket, NULL, &thID);

		/* запускаем функции прослушивания чужих сообщений
		нам нужен именно отдельный поток, потому что recv()
		забирает управление и не позволит послать клиенту
		сообщение пока от этого самого ("родного" для данной
		нити сервера) клиента что-нибудь не придёт */
		//CreateThread(NULL,NULL, CheckCommonBuffer, &client_socket,NULL,&thID);
	}
	return 0;
}



// Эта функция создается в отдельном потоке и
// обсуживает очередного подключившегося клиента
// независимо от остальных
DWORD WINAPI WorkWithClient(LPVOID sockets)
{
	SOCKET my_sock = ((SOCKET*)sockets)[nclients - 1];
	char buff[1024] = "123124";

#define CRLF "\r\n"
#define HELLO_STR "Connection established. \n You can use one of the following queries:\n\
1) Send an '\\all' message to recieve information about all users\n\
2) Send a message in format ( [User name | User login] ) to recieve information about specific user\r\n"
#define LOGIN_STR "User login: "
#define NAME_STR "User name: "
#define GROUP_STR "User group: "
#define PHONE_STR "User phone: "
#define USERINFO_STR "User information file:\r\n"
#define	NOUSERINFO_STR "User don't have an information file\r\n"
#define USERNOTFOUND_STR "There is no such user\r\n"
#define ECHO "foobar"


	// отправляем клиенту приветствие 
	send(my_sock, HELLO_STR, sizeof(HELLO_STR), 0);
	//Принимаем запрос от клиента и отправляем соответствующую информацию в ответ
	int bytes_recv;

	if ((bytes_recv = recv(my_sock, buff, sizeof(buff), 0)) != SOCKET_ERROR) {
		//Открыть файл с информацией о пользователях
		ifstream users;
		users.open("USERS.txt", ios::in);
		if (!users.is_open())
		{
			cout << "\nFile is not open\n";
		}

		cout << "Socket: " << my_sock << " Message: " << buff << endl; // печатает сообщения всех клиентов в консоли сервера

		//Если Запрос вида \r\n, то по стандарту возвращается информация о всех пользователях 
		if (strcmp(CRLF, buff) == 0)
		{
			while (users.getline(buff, sizeof(buff)))
			{
				strcat(buff, CRLF);
				send(my_sock, buff, strlen(buff) + 1, 0);
				recv(my_sock, buff, sizeof(buff), 0);
			}
		}
		else //Любой другой запрос расценивается как запрос о конкретном пользователе (по логину или по имени)
		{
			bool userFound = false;
			string tmp, userLogin, userName;
			char userInfo[256], tmpStr[128];
			//От запроса откидываются последние два символа, которые всегда \r\n по требованию стандарта
			buff[strlen(buff) - 2] = '\0';

			//Обходим весь файл с пользователями
			while (users.getline(userInfo, sizeof(userInfo)))
			{
				userLogin = strtok(userInfo, " _");
				userName = strtok(NULL, " _");
				
				//Если запрос совпал с именем либо с логином пользователя, то отправляем информацию о нём
				if (strcmp(buff, userLogin.c_str()) == 0 || strcmp(buff, userName.c_str()) == 0)
				{
					//Устанавливаем флаг что есть совпадение
					userFound = true;
					
					//Отправляем строку с логином в удобочитаемом виде
					tmp = LOGIN_STR + userLogin + "\r\n";
					strcpy(tmpStr, tmp.c_str());
					send(my_sock, tmpStr, strlen(tmpStr) + 1, 0);
					recv(my_sock, buff, sizeof(buff), 0);

					//Отправляем строку с именем и фамилией в удобочитаемом виде 
					tmp = NAME_STR + userName + " " + strtok(NULL, " ") + "\r\n";
					strcpy(tmpStr, tmp.c_str());
					send(my_sock, tmpStr, strlen(tmpStr) + 1, 0);
					recv(my_sock, buff, sizeof(buff), 0);

					//Отправляем строку с номером группы в удобочитаемом виде
					//тут костыльно, потому что конкатенация плюсовых строк почему-то ругается,
					//если в выражении только сишные строки, поэтому тут ещё и tmp="" засунуто
					tmp = "";
					tmp = tmp + GROUP_STR + strtok(NULL, " ") + "\r\n";
					strcpy(tmpStr, tmp.c_str());
					send(my_sock, tmpStr, strlen(tmpStr) + 1, 0);
					recv(my_sock, buff, sizeof(buff), 0);

					//Отправляем строку с номером. Тут такой же костыль
					tmp = "";
					tmp = tmp + PHONE_STR + strtok(NULL, " ") + "\r\n";
					strcpy(tmpStr, tmp.c_str());
					send(my_sock, tmpStr, strlen(tmpStr) + 1, 0);
					recv(my_sock, buff, sizeof(buff), 0);

					//У каждого пользователя может быть свой информационный файл.
					//Называться он должен логин_пользователя.txt
					//Проверяем существует ли он и если да, то перекидываем построчно клиенту
					//если нет, то отправляем соответствующее сообщение
					ifstream userInfoFile;
					userInfoFile.open(userLogin + ".txt", ios::in);
					if (userInfoFile.is_open())
					{
						send(my_sock, USERINFO_STR, sizeof(USERINFO_STR), 0);
						recv(my_sock, buff, sizeof(buff), 0);

						while (userInfoFile.getline(buff, sizeof(buff)))
						{
							strcat(buff, CRLF);
							send(my_sock, buff, strlen(buff) + 1, 0);
							recv(my_sock, buff, sizeof(buff), 0);
						}

					}
					else
					{
						send(my_sock, NOUSERINFO_STR, sizeof(NOUSERINFO_STR), 0);
						recv(my_sock, buff, sizeof(buff), 0);
					}
				}
			}

			//Если совпадений не найдено, то отправляем соответствующее сообщение
			if (!userFound)
			{
				send(my_sock, USERNOTFOUND_STR, sizeof(USERNOTFOUND_STR), 0);
				recv(my_sock, buff, sizeof(buff), 0);
			}
		}
	}



	nclients--; // уменьшаем счетчик активных клиентов
	printf("-disconnecting\n"); PRINTNUSERS

		// закрываем сокет
		closesocket(my_sock);
	return 0;
}