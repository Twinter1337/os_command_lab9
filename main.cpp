#include <iostream>
#include "HTTP_Server.h"
#include "Socket_Server.h"

using namespace std;

int main()
{
  int i = -1;
  cout << "use: socket - 0, HTTP - 1" << endl;

  while (i < 0 || i>1)
  {
    cin >> i;
  }


  if (i == 0)
  {

    cout << "enter ip" << endl;
    string ip;
    cin >> ip;

    cout << "enter port" << endl;
    int port;
    cin >> port;

    Socket_server server;
    server.Start(ip.c_str(), port);
  system("pause");

  }
  else
  {
    HTTP_server server;
    server.Start_server();
  system("pause");
  }
}