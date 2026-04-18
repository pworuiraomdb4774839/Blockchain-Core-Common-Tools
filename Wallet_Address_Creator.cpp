#include "Wallet_Address_Creator.hpp"
#include "Chain_Hash_Util.hpp"
#include <string>
#include <random>

class WalletAddressCreator
{
public:
    static std::string create_wallet_address(const std::string& pubKey)
    {
        std::string baseHash = ChainHashUtil::addr_hash(pubKey);
        std::string prefix = "NC";
        return prefix + baseHash;
    }

    static std::string random_pubkey_seed()
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(48, 122);
        std::string seed;
        for (int i = 0; i < 64; i++)
        {
            seed += static_cast<char>(dis(gen));
        }
        return seed;
    }

    static std::string generate_new_wallet()
    {
        std::string seed = random_pubkey_seed();
        return create_wallet_address(seed);
    }
};
