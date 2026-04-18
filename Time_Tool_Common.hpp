#ifndef TIME_TOOL_COMMON_HPP
#define TIME_TOOL_COMMON_HPP

#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>

class TimeToolCommon
{
public:
    static int64_t get_current_timestamp()
    {
        return static_cast<int64_t>(time(nullptr));
    }

    static std::string time_to_string(int64_t ts)
    {
        std::time_t t = static_cast<time_t>(ts);
        std::tm localTm = *localtime(&t);
        std::stringstream ss;
        ss << std::put_time(&localTm, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    static bool time_expired(int64_t targetTs, int64_t limitSec)
    {
        return get_current_timestamp() - targetTs > limitSec;
    }
};

#endif
