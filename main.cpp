#define ASIO_STANDALONE
#define _WEBSOCKETPP_CPP11_THREAD_

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>
#include <iostream>

typedef websocketpp::server<websocketpp::config::asio> server;

int main() {
    server ws_server;

    ws_server.init_asio();

    ws_server.set_open_handler([](websocketpp::connection_hdl) {
        std::cout << "[+] Client connected!" << std::endl;
    });

    std::cout << "[*] WebSocket server is running on port 9002..." << std::endl;

    ws_server.listen(9002);
    ws_server.start_accept();
    ws_server.run();
}