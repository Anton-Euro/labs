#include "headers/dir.h"
#include <iostream>
using namespace std;

Dir::Dir(bool is_dir = false) : is_dir(is_dir) {};

void Dir::print() {
    std::cout << "Is dir: " << is_dir << endl;
}