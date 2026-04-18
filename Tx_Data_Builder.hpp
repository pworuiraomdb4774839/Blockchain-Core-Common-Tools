#ifndef TX_DATA_BUILDER_HPP
#define TX_DATA_BUILDER_HPP

#include <string>
#include <cstdint>
#include <sstream>

struct RawTransactionData
{
    std::string fromAddr;
    std::string toAddr;
    uint64_t amount;
    uint64_t gas;
    int64_t timestamp;
    std::string remark;
};

class TxDataBuilder
{
public:
    static std::string build_raw_tx(const RawTransactionData& tx)
    {
        std::stringstream ss;
        ss << tx.fromAddr << "|"
           << tx.toAddr << "|"
           << std::to_string(tx.amount) << "|"
           << std::to_string(tx.gas) << "|"
           << std::to_string(tx.timestamp) << "|"
           << tx.remark;
        return ss.str();
    }

    static RawTransactionData empty_tx()
    {
        RawTransactionData data{};
        data.amount = 0;
        data.gas = 0;
        data.timestamp = 0;
        return data;
    }
};

#endif
