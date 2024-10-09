class Dir {
    public:
        bool is_dir;

        explicit Dir(bool is_dir);
        Dir() = default;

        virtual void print();
};