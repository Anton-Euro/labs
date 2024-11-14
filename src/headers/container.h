#include <stdexcept>
#include <exception>
#include <string>

class MyException : public std::exception {
private:
    std::string message;
public:
    explicit MyException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

template <typename T>
class MyContainer {
private:
    T* data;
    size_t capacity;
    size_t count;

    void resize(size_t newCapacity) {
        T* newData = new T[newCapacity];
        for (size_t i = 0; i < count; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    MyContainer() : data(nullptr), capacity(0), count(0) {}

    ~MyContainer() {
        delete[] data;
    }

    void add(const T& item) {
        if (count == capacity) {
            size_t newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resize(newCapacity);
        }
        data[count++] = item;
    }

    void remove(size_t index) {
        if (index >= count) {
            throw MyException("Index out of range");
        }
        for (size_t i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }
        --count;

        if (count < capacity / 2) {
            resize(capacity / 2);
        }
    }

    size_t size() const {
        return count;
    }

    T& operator[](size_t index) {
        if (index >= count) {
            throw MyException("Index out of range");
        }
        return data[index];
    }

    class Iterator {
    private:
        T* current;

    public:
        Iterator(T* ptr) : current(ptr) {}

        T& operator*() const {
            return *current;
        }

        Iterator& operator++() {
            ++current;
            return *this;
        }

        bool operator==(const Iterator& other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator& other) const {
            return current != other.current;
        }
    };

    Iterator begin() {
        return Iterator(data);
    }

    Iterator end() {
        return Iterator(data + count);
    }
};
