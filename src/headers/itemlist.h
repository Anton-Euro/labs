#include "item.h"
#include <memory>

class ItemList {
    private:
        std::vector<std::unique_ptr<Item>> items;
    public:
        ItemList() = default;
        ~ItemList();
        ItemList(const ItemList &other);
        ItemList& operator=(const ItemList& other) {
            if (this != &other) {
                clear();
                for (const auto& item : other.items) {
                    items.push_back(std::make_unique<Item>(*item));
                }
            }
            return *this;
        }

        void init_from_dir(const fs::path& path);
        void print_all() const;
        void clear();
        void append(std::unique_ptr<Item> Item);
        unsigned int get_size();
        Item* get_from_index(unsigned int index); 
        void sort();
};