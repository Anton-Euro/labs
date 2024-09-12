#include "itemlist.h"

void ItemList::init_from_dir(const fs::path& path) {
    if (fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_directory(entry)) {
                init_from_dir(entry.path());
            } else {
                items.push_back(new Item);
                items[items.size()-1]->init_from_file(entry.path());
            }
        }
    }
}

void ItemList::print_all() {
    for(Item *el : items) {
        cout << endl;
        el->print();
    }
}

void ItemList::clear() {
    for(Item *el : items) {
        delete el;
    }
    items.clear();
}

void ItemList::append(Item *item) {
    items.push_back(item);
}

ItemList::~ItemList() {
    clear();
}