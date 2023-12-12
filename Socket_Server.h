#pragma once

#include <iostream>
#include <winsock2.h>
#include <string>
#include <ws2tcpip.h>
#include <stdio.h>
#include <vector>
#include <thread>

#pragma comment(lib, "ws2_32.lib")

class Socket_server {
public:
  Socket_server() {
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 2);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
      std::cout << "Error initializing Winsock" << std::endl;
      exit(1);
    }
  }

  ~Socket_server() {
    WSACleanup();
  }

  void Start(const char* ip_address, int port) {
    Setup_socket(ip_address, port);
    Accept_connections();
  }

private:
  SOCKET listen_socket;
  std::vector<SOCKET> connections;
  int counter = 0;

  void Setup_socket(const char* ip_address, int port) {
    SOCKADDR_IN addr;
    int size_of_addr = sizeof(addr);
    if (inet_pton(AF_INET, ip_address, &addr.sin_addr) <= 0) {
      std::cout << "Invalid address" << std::endl;
      exit(1);
    }
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;

    listen_socket = socket(AF_INET, SOCK_STREAM, NULL);
    bind(listen_socket, (SOCKADDR*)&addr, sizeof(addr));
    listen(listen_socket, SOMAXCONN);

    std::cout << "SERVER" << std::endl;
    std::cout << "Check connecting..." << std::endl;
  }

  void Accept_connections() {
    SOCKADDR_IN addr;
    int size_of_addr = sizeof(addr);
    SOCKET new_connection;

    for (int i = 0; i < 2; i++) {
      new_connection = accept(listen_socket, (SOCKADDR*)&addr, &size_of_addr);

      if (new_connection == 0) {
        std::cout << "Error accepting connection" << std::endl;
      }
      else {
        std::cout << "Client Connected!" << std::endl;
        connections.push_back(new_connection);
        counter++;
        std::thread(&Socket_server::ClientHandler, this, i).detach();
      }
    }
  }

  void ClientHandler(int index) {
    char msg[256];
    while (true) {
      if (recv(connections[index], msg, sizeof(msg), NULL) == SOCKET_ERROR) {
        closesocket(connections[index]);
        return;
      }
      for (int i = 0; i < counter; i++) {
        /*if (i == index) {
            continue;
        }*/
        send(connections[i], ("Other user: " + std::string(msg)).c_str(), sizeof(msg), NULL);
      }
    }
  }
};