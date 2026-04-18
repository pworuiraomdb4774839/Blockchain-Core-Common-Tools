#include "Log_Output_Common.hpp"
#include "TimeToolCommon.hpp"
#include <iostream>

class LogOutputCommon
{
public:
    static void log_info(const std::string& msg)
    {
        std::string timeStr = TimeToolCommon::time_to_string(TimeToolCommon::get_current_timestamp());
        std::cout << "[INFO] " << timeStr << " : " << msg << std::endl;
    }

    static void log_error(const std::string& msg)
    {
        std::string timeStr = TimeToolCommon::time_to_string(TimeToolCommon::get_current_timestamp());
        std::cerr << "[ERROR] " << timeStr << " : " << msg << std::endl;
    }

    static void log_chain(const std::string& module, const std::string& msg)
    {
        std::string timeStr = TimeToolCommon::time_to_string(TimeToolCommon::get_current_timestamp());
        std::cout << "[CHAIN][" << module << "] " << timeStr << " : " << msg << std::endl;
    }
};
