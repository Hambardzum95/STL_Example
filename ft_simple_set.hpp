#ifndef FT_SIMPLE_SET_HPP
#define FT_SIMPLE_SET_HPP

#include <iostream>

namespace ft
{

template<typename T>
class set
    {
    private:
        class Node
        {   public:
            T m_data;
            Node* m_next;
            Node(T data, Node* next)
            {
                m_data = data;
                m_next = next;
            }
            ~Node(){delete m_next;}
        };
        Node* m_head;
        Node* m_tail;
        int m_size;
        public:
        set()
        {   
            m_head = NULL;
            m_tail = NULL;
            m_size = 0;
        }
        ~set()
        {
            Node* temp = m_head;
            while(temp!= NULL)
            {
                Node* next = temp->m_next;
                delete temp;
                temp = next;
            }
        }
        set& operator=(const & src)
        {
            if(this == &src)
                return *this;
            Node* temp = m_head;
            while(temp!= NULL)
            {
                Node* next = temp->m_next;
                delete temp;
                temp = next;
            }
            m_head = NULL;
            m_tail = NULL;
            m_size = 0;
            Node* p = m_head;
            while(p != NULL)
            {
                insert(p->m_data);
                p = p->m_next;
            }
            return *this;
        }
        T& insert(T data)
        {
            if(m_head == NULL)
            {
                m_head = new Node(data, NULL);
                m_tail = m_head;
                ++m_size;
            }
            Node* p = m_head;
            while(p->m_next != NULL)
            {
                if(p->m_next->m_data == data)
                    return 0;
                p = p->m_next;
            }
            p->m_next = new Node(data, NULL);
            ++m_size;
            }
            T& erase(T data)
            {
                if(m_head == NULL)
                    return 0;
                Node* p = m_head;
                if(p->m_data == data)
                {
                    m_head = p->m_next;
                    delete p;
                    --m_size;
                }
                while(p->m_next != NULL)
                {
                    if(p->m_next->m_data == data)
                    {
                        Node* q = p->m_next;
                        p->m_next = p->m_next->m_next;
                        delete q;
                        --m_size;
                    }
                    p = p->m_next;
                }
            }
            T& print()
            {
                if(m_head == NULL)
                    return 0;
                Node* p = m_head;
                while(p->m_next != NULL)
                {
                    std :: cout<<p->m_data<<" ";
                    p = p->m_next;
                }
                std :: cout<<p->m_data;
            }
            int Get_size()
            {
                return m_size;
            }
            T& insert_after(T data, T x)
            {
                if(m_head == NULL)
                    return 0;
                Node* p = m_head;
                while(p->m_next != NULL)
                {
                    if(p->m_next->m_data == data)
                    {
                        Node* q = new Node(x);
                        q->m_next = p->m_next;
                        p->m_next = q;
                        ++m_size;
                    }
                    p = p->m_next;
                }
                if(p->m_data == data)
                {
                    Node* q = new Node(x);
                    q->m_next = p->m_next;
                    p->m_next = q;
                    ++m_size;
                }
            }
            T& insert_before(T data, T x)
            {
                if(m_head == NULL)
                    return 0;
                Node* p = m_head;
                while(p->m_next != NULL)
                {
                    if(p->m_next->m_data == data)
                    {
                        Node* q = new Node(x);
                        q->m_next = p->m_next;
                        p->m_next = q;
                        ++m_size;
                    }
                        p = p->m_next;
                }
                if(p->m_data == data)
                {
                    Node* q = new Node(x);
                    q->m_next = p->m_next;
                    p->m_next = q;
                    ++m_size;
                }
            }
            T& clear()
            {
                if(m_head == NULL)
                    return 0;
                Node* p = m_head;
                Node* q;
                while(p != NULL)
                {
                    q = p;
                    p = p->m_next;
                    delete q;
                }
                    m_head = NULL;
                    m_tail = NULL;
                    m_size = 0;
            }
            void swap();
            bool empty();
};
    template <typename T>
    void set<T> :: swap()
    {
        Node* p = m_head;
        Node* q = m_tail;
        m_head = q;
        m_tail = p;
    }

    template <typename T>
    bool set<T> :: empty()
    {
        if(m_head == NULL)
            return true;
        return false;
    }
} // namespace ft
#endif