#include "C:\Users\$DPH400-H44T15729HUK\Downloads\httplib.h"
#include <iostream>

class HTTP_server {
private:
	std::vector<std::string> messages_log; // тут і так все ясно
	std::map<std::string, int> clients; //зберігає адресу і порт клієнтів
	httplib::Server server;
	int messages_log_size = 0;

public:

	//------------------------------------------------------------------------------------------

	std::pair<std::string, std::string> Receive_messge_from_client(const httplib::Request& req, httplib::Response& res) {
		std::string client_id = req.remote_addr;
		std::string message_from_client = req.body;

		clients[client_id] = 8080;

		messages_log.push_back(client_id + " : " + message_from_client);

		//test
		std::cout << messages_log.back() << std::endl;
		//test

		res.set_content("Message recived by server", "text/plain");
		return std::pair<std::string, std::string>(client_id, message_from_client);
	}

	//------------------------------------------------------------------------------------------
	
	void Manage_message_from_client(const httplib::Request& req, httplib::Response& res) {
		std::pair<std::string, std::string> sender_info = Receive_messge_from_client(req, res);
	}

	//------------------------------------------------------------------------------------------

	void Handle_get_messages(const httplib::Request& req, httplib::Response& res) {
		std::string response_body;

		if (!messages_log.empty() && messages_log_size < messages_log.size()) {
			response_body = messages_log.back();
			res.set_content(response_body, "text/plain");
			messages_log_size++;
		}
		else {
			return;
		}
	}

	//------------------------------------------------------------------------------------------

	void Start_server() {
		server.Post("/receive", [&](const httplib::Request& req, httplib::Response& res) {
			Manage_message_from_client(req, res);
			});

		server.Get("/get_messages", [&](const httplib::Request& req, httplib::Response& res) {
			Handle_get_messages(req, res);
			});

		std::cout << "Server is running..." << std::endl;
		server.listen("0.0.0.0", 8080);
	}
};

int main() {
	HTTP_server *server = new HTTP_server();

	server->Start_server();
}