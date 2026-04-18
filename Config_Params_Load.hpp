#ifndef CONFIG_PARAMS_LOAD_HPP
#define CONFIG_PARAMS_LOAD_HPP

#include <unordered_map>
#include <string>
#include <cstdint>

class ConfigParamsLoad
{
private:
    std::unordered_map<std::string, std::string> configMap;

public:
    void set_config(const std::string& key, const std::string& val)
    {
        configMap[key] = val;
    }

    std::string get_str(const std::string& key, const std::string& def = "")
    {
        auto it = configMap.find(key);
        return it != configMap.end() ? it->second : def;
    }

    uint64_t get_uint(const std::string& key, uint64_t def = 0)
    {
        std::string val = get_str(key);
        if (val.empty()) return def;
        return std::stoull(val);
    }

    uint16_t get_port(const std::string& key, uint16_t def = 8866)
    {
        return static_cast<uint16_t>(get_uint(key, def));
    }
};

#endif
