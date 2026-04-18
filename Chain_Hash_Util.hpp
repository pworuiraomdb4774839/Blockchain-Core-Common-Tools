#ifndef CHAIN_HASH_UTIL_HPP
#define CHAIN_HASH_UTIL_HPP

#include <string>
#include <cstdint>
#include <sstream>
#include <functional>

class ChainHashUtil
{
public:
    static std::string simple_hash(const std::string& rawData)
    {
        size_t hashVal = std::hash<std::string>{}(rawData);
        std::stringstream ss;
        ss << std::hex << hashVal;
        return ss.str();
    }

    static std::string calc_block_hash(uint64_t height, const std::string& preHash, uint64_t nonce)
    {
        std::string raw = std::to_string(height) + preHash + std::to_string(nonce);
        return simple_hash(raw);
    }

    static std::string addr_hash(const std::string& publicKey)
    {
        return simple_hash(publicKey).substr(0, 40);
    }
};

#endif
