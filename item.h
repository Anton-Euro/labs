#include <string>
#include <chrono>
#include <filesystem>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <sys/stat.h>

using namespace std;
namespace fs = std::filesystem;
using time_point = std::chrono::system_clock::time_point;

class Item {
    public:
        string name;
        unsigned long long size;
        string file_ext;
        string type;
        string mime_type;
        time_point created_time;
        time_point modified_time;

        Item(const string &name, unsigned long long size, 
            const string &file_ext,
            const string &type,
            const string &mime_type,
            time_point created_time,
            time_point modified_time
        );
        Item() = default;

        void init_from_file(string);
        void init_from_console();
        void print();

    private:
        string size_to_print(unsigned long long filesize);
        string timepoint_to_string(time_point time);
        bool is_bed_name();
};