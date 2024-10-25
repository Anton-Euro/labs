#include "file.h"
#include "dir.h"

class Item : public File, public Dir {
    friend class ItemList;
    public:
        Item(const std::string &name, unsigned long long size, 
            const std::string &file_ext = "",
            const std::string &type = "",
            const std::string &mime_type = "",
            file_list::time_point created_time = std::chrono::system_clock::now(),
            file_list::time_point modified_time = std::chrono::system_clock::now(),
            bool is_dir = false
        );
        Item(): File(), Dir(false) {};

        bool operator == (const Item &item) const {
            return size == item.get_size();
        }

        bool operator > (const Item &item) const {
            return size > item.get_size();
        }

        bool operator < (const Item &item) const {
            return size < item.get_size();
        }

        unsigned int get_size() const final;
        void print() final;
        unsigned int get_len() const {
            return items.size();
        }

        std::string get_name(int index) {
            return items[index]->name;
        }

        std::string get_ext(int index) {
            return items[index]->file_ext;
        }

        bool get_isdir(int index) {
            return items[index]->is_dir;
        }

    private:
        std::vector<std::unique_ptr<Item>> items;
};