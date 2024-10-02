#include "headers/item.h"
using namespace std;

const unsigned int KILO = 1024;

string size_to_print(const Item &item) {
    vector<string> name_size_file = {"bytes", "KB", "MB", "GB", "TB"};
    short d = 0;
    double total_size = item.size;
    while(total_size / KILO > 1) {
        d++;
        total_size = round((total_size / KILO) * 100.0) / 100.0;
    }
    string str = to_string(total_size);
    int dot_pos = str.find('.');
    str = str.substr(0, dot_pos + 3);
    return str + " " + name_size_file[d];
}