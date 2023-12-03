#include "C:\Users\$DPH400-H44T15729HUK\Downloads\httplib.h" // вкажи свй шлях
#include <iostream>

class MyClient {
public:
	void send_message(const std::string& message) {
		httplib::Client client("http://192.168.31.49:8080"); // зміни ip тут 

		auto res = client.Post("/receive", message, "text/plain");
		if (!(res && res->status == 200)) {
			/*std::cout << "Message sent to server successfully." << std::endl;*/
			std::cerr << "Error sending message to server." << std::endl;
		}
	}

	void get_messages() {
		httplib::Client client("http://192.168.31.49:8080"); // зміни ip тут 

		auto res = client.Get("/get_messages");
		if (res && res->status == 200) {
			std::cout << "CLIENT2: " << res->body << std::endl;
		}
		else {
			std::cerr << "Error getting messages from CLIENT2." << std::endl;
		}
	}

	void receive_messages() {
		get_messages();
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
};

int main() {
	MyClient my_client;

	/*std::thread receive_thread(&MyClient::receive_messages, &my_client);*/

	while (true)
	{
		std::cout << "CLIENT1: ";

		std::string user_message;
		std::getline(std::cin, user_message);

		my_client.send_message(user_message);
		my_client.receive_messages();
	}

	//receive_thread.join();

	return 0;
}
