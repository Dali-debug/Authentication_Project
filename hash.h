#ifndef HASH_H
#define HASH_H

#include <string>

class Hash {
public:
    static std::string sha256(const std::string& input);
};

#endif
