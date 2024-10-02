#include "headers/itemlist.h"
#include "headers/friend.h"
using namespace std;

int main() {
    ItemList items;
    short choice = -1;
    while(choice != 0) {
        cout << "---------------------------------\n";
        cout << "1 - init list from dir\n2 - init item from file\n3 - init item from console\n4 - print all items\n5 - clear item list\n6 - print item from friend func\n7 - sort items from size\n0 - exit\nSelect choose: ";
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
        } else if(choice == 6) {
            items.print_all();
            unsigned int index = -1;
            while(index < 0 || index > items.get_size()) {
                cout << "Enter item index: ";
                cin >> index;
            }
            Item* ptr = items.get_from_index(index);
            cout << size_to_print(*ptr) << endl;
        } else if(choice == 7) {
            items.sort();
        }
    }
    return 0;
}