class Dir {
    public:
        bool is_dir;

        Dir(bool is_dir);
        Dir() = default;

        virtual void print();
};