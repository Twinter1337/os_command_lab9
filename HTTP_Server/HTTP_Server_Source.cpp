//#include "C:\Users\$DPH400-H44T15729HUK\Downloads\httplib.h"
//#include <iostream>
//#include <map>
//
//class MyServer {
//public:
//    void handle_receive(const httplib::Request& req, httplib::Response& res) {
//        std::string client_address = req.remote_addr;
//        std::cout << "Request from client at address: " << client_address << std::endl;
//        std::string message = req.body;
//        std::cout << "Message from client: " << message << std::endl;
//
//        messages.push_back(message);
//
//        // Оновлення списку підключених клієнтів
//        clients[client_address] = 8080;  // Assuming default port is 8080, update accordingly
//
//        // Відправлення повідомлень всім підключеним клієнтам, окрім відправника
//        broadcast_messages(client_address);
//
//        res.set_content("Message received by server", "text/plain");
//    }
//
//    void handle_get_messages(const httplib::Request& req, httplib::Response& res) {
//        std::string response_body;
//
//        if (!messages.empty() && messages_log_size < messages.size()) {
//            response_body = messages.back();
//            res.set_content(response_body, "text/plain");
//            messages_log_size++;
//        }
//        else {
//            return;
//        }
//    }
//
//    void start_server() {
//        server.Post("/receive", [&](const httplib::Request& req, httplib::Response& res) {
//            handle_receive(req, res);
//            });
//
//        server.Get("/get_messages", [&](const httplib::Request& req, httplib::Response& res) {
//            handle_get_messages(req, res);
//            });
//
//        std::cout << "Server is listening on port 8080..." << std::endl;
//        server.listen("0.0.0.0", 8080);
//    }
//
//private:
//    httplib::Server server;
//    std::vector<std::string> messages;
//    int messages_log_size = 0;
//
//    // Структура для збереження інформації про підключених клієнтів
//    std::map<std::string, int> clients;  // Use int to store the client's port
//
//    void broadcast_messages(const std::string& sender_address) {
//        // Відправлення повідомлень всім підключеним клієнтам, окрім відправника
//        for (const auto& client : clients) {
//            const std::string& client_address = client.first;
//
//            if (client_address != sender_address) {
//                // Get the client's port from the stored map
//                int client_port = client.second;
//
//                // Use the client_address and client_port as needed (e.g., send a message to the client)
//                httplib::Client client(client_address.c_str(), client_port);
//                auto res = client.Post("/get_messages", "", "text/plain");
//                if (!res || res->status != 200) {
//                    std::cerr << "Error sending messages to client at address: " << client_address << std::endl;
//                }
//
//            }
//        }
//    }
//};
//
//int main() {
//    MyServer my_server;
//    my_server.start_server();
//
//    return 0;
//}
