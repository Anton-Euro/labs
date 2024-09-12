#include <string>
#include <ctime>
#include <filesystem>
#include <iostream>
#include <vector>
#include <cmath>
#include <sys/stat.h>

using namespace std;
namespace fs = std::filesystem;

class Item {
    public:
        string name;
        unsigned long long size;
        time_t created_time;
        time_t modified_time;
        string file_ext;
        string type;
        string mime_type;

        Item(const string &name, unsigned long long size, 
            string file_ext,
            string type,
            string mime_type,
            time_t created_time,
            time_t modified_time
        );
        Item() = default;

        void init_from_file(string);
        void init_from_console();
        void print();

    private:
        string size_to_print(unsigned long long filesize);
        string time_to_string(time_t time);
        bool is_bed_name();
};