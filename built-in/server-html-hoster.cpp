#include<bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
using namespace std;

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 10);

    cout << "Hosting index.html at http://localhost:8080\n";

    while (true) {
        int client = accept(server_fd, nullptr, nullptr);
        ifstream file("index.html");
        stringstream buffer;
        buffer << file.rdbuf();
        string html = buffer.str();

        string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n\r\n" +
            html;

        send(client, response.c_str(), response.size(), 0);
        close(client);
    }

    return 0;
}
