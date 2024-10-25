#ifndef FILE_H
#define FILE_H

#include <string>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <sys/stat.h>

namespace fs = std::filesystem;
namespace file_list {
    using time_point = std::chrono::system_clock::time_point;
}


class File {
    virtual unsigned int get_size() const = 0;

    public:
        std::string name;
        unsigned long long size;
        std::string file_ext;
        std::string type;
        std::string mime_type;
        file_list::time_point created_time;
        file_list::time_point modified_time;

        File(const std::string &name, unsigned long long size, 
            const std::string &file_ext = "",
            const std::string &type = "",
            const std::string &mime_type = "",
            file_list::time_point created_time = std::chrono::system_clock::now(),
            file_list::time_point modified_time = std::chrono::system_clock::now()
        );
        File() = default;

        virtual void print();
        void init_from_console();
    
    private:
        std::string timepoint_to_string(file_list::time_point time);
        bool is_bed_name();
        std::string size_to_print();
};

#endif