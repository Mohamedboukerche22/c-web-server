#include "crow.h"
using namespace crow;
// easy way to host lol
int main() {
    SimpleApp app;
    CROW_ROUTE(app, "/")([](){
        return "<h1>Hello from Crow!.moha</h1>";
    });
    app.port(8080).run();
}
