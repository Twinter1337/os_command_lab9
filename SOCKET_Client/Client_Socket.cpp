#include <iostream>
#include <winsock2.h>
#include <string>
#include <ws2tcpip.h>
#include <thread>
#include <chrono>
#pragma comment(lib, "ws2_32.lib")

class Client {
public:
    Client(const std::string& serverIP, int port) : serverIP(serverIP), port(port) {}

    ~Client() {
        closesocket(connection);
        WSACleanup();
    }

    void Connect() {
        WSAData wsaData;
        WORD DLLVersion = MAKEWORD(2, 2);
        if (WSAStartup(DLLVersion, &wsaData) != 0) {
            std::cout << "ERROR" << std::endl;
            exit(1);
        }

        SOCKADDR_IN addr;
        int size_of_addr = sizeof(addr);
        if (inet_pton(AF_INET, serverIP.c_str(), &addr.sin_addr) <= 0) {
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

        receiveThread = std::thread(&Client::Receive_messages, this);
    }

    void Send_messages() {
        char msg[256];
        while (true) {
            std::cin.getline(msg, sizeof(msg));
            send(connection, msg, sizeof(msg), NULL);
        }
    }

    void Receive_messages() {
        char msg[256];
        while (true) {
            int bytesReceived = recv(connection, msg, sizeof(msg), NULL);
            if (bytesReceived <= 0) {
                std::cout << "Server closed the connection." << std::endl;
                exit(1);
            }
            std::cout << msg << std::endl;
        }
    }

private:
    SOCKET connection;
    std::string serverIP;
    int port;
    std::thread receiveThread;
};

int main() {
    Client client("192.168.2.101", 5555);
    client.Connect();

    client.Send_messages();

    return 0;
}
