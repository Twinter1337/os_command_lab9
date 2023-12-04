#pragma once
#include "E:\httpLib\httplib.h"
#include <iostream>

class HTTP_Client {
public:
	void Send_message(const std::string& message) {
		httplib::Client client("http://192.168.31.49:8080"); // зміни ip тут 

		auto res = client.Post("/receive", message, "text/plain");
	}

	std::string Receive_messages() {
		httplib::Client client("http://192.168.31.49:8080"); // зміни ip тут 

		auto res = client.Get("/get_messages");
		if (res && res->status == 200) {
			return res->body;
		}
	}
};