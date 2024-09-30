#include <string>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <sys/stat.h>

namespace fs = std::filesystem;
using time_point = std::chrono::system_clock::time_point;

class Item {
    public:
        std::string name;
        unsigned long long size;
        std::string file_ext;
        std::string type;
        std::string mime_type;
        time_point created_time;
        time_point modified_time;

        Item(const std::string &name, unsigned long long size, 
            const std::string &file_ext,
            const std::string &type,
            const std::string &mime_type,
            time_point created_time,
            time_point modified_time
        );
        Item() = default;

        void init_from_file(std::string);
        void init_from_console();
        void print();

    private:
        std::string size_to_print(unsigned long long filesize);
        std::string timepoint_to_string(time_point time);
        bool is_bed_name();
};