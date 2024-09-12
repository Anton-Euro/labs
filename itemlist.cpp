#include "itemlist.h"
using namespace std;

void ItemList::init_from_dir(const fs::path& path) {
    if (fs::is_directory(path)) {
        for (const auto& entry : fs::directory_iterator(path)) {
            if (fs::is_directory(entry)) {
                init_from_dir(entry.path());
            } else {
                items.push_back(make_unique<Item>());
                items[items.size()-1]->init_from_file(entry.path());
            }
        }
    }
}

void ItemList::print_all() const {
    for(auto &el : items) {
        cout << endl;
        el->print();
    }
}

void ItemList::clear() {
    items.clear();
}

void ItemList::append(unique_ptr<Item> item) {
    items.push_back(move(item));
}

ItemList::~ItemList() {
    clear();
}

ItemList::ItemList(const ItemList& other) {
    for (const auto& item : other.items)
        items.push_back(std::make_unique<Item>(*item));
}