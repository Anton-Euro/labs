#include "headers/file.h"
using namespace std;

File::File(const string &name, unsigned long long size, 
    const string &file_ext,
    const string &type,
    const string &mime_type,
    file_list::time_point created_time,
    file_list::time_point modified_time
) : name(name), size(size), file_ext(file_ext), type(type), mime_type(mime_type), created_time(created_time), modified_time(modified_time) {}



void File::init_from_console() {
    do {
        cout << "enter file name: ";
        cin >> name;
    } while(is_bed_name());
    cout << "enter file size: ";
    cin >> size;
    cout << "enter file extension: ";
    cin >> file_ext;

    type = "";
    mime_type = "";
    created_time = chrono::system_clock::now();
    modified_time = chrono::system_clock::now();

}

void File::print() {
    cout << "name: " << name << endl;
    cout << "file extension: " << file_ext << endl;
    cout << "size: " << size_to_print() << endl;
    
    cout << "created time: " << timepoint_to_string(created_time) << endl;
    cout << "modified time: " << timepoint_to_string(modified_time) << endl;
}






string File::timepoint_to_string(file_list::time_point time) const {
    time_t timeT = chrono::system_clock::to_time_t(time);
    tm tm;
    localtime_r(&timeT, &tm);
    ostringstream oss;
    oss << put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

bool File::is_bed_name() const {
    string bed_symbol = R"(\/:*?"<>|)";
    if(name.empty()) return true;
    for(char name_el : name) {
        for(char bed_symbol_el : bed_symbol)
            if(name_el == bed_symbol_el) return true;
    }
    return false;
}

const unsigned int KILO = 1024;

template <typename T>
T round_t(T a) {
    return round((a / KILO) * 100.0) / 100.0;
}


string File::size_to_print() const {
    vector<string> name_size_file = {"bytes", "KB", "MB", "GB", "TB"};
    short d = 0;
    double total_size = size;
    while(total_size / KILO > 1) {
        d++;
        total_size = round_t(total_size);
    }
    string str = to_string(total_size);
    int dot_pos = str.find('.');
    str = str.substr(0, dot_pos + 3);
    return str + " " + name_size_file[d];
}