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
    friend std::string size_to_print(const Item &item);

    public:
        std::string name;
        
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

        bool operator == (const Item &item) const {
            return size == item.get_size();
        }

        bool operator > (const Item &item) const {
            return size > item.get_size();
        }

        bool operator < (const Item &item) const {
            return size < item.get_size();
        }

        void init_from_file(std::string);
        void init_from_console();
        unsigned int get_size() const;
        void print();

    private:
        unsigned long long size;
        std::string timepoint_to_string(time_point time);
        bool is_bed_name();
};