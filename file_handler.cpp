#include "file_handler.h"
#include <fstream>
#include <sstream>

FileHandler::FileHandler(const std::string& fname)
    : filename(fname) {}

std::vector<User> FileHandler::readUsers() {
    std::vector<User> users;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string uname, hash, salt;

        std::getline(ss, uname, ',');
        std::getline(ss, hash, ',');
        std::getline(ss, salt);

        if (!uname.empty() && !hash.empty() && !salt.empty()) {
            users.emplace_back(uname, hash, salt);
        }
    }

    return users;
}

void FileHandler::writeUser(const User& user) {
    std::ofstream file(filename, std::ios::app);
    file << user.getUsername() << "," << user.getPasswordHash() << "," << user.getSalt() << "\n";
}
