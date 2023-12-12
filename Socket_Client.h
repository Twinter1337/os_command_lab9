#pragma once
#include <iostream>
#include <winsock2.h>
#include <string>
#include <ws2tcpip.h>
#include <thread>
#include <chrono>
#include "Client.h"
#include "MainForm.h"

#pragma comment(lib, "ws2_32.lib")

namespace lab9
{
  using namespace System;
  using namespace System::Windows::Forms;

  class Socket_Client : public Client {
  public:
    ~Socket_Client() {
      closesocket(connection);
      WSACleanup();
    }

    void RecieveMessageThread() override {

      while (true) {

        std::string msg = "";

        if (RecieveOneMessage(msg))
        {
          chat += msg;
          std::cout << chat << std::endl;
        }
        else
        {
          std::cout << "Server closed connection." << std::endl;
        }
      }
    }

    bool RecieveOneMessage(std::string& message) override
    {
      message = "";
      char msg[256];
      int result = recv(connection, msg, sizeof(msg), NULL);

      int i = 0;

      while (msg[i] != '\n')
      {
        message += msg[i];
        i++;
      }

      message += msg[i];

      return result > 0;
    }

    void Initialize(std::string server_ip, int port) override
    {
      this->server_ip = server_ip;
      this->port = port;
      Connect();
    }

    void SendMessage(const std::string& msg) override
    {
      send(connection, msg.c_str(), msg.size(), NULL);
    }

  private:
    void Connect() {
      WSAData wsaData;
      WORD DLLVersion = MAKEWORD(2, 2);
      if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "ERROR" << std::endl;
        exit(1);
      }

      SOCKADDR_IN addr;
      int size_of_addr = sizeof(addr);
      if (inet_pton(AF_INET, server_ip.c_str(), &addr.sin_addr) <= 0) {
        std::cout << "Invalid address" << std::endl;
        exit(1);
      }
      addr.sin_port = htons(port);
      addr.sin_family = AF_INET;

      connection = socket(AF_INET, SOCK_STREAM, NULL);
      if (connect(connection, (SOCKADDR*)&addr, size_of_addr) != 0) {
        std::cout << "Error: failed connect to server" << std::endl;
        exit(1);
      }

      std::cout << "Connected successfully" << std::endl;

      receiveThread = std::thread(&Socket_Client::RecieveMessageThread, this);
    }

    SOCKET connection;
  };
}