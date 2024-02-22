#include "stack.hpp"
#include <stdexcept>
#include <cstdlib>

namespace stack {
    template<typename T>
    Stack<T>::Stack() : 
    _size(0), _capacity(0), _data(nullptr) {}

    template<typename T>
    Stack<T>::Stack(const Stack& other) : 
    Stack() {
        if (other._data == nullptr) {
            _data = nullptr;
            return;
        }

        reserve(other._capacity);
        _size = other._size;
        for (int64_t i = 0; i < _size; ++i) {
            _data[i] = other._data[i];
        }
    }

    template<typename T>
    Stack<T>::Stack(Stack&& other) : 
    _size(other._size), _capacity(other._capacity) {
        if (other._data == nullptr) {
            _data = nullptr;
            return;
        }
        _data = other._data;
        other._data = nullptr;
        other._size = 0;
        other._capacity = 0;
    }

    template<typename T>
    Stack<T>::~Stack() {
        delete[] _data;
        _data = nullptr;
    }

    template<typename T>
    void Stack<T>::push(const T& value) {
        if (_data == nullptr) {
            reserve(MIN_CAPACITY);
        }
        else if (_size == _capacity) {
            reserve((_capacity >> 1) * 3);
        }
        _data[_size] = value;
        ++_size;
    }

    template<typename T>
    void Stack<T>::reserve(int64_t size) {
        if (_data == nullptr) {
            _data = (T*)malloc(size * sizeof(T));
            if (_data == NULL) {
                throw std::runtime_error("Can not allocate memory");
            }
        } else {
            T* tmp = (T*)realloc(_data, size * sizeof(T));
            if (tmp == NULL) {
                throw std::runtime_error("Can not allocate memory");
            }
            _data = tmp;
        }
        _capacity = size;
    }

    template<typename T>
    void Stack<T>::pop() {
        if (!_size) {
            throw std::out_of_range("Stack is empty");
        }
        --_size;
    }

    template<typename T>
    T& Stack<T>::top() const {
        if (!_size) {
            throw std::out_of_range("Stack is empty");;
        }
        return _data[_size - 1];
    }
    
    template<typename T>
    void Stack<T>::clear() {
        delete[] _data;
        _data = nullptr;
        _size = _capacity = 0;
    }

    template<typename T>
    int64_t Stack<T>::size1() const {
        return _size;
    }

    template<typename T>
    bool Stack<T>::is_empty() const {
        return _size == 0;
    }
} // namespace stack