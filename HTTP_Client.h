#pragma once
#include "httplib.h"
#include <iostream>
#include <string>
#include "Client.h"

namespace lab9
{
  class HTTP_Client : public Client
  {
  public:

    void Initialize(std::string server_ip, int port) override
    {
      this->server_ip = server_ip;
      this->port = port;
      receiveThread = std::thread(&HTTP_Client::RecieveMessageThread, this);
    }

    void SendMessage(const std::string& msg) override
    {
      httplib::Client client("http://" + server_ip + ":" + std::to_string(port));
      auto res = client.Post("/receive", msg, "text/plain");
    }

    void RecieveMessageThread() override
    {
      while (true)
      {
        std::string msg = "";

        if (RecieveOneMessage(msg))
        {
          if (msg != chat)
          {
            chat = msg;
            std::cout << msg << std::endl;
          }
        }
      }
    }

    bool RecieveOneMessage(std::string& message) override
    {
      httplib::Client client("http://" + server_ip + ":" + std::to_string(port));
      auto res = client.Get("/get_messages");

      if (res && res->status == 200)
      {
        message = res->body;
      }

      return message.size() != 0;
    }
  };
}