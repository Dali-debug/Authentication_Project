#include "hash.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string Hash::sha256(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.length(), hash);

    std::stringstream ss;
    for (unsigned char i : hash) {
        ss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(i);
    }

    return ss.str();
}
