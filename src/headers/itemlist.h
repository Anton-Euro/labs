#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <memory>

class ItemList {
    friend class QListViewExplorerModel;
    public:
        ItemList(): itemlistt(std::make_unique<Item>("root", 0)) {};
        std::unique_ptr<Item> init_from_file(std::string path);
        void init_from_dir(const fs::path& path);
        void print_all() const;

    private:
        std::unique_ptr<Item> itemlistt;

        void init_from_dir_req(const fs::path& path, Item *item_ptr);
        
};

#endif