#include "item.h"
#include <memory>

class ItemList {
    private:
        vector<unique_ptr<Item>> items;
    public:
        ~ItemList();

        void init_from_dir(const fs::path& path);
        void print_all() const;
        void clear();
        void append(unique_ptr<Item> Item);
};