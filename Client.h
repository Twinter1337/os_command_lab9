#pragma once
#include <iostream>

class Client {
  public:
  virtual void SendMessage(const std::string& msg) = 0;
  virtual void RecieveMessageThread() = 0;
  virtual bool RecieveOneMessage(std::string& msg) = 0;
  virtual void Initialize(std::string server_ip, int port) = 0;

  std::string chat = "";
protected:
  std::string server_ip;
  int port;
  std::thread receiveThread;
};