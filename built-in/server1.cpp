#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
using namespace std;

#define fastAOI ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define sz(x) (int)(x).size()


void server(){
    int port;
    cout<<"Select a port like = (8080)\n";
    cin >>port;
    int server_fd;
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
   sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 10);

    cout << "Server running on http://localhost:" << port <<"\n";
    while (true) {
        int client = accept(server_fd, nullptr, nullptr);
        
        string response =
            "HTTP/1.1 200 OK\r\n"
            "Content-Type: text/html\r\n\r\n"
            "<h1>Hello from my C++ Server!.moha</h1>";

        send(client, response.c_str(), response.size(), 0);
        close(client);
    }

}

int main() {
    //fastAOI;
    int t = 1;
    // cin >> t;
    while (t--) {
        server();
        // solve();
    }
    return 0;
}
