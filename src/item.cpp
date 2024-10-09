#include "headers/item.h"
using namespace std;

// PUBLIC

Item::Item(const string &name, unsigned long long size, 
    const string &file_ext = "",
    const string &type = "",
    const string &mime_type = "",
    time_point created_time = chrono::system_clock::now(),
    time_point modified_time = chrono::system_clock::now(),
    bool is_dir = false
) : File(name, size, file_ext, type, mime_type, created_time, modified_time), Dir(is_dir) {}

void Item::print() {
    cout << "------Item------" << endl;
    File::print();
    Dir::print();
    cout << "----------------" << endl;
}

unsigned int Item::get_size() const {
    return size;
}