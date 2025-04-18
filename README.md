# 🚀 WebSocket++ Server with Standalone Asio (Windows / MSYS2)

This project demonstrates how to run a minimal WebSocket server using **WebSocket++** and **standalone Asio** (no Boost) on Windows using **MSYS2 MinGW 64-bit**.

---

**Create `main.cpp`**

```cpp
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
```

---

## 🔨 Build the Server

Run the following command inside the MSYS2 **MinGW 64-bit** terminal:

```bash
g++ main.cpp -std=c++11 \
  -I <WSPP_PATH> \
  -I <ASIO_PATH>/asio/include \
  -lpthread -lws2_32 -lmswsock -o my_websocket_server
```

> Replace `<WSPP_PATH>` with the path to your `websocketpp` folder  
> Replace `<ASIO_PATH>` with the path to your `asio-X.Y.Z` folder


## ▶️ Run the Server

```bash
./my_websocket_server
```

You should see:

```
[*] WebSocket server is running on port 9002...
```

And when a client connects:

```
[+] Client connected!
```

---

## 🧪 Test the Server

### Option 1: Browser Console

```js
const ws = new WebSocket("ws://localhost:9002");
ws.onopen = () => console.log("Connected!");
```

### Option 2: With `wscat` (Node.js CLI tool)

```bash
npm install -g wscat
wscat -c ws://localhost:9002
```

---

## ✅ Done!

You now have a working standalone WebSocket server in C++ using WebSocket++ and Asio — all without Boost. 🎉
