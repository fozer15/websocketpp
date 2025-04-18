#define ASIO_STANDALONE
#define _WEBSOCKETPP_CPP11_THREAD_

#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

int main() {
    websocketpp::server<websocketpp::config::asio> server;
    server.init_asio();
    server.listen(9002);
    server.start_accept();
    std::cout << "[*] WebSocket server is running on port 9002..." << std::endl;
    server.run();
    return 0;
}