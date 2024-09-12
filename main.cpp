#include "itemlist.h"

int main() {
    ItemList items;
    short choice = -1;
    while(choice != 0) {
        cout << "---------------------------------\n";
        cout << "1 - init list from dir\n2 - init item from file\n3 - init item from console\n4 - print all items\n5 - clear item list\n0 - exit\nSelect choose: ";
        cin >> choice;
        cout << "---------------------------------\n";

        if(choice == 1) {
            string path;
            cout << "Enter your path: ";
            cin >> path;
            items.init_from_dir(path);
        } else if(choice == 2) {
            string path;
            cout << "Enter path to file: ";
            cin >> path;
            auto ptr = make_unique<Item>();
            ptr->init_from_file(path);
            items.append(move(ptr));
        } else if(choice == 3) {
            auto ptr = make_unique<Item>();
            ptr->init_from_console();
            items.append(move(ptr));
        } else if(choice == 4) {
            items.print_all();
        } else if(choice == 5) {
            items.clear();
        }
    }
    return 0;
}