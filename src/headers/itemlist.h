#ifndef ITEMLIST_H
#define ITEMLIST_H

#include "item.h"
#include <memory>

class ItemList {
    friend class QTableViewFilesModel;
    friend class MainWindow;
    public:
        ItemList(): list(std::make_shared<Item>("root", 0)) {current_dir = list;};
        std::shared_ptr<Item> init_from_file(std::string path);
        void init_from_dir(const fs::path& path);
        void print_all() const;

    private:
        std::shared_ptr<Item> list;
        std::shared_ptr<Item> current_dir;

        void init_from_dir_req(const fs::path& path, std::shared_ptr<Item> item_ptr);
        
};

#endif