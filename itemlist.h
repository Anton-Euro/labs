#include "item.h"

class ItemList {
    private:
        vector<Item*> items;
    public:
        ~ItemList();

        void init_from_dir(const fs::path& path);
        void print_all() const;
        void clear();
        void append(Item *item);
};