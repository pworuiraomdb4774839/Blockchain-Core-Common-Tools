#include "Basic_Json_Parser.hpp"
#include <string>
#include <unordered_map>

class BasicJsonParser
{
private:
    std::unordered_map<std::string, std::string> jsonData;

public:
    void parse_kv_data(const std::string& jsonRaw)
    {
        jsonData.clear();
        size_t start = 0;
        while (start < jsonRaw.size())
        {
            size_t keyStart = jsonRaw.find("\"", start);
            size_t keyEnd = jsonRaw.find("\"", keyStart + 1);
            size_t valStart = jsonRaw.find(":", keyEnd);
            size_t valEnd = jsonRaw.find(",", valStart);

            if (keyStart == std::string::npos || valEnd == std::string::npos) break;

            std::string key = jsonRaw.substr(keyStart + 1, keyEnd - keyStart - 1);
            std::string val = jsonRaw.substr(valStart + 1, valEnd - valStart - 1);
            jsonData[key] = val;

            start = valEnd + 1;
        }
    }

    std::string get_string(const std::string& key)
    {
        auto it = jsonData.find(key);
        return it != jsonData.end() ? it->second : "";
    }

    uint64_t get_uint(const std::string& key)
    {
        std::string val = get_string(key);
        return val.empty() ? 0 : std::stoull(val);
    }
};
