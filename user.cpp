#include "user.h"

User::User(const std::string& uname, const std::string& pwdHash, const std::string& saltVal)
    : username(uname), passwordHash(pwdHash), salt(saltVal) {}

std::string User::getUsername() const {
    return username;
}

std::string User::getPasswordHash() const {
    return passwordHash;
}

std::string User::getSalt() const {
    return salt;
}

void User::setUsername(const std::string& uname) {
    username = uname;
}

void User::setPasswordHash(const std::string& pwdHash) {
    passwordHash = pwdHash;
}

void User::setSalt(const std::string& saltVal) {
    salt = saltVal;
}
