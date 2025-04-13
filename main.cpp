#include <iostream>
#include <random>
#include <conio.h> // Windows only
#include "file_handler.h"
#include "hash.h"
#include "user.h"

// Masquer la saisie du mot de passe avec '*'
std::string inputHiddenPassword() {
    std::string password;
    char ch;

    while ((ch = _getch()) != '\r') { // Entrée = fin
        if (ch == '\b') { // Backspace
            if (!password.empty()) {
                password.pop_back();
                std::cout << "\b \b";
            }
        } else {
            password.push_back(ch);
            std::cout << '*';
        }
    }
    std::cout << std::endl;
    return password;
}

// Générer un sel aléatoire
std::string generateSalt(size_t length = 16) {
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string salt;
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<> distrib(0, charset.size() - 1);

    for (size_t i = 0; i < length; ++i) {
        salt += charset[distrib(generator)];
    }

    return salt;
}

// Vérifier si l'utilisateur existe déjà
bool userExists(const std::vector<User>& users, const std::string& username) {
    for (const auto& user : users) {
        if (user.getUsername() == username) return true;
    }
    return false;
}

// Enregistrement
void registerUser(FileHandler& handler) {
    std::string uname;
    std::cout << "=====Registration=====\n";
    std::cout << " Enter username: ";
    std::cin >> uname;

    std::vector<User> users = handler.readUsers();
    if (userExists(users, uname)) {
        std::cout << "User already exists.\n";
        return;
    }

    std::cout << " Enter password: ";
    std::string pwd = inputHiddenPassword();

    std::string salt = generateSalt();
    std::string hash = Hash::sha256(pwd + salt);
    User newUser(uname, hash, salt);
    handler.writeUser(newUser);
    std::cout << "User registered successfully.\n";
}

// Connexion
void loginUser(FileHandler& handler) {
    std::string uname;
    std::cout << "=====Login=====\n";
    std::cout << " Enter username: ";
    std::cin >> uname;
    std::cout << " Enter password: ";
    std::string pwd = inputHiddenPassword();

    std::vector<User> users = handler.readUsers();
    for (const auto& user : users) {
        if (user.getUsername() == uname) {
            std::string hash = Hash::sha256(pwd + user.getSalt());
            if (user.getPasswordHash() == hash) {
                std::cout << "Login successful!\n";
                return;
            } else {
                std::cout << "Invalid password.\n";
                return;
            }
        }
    }

    std::cout << "User not found.\n";
}

int main() {
    FileHandler handler("users.txt");

    int choice;
    do {
        std::cout << "\n1. Register\n2. Login\n0. Exit\nChoose option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                registerUser(handler);
                break;
            case 2:
                loginUser(handler);
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}
