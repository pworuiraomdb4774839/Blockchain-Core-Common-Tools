#include "Simple_File_Operate.hpp"
#include <fstream>
#include <string>

class SimpleFileOperate
{
public:
    static bool write_file(const std::string& path, const std::string& content)
    {
        std::ofstream out(path, std::ios::out | std::ios::trunc);
        if (!out.is_open()) return false;
        out << content;
        out.close();
        return true;
    }

    static std::string read_file(const std::string& path)
    {
        std::ifstream in(path);
        if (!in.is_open()) return "";
        std::stringstream buffer;
        buffer << in.rdbuf();
        in.close();
        return buffer.str();
    }

    static bool append_file(const std::string& path, const std::string& content)
    {
        std::ofstream out(path, std::ios::app);
        if (!out.is_open()) return false;
        out << content;
        out.close();
        return true;
    }
};
