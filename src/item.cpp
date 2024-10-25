#include "headers/item.h"
using namespace std;

// PUBLIC


Item::Item(const string &name, unsigned long long size, 
    const string &file_ext,
    const string &type,
    const string &mime_type,
    file_list::time_point created_time,
    file_list::time_point modified_time,
    bool is_dir
): File(name, size, file_ext, type, mime_type, created_time, modified_time), Dir(is_dir) {}

void Item::print() {
    cout << "------Item------" << endl;
    File::print();
    Dir::print();
    cout << "----------------" << endl;
    for(int i = 0; i < items.size(); i++) {
        items[i]->print();
    }
    
}

unsigned int Item::get_size() const {
    return size;
}


