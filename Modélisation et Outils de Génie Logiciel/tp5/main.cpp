#include "httplib.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>

int main() {
    try {
        // Créer ou ouvrir la base de données persistante
        SQLite::Database db("visits.db", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        db.exec("CREATE TABLE IF NOT EXISTS visits (count INTEGER);");

        if (db.execAndGet("SELECT COUNT(*) FROM visits;").getInt() == 0) {
            db.exec("INSERT INTO visits (count) VALUES (0);");
        }

        httplib::Server svr;

        // Route pour "/"
        svr.Get("/", [&db](const httplib::Request &, httplib::Response &res) {
            int count = db.execAndGet("SELECT count FROM visits;").getInt();
            count++;
            db.exec("UPDATE visits SET count = " + std::to_string(count) + ";");
            res.set_content("Total visits: " + std::to_string(count), "text/plain");
        });

        // Route pour "/quit"
        svr.Get("/quit", [&](const httplib::Request &, httplib::Response &) {
            svr.stop();
        });

        std::cout << "Server running on http://0.0.0.0:8080\n";
        svr.listen("0.0.0.0", 8080);

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
