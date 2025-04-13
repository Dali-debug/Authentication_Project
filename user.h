#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string passwordHash;
    std::string salt;

public:
    User(const std::string& uname, const std::string& pwdHash, const std::string& saltVal);

    std::string getUsername() const;
    std::string getPasswordHash() const;
    std::string getSalt() const;

    void setUsername(const std::string& uname);
    void setPasswordHash(const std::string& pwdHash);
    void setSalt(const std::string& saltVal);
};

#endif
