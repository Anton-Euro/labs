#include "file.h"
#include "dir.h"

class Item : public File, public Dir {
    public:
        Item(const std::string &name, unsigned long long size, 
            const std::string &file_ext,
            const std::string &type,
            const std::string &mime_type,
            time_point created_time,
            time_point modified_time,
            bool is_dir
        );
        Item() = default;

        bool operator == (const Item &item) const {
            return size == item.get_size();
        }

        bool operator > (const Item &item) const {
            return size > item.get_size();
        }

        bool operator < (const Item &item) const {
            return size < item.get_size();
        }

        unsigned int get_size() const;
        void print();
};