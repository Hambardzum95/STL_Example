#ifndef FT_STACK_HPP
#define FT_STACK_HPP

#include <iostream>

namespace ft
{
    template<typename T>
    class Stack
    {
    public:
        Stack()
        {
            size = 0;
            first = NULL;
        }
        ~Stack()
        {
            delete first;
        }
        Stack(const Stack& copy)
        {
            *this = copy;
        }
        Stack& operator=(const Stack& src)
        {
            if(&src != this)
            {
                delete first;
                size = src.size;
                first = new T[size];
                int i = 0;
                while(i < size)
                {
                    first[i] = src.first[i];
                    ++i
                }
            }
            return this;
        }
        class Inner
        {
            T *data;
            Inner* next;
            Inner(T data = T(), Inner *next = NULL)
            {
                this->next = next;
                this->data = data;
            }
            ~Inner()
            {
                delete next;
            }
        };
    private:
        Inner *first;
        int size;
    public:
        void push(T data);
        void pop();
        T top()const
        {
            if (first == NULL)
            {
                std :: cout << "Empty" << std :: endl;
                isEmpty();
            }
            return first->data;
        }
        int size()const
        {
            return size;
        }
        bool isEmpty()const
        {
            return (first = NULL);
        }
    };

    template <typename T>
    void Stack<T>::push(T)
    {
        Inner *new_first = new Inner(data, first);  
        ++size;
    }

    template <typename T>
    void Stack<T>::pop()
    {
        if (first == NULL)
        {
            std :: cout << "Empty" << std :: endl;
            isEmpty();
        }
        Inner * tmp = first;
        first = first->next;
        --size;
        delete tmp;
    }

    template<typename T>
    std :: ostream& operator << (std:: ostream& out, const Stack<T>& a)
    {
        return out << a;
    }

    template<typename T>
    std :: ifstream& operator >> (std:: ifstream& in, const Stack<T>& a)
    {
        return in >> a;
    }
}

#endif