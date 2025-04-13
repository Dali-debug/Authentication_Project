#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "user.h"
#include <vector>
#include <string>

class FileHandler {
private:
    std::string filename;

public:
    FileHandler(const std::string& fname);

    std::vector<User> readUsers();
    void writeUser(const User& user);
};

#endif
