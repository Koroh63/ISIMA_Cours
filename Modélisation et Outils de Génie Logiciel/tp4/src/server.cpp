#include "httplib.h"
#include "SQLiteCpp/SQLiteCpp.h"
#include <SQLiteCpp/Database.h>
#include <string>
#include <unistd.h>

using namespace std;

int main(){
    
    httplib::Server server;

    SQLite::Database db("database/data.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
    db.exec("CREATE TABLE IF NOT EXISTS visits (id INTEGER PRIMARY KEY, count INTEGER);");

    SQLite::Statement query(db, "SELECT count FROM visits WHERE id = 1;");
    int visit_count = 0;
    if (query.executeStep()) {
        visit_count = query.getColumn(0).getInt();
    } else {
        db.exec("INSERT INTO visits (id, count) VALUES (1, 0);");
    }

    server.Get("/", [&visit_count,&db](const httplib::Request &, httplib::Response &res) {
        visit_count++;
        db.exec("UPDATE visits SET count = " + std::to_string(visit_count) + " WHERE id = 1;");
        res.set_content(to_string(visit_count), "text/plain");
    });

    server.Get("/quit", [&visit_count](const httplib::Request &, httplib::Response &res) {
        
        res.set_content("server quitted in 5 seconds", "text/plain");
        exit(0);    
    });
    
    server.listen("localhost", 8080);
    return 0;
}