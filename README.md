
# C++ Authentication System 🔐

This project implements a simple authentication system in C++ using the following features:

- Object-Oriented Programming (OOP)
- Secure password hashing using **SHA-256** and unique **salt**
- Masked password input using `getch()` (for Windows)
- Persistent storage in `users.txt`
- User registration with username check
- Login functionality
- Fully modular structure (user, file handler, hashing)

---

## 🛠 Structure

```
📁 project-root
│
├── user.h / user.cpp         → User model class
├── hash.h / hash.cpp         → SHA-256 hashing utility
├── file_handler.h / .cpp     → File read/write operations
├── main.cpp                  → CLI interface, authentication logic
├── users.txt                 → Flat file storage for registered users
└── README.md                 → Project description (this file)
```

---

## 🧪 Testing

The final step is **integration testing** to simulate the authentication workflow and validate the output of our code.

✅ We will automate these tests using **GitHub Actions**, as usual 😉.

---

## 🗂️ Version Control

We will use **GitHub** and **Git** to push changes and collaborate as a team.  
Please share your GitHub links so I can review your progress and assist with improvements.


---

## 🧰 Compilation (Windows)

Requires:
- OpenSSL installed
- `g++` compiler (MinGW)

Command:
```bash
g++ main.cpp user.cpp file_handler.cpp hash.cpp -o auth_app -lssl -lcrypto
```

