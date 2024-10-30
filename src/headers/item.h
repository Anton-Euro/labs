#include "file.h"
#include "dir.h"

class FileMeta {
public:
    std::string name;
    unsigned long long size;
    std::string file_ext;
    std::string mime_type;
    file_list::time_point created_time;
    file_list::time_point modified_time;
    bool is_dir;

    std::string size_to_print(unsigned long long size) const;
    std::string timepoint_to_string(file_list::time_point time) const;
};

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

        std::unique_ptr<FileMeta> get_from_index(int index) {
            std::unique_ptr<FileMeta> file_meta = std::make_unique<FileMeta>();
            file_meta->name = items[index]->name;
            file_meta->size = items[index]->size;
            file_meta->file_ext = items[index]->file_ext;
            file_meta->mime_type = items[index]->mime_type;
            file_meta->created_time = items[index]->created_time;
            file_meta->modified_time = items[index]->modified_time;
            file_meta->is_dir = items[index]->is_dir;

            return std::move(file_meta);
        }

        std::shared_ptr<Item> get_ptr_from_index(int index) {
            return items[index];
        }

        void add_from_ptr(std::shared_ptr<Item> itemp) {
            items.push_back(itemp);
        }

    private:
        std::vector<std::shared_ptr<Item>> items;
};