#include <inttypes.h>

#ifndef STACK_HPP
#define STACK_HPP

#define MIN_CAPACITY 8
namespace stack {
    template<typename T>
    class Stack {
    private:
        T* _data;
        int64_t _size;
        int64_t _capacity;
        void reserve(int64_t);
    public:
        Stack();
        Stack(const Stack&);
        Stack(Stack&&);
        ~Stack();
        Stack& operator=(const Stack&) = default;
        Stack& operator=(Stack&&) = default;
        T& top() const;
        void push(const T&);
        void pop();
        void clear();
        int64_t size1() const;
        bool is_empty() const;
    };
} // namespace stack
#endif