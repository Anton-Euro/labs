#include "headers/itemlist.h"
using namespace std;

std::shared_ptr<Item> ItemList::init_from_file(string path) {
    auto new_item = std::make_shared<Item>();
    fs::path file_path = path;
    if (fs::exists(file_path) && fs::is_regular_file(file_path)) {
        new_item->size = fs::file_size(file_path);

        // for macos
        struct stat fileInfo;
        stat(path.c_str(), &fileInfo);
        new_item->modified_time = chrono::system_clock::from_time_t(fileInfo.st_mtime);
        new_item->created_time = chrono::system_clock::from_time_t(fileInfo.st_birthtime);

        // for windows soon...

        string filename = file_path.filename();

        short dot_pos = filename.rfind('.');
        if (dot_pos <= 0) {
            new_item->name = filename;
            new_item->file_ext = "";
        } else {
            new_item->name = filename.substr(0, dot_pos);
            new_item->file_ext = filename.substr(dot_pos + 1);
        }
 
        new_item->type = "file";

        new_item->mime_type = "";
    } else {
        std::cout << "file not exists" << std::endl;
    }
    return new_item;
}



void ItemList::init_from_dir_req(const fs::path& path, std::shared_ptr<Item> item_ptr) {
    if (fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_directory(entry)) {
                struct stat fileInfo;
                stat(path.c_str(), &fileInfo);
                item_ptr->items.push_back(std::make_shared<Item>(entry.path().filename(), 0, "", "dir", "", chrono::system_clock::from_time_t(fileInfo.st_birthtime), chrono::system_clock::from_time_t(fileInfo.st_mtime), true));
                init_from_dir_req(entry.path(), item_ptr->items.back());
            } else {
                item_ptr->items.push_back(init_from_file(entry.path()));
            }
        }
    }
}

void ItemList::init_from_dir(const fs::path& path) {
    list->items.clear();
    current_dir = list;
    init_from_dir_req(path, list);
}

void ItemList::print_all() const {
    list->print();
}
