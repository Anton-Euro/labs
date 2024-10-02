#include "headers/itemlist.h"
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
    for(int i = 0; i < items.size(); i++) {
        cout << endl;
        cout << "Index: " << i << endl;
        items[i]->print();
    }
}

unsigned int ItemList::get_size() {
    return items.size();
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
        items.push_back(make_unique<Item>(*item));
}

Item* ItemList::get_from_index(unsigned int index) {
    return items[index].get();
}

void ItemList::sort() {
    bool swapped;
    int n = items.size();

    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (*items[i] > *items[i + 1]) {
                swap(items[i], items[i + 1]);
                swapped = true;
            }
        }
        --n;
    } while (swapped);
}