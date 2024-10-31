#include <stdexcept>
#include <exception>

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
class Stack {
private:
    std::unique_ptr<T[]> data;          
    int top;         
    int capacity;    

public:
    Stack(int size = 10) : top(-1), capacity(size) {
        data = std::make_unique<T[]>(capacity);
    }

    void push(const T& value) {
        if (isFull()) {
            throw MyException("Stack overflow");
        }
        data[++top] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw MyException("Stack underflow");
        }
        --top;
    }

    T peek() const {
        if (isEmpty()) {
            throw MyException("Stack is empty");
        }
        return data[top];
    }

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == capacity - 1;
    }

    int size() const {
        return top + 1;
    }
};
