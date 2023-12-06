#pragma once
#include "E:\httpLib\httplib.h"
#include <iostream>

class HTTP_Client {
public:
	void Send_message(const std::string& message, const std::string server_ip) {
		httplib::Client client("http://" + server_ip + ":8080"); // зміни ip тут 

		auto res = client.Post("/receive", message, "text/plain");
	}

	std::string Receive_messages(const std::string server_ip) {
		httplib::Client client("http://" + server_ip + ":8080"); // зміни ip тут 

		auto res = client.Get("/get_messages");
		if (res && res->status == 200) {
			return res->body;
		}
	}
};