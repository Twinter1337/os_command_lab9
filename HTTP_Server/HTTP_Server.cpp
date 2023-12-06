#include "E:\httplib\httplib.h"
#include <iostream>

class HTTP_server {
private:

	std::vector<std::string> messages_log; // тут і так все ясно
	std::map<std::string, int> clients; //зберігає адресу і порт клієнтів
	httplib::Server server;
	int messages_log_size = 0;

public:

	//------------------------------------------------------------------------------------------

	void Receive_messge_from_client(const httplib::Request& req, httplib::Response& res) {
		std::string client_id = req.remote_addr;
		std::string message_from_client = req.body;

		clients[client_id] = 8080;

		messages_log.push_back(client_id + " : " + message_from_client);

		std::cout << messages_log.back() << std::endl;
	
		res.set_content("Message recived by server", "text/plain");
		}

	//------------------------------------------------------------------------------------------
	
	void Handle_get_messages(const httplib::Request& req, httplib::Response& res) {
		std::string response_body;

		for (auto msg : messages_log) {
			response_body += msg;
		}

		res.set_content(response_body, "text/plain");
	}

	//------------------------------------------------------------------------------------------

	void Start_server() {
		server.Post("/receive", [&](const httplib::Request& req, httplib::Response& res) {
			Receive_messge_from_client(req, res);
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