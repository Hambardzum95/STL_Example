#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

namespace ft
{
    template<typename T>
    class List
    {
        List()
        {
            head = NULL;
            tail = NULL;
            size = 0;
            cap = 1;
        }
        ~List()
        {
            clear();
        }
        class Node
        {
            T data;
            Node * pr;
            Node * next;
            Node(T data =T(), Node *next = NULL, Node *pr = NULL)
            {
                this->data = data;
                this->pr = pr; 
                this->next = next;
            }
            ~Node()
            {
                delete next;
                delete pr;
            }
        Node* head;
        Node* tail;
        int size;
        int cap;
    public:
       Node* push_front(T data)
        {
            Node* ptr = new Node(data);
            ptr->next = head;
            if (head != NULL)
            {
                head->pr = ptr;
            }
            if(tail == NULL)
            {
                tail = ptr;
            }
            head = ptr;
            ++size;
            if(cap == size)
            {
                cap = 2*cap;
            }
            return ptr;
        }
       Node*  push_back(T data)
        {
            Node* ptr = new Node(data);
            ptr->pr = tail;
            if (tail != NULL)
            {
                tail->next = ptr;
            }
            if(head == NULL)
            {
                head = ptr;
            }
            tail = ptr;
            ++size;
            if(cap == size)
            {
                cap = 2*cap;
            }
            return ptr;
        }
        void pop_front()
        {
            if(head == NULL)
            {
                return 0;
            }
            Node* ptr = head->next;
            if(ptr != NULL)
            {
                ptr->pr = NULL;
            }
            else
            {
                tail = ptr;
            }
            delete head;
            head = ptr;
            --size; 
        }
        void pop_back()
        {
            if(tail == NULL)
            {
                return 0;
            }
            Node* ptr = tail->pr;
            if(ptr != NULL)
            {
                ptr->next = NULL;
            }
            else
            {
                head = ptr;
            }
            delete tail;
            tail = ptr;
            --size; 
        }
        void erase(int i)
        {
            Node* ptr = get_AT(i);
            if(ptr == NULL)
            {
                return 0;
            }
            if(ptr-> == NULL)
            {
                pop_front()
                return 0;
            }
            if(ptr->next == NULL)
            {
                pop_back();
                return 0;
            }
            Node* l = ptr->pr;
            Node* r = ptr->next;
            l->next = r;
            r->pr = left;
            delete ptr;
            --size;
        }
        void reserve(int a)
        {
            if (a != cap)
            {
                cap = a;
            }
            else
            {
                cap= cap*2;
            }
        }
        bool empty()const
        {
            return !head;
        }
        void clear()
        { 
            while(size)
            {
                pop_front();
            }
        }
        const int Get_size()
        {
            return this->size;
        }
        const int Get_cap()
        {
            return this->cap;
        }
        Node * get_AT(int a);
        {
            Node* ptr = head;
            int i = a;
            while(i != a)
            {
                if(ptr == NULL)
                {
                    return ptr;
                }
                ptr = ptr->next;
                ++i;
            }
            return ptr;
        }
        T& operator[](int index)
        {
            return get_AT(index);
        }
        Node* insert(int i, T data)
        {
            Node* r = get_AT(i);
            if(i == NULL)
            {
                if(cap == size)
                {
                    cap = 2*cap;
                }
                ++size
                return push_back(data);
            }
            Node* l = r->pr;
            if (l == NULL)
            {
                if(cap == size)
                {
                    cap = 2*cap;
                }
                return push_front(data);
            }
            Node* ptr = new Node(data);
            ptr->pr = l;
            ptr->next = r;
            l->next = ptr;
            r->pr = ptr;
            if(cap == size)
            {
                cap = 2*cap;
            }
            return ptr;
        }
    };
};
template<typename T>
std :: ostream& operator << (std:: ostream& out, const List<T>& a)
{
    return out << a;
}

template<typename T>
std :: ifstream& operator >> (std:: ifstream& in, const List<T>& a)
{
    return in >> a;
}
} // namespace ft

#endif
