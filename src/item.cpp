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





string FileMeta::size_to_print(unsigned long long size) const {
    const unsigned int KILO = 1024;
    vector<string> name_size_file = {"bytes", "KB", "MB", "GB", "TB"};
    short d = 0;
    double total_size = size;
    while(total_size / KILO > 1) {
        d++;
        total_size = round((total_size / KILO) * 100.0) / 100.0;
    }
    string str = to_string(total_size);
    int dot_pos = str.find('.');
    str = str.substr(0, dot_pos + 3);
    return str + " " + name_size_file[d];
}


std::string FileMeta::timepoint_to_string(file_list::time_point time) const {
    time_t timeT = chrono::system_clock::to_time_t(time);
    tm tm;
    localtime_r(&timeT, &tm);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}