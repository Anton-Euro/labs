#include "item.h"


// PUBLIC


Item::Item(string name, unsigned long long size, 
    string file_ext,
    string type,
    string mime_type,
    time_t created_time,
    time_t modified_time
) {
    this->name = name;
    this->size = size;
    this->created_time = created_time;
    this->modified_time = modified_time;
    this->file_ext = file_ext;
    this->type = type;
    this->mime_type = mime_type;
}

Item::Item() {}

void Item::init_from_file(string path) {
    fs::path file_path = path;
    if (fs::exists(file_path) && fs::is_regular_file(file_path)) {
        size = fs::file_size(file_path);

        // for macos
        struct stat fileInfo;
        stat(path.c_str(), &fileInfo);
        modified_time = fileInfo.st_mtime;
        created_time = fileInfo.st_birthtime;

        // for windows
        // auto ftime = fs::last_write_time(file_path);
        // auto ctime = fs::creation_time(file_path);

        string filename = file_path.filename();

        short dot_pos = filename.rfind('.');
        if (dot_pos == -1) {
            name = filename;
            file_ext = "";
        } else {
            name = filename.substr(0, dot_pos);
            file_ext = filename.substr(dot_pos + 1);
        }

        type = "file";

        mime_type = "";
    } else {
        std::cout << "file not exists" << std::endl;
    }
}

void Item::init_from_console() {
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
    created_time = time(nullptr);
    modified_time = time(nullptr);

}

void Item::print() {
    cout << "name: " << name << endl;
    cout << "file extension: " << file_ext << endl;
    cout << "size: " << size_to_print(size) << endl;
    
    cout << "created time: " << time_to_string(created_time) << endl;
    cout << "modified time: " << time_to_string(modified_time) << endl;
}


// PRIVATE


string Item::size_to_print(unsigned long long filesize) {
    vector<string> name_size_file = {"bytes", "KB", "MB", "GB", "TB"};
    short d = 0;
    double total_size = filesize;
    while(total_size / 1024 > 1) {
        d++;
        total_size = round((total_size / 1024) * 100.0) / 100.0;
    }
    string str = to_string(total_size);
    int dot_pos = str.find('.');
    str = str.substr(0, dot_pos + 3);
    return str + " " + name_size_file[d];
}

string Item::time_to_string(time_t time) {
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localtime(&time));
    return buffer;
}

bool Item::is_bed_name() {
    char bed_symbol[] = {'/', '\\', '"'};
    for(char el : bed_symbol) {
        if(name.find(el, 0) != string::npos) return true;
    }
    return false;
}