#ifndef DIR_H
#define DIR_H

class Dir {
    public:
        bool is_dir;

        explicit Dir(bool is_dir = false): is_dir(is_dir) {};
        Dir() = default;

        virtual void print();
};

#endif