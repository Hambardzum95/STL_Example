#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <iostream>

namespace ft
{
    template<typename T>
    class Forward_list
    {
    public:
            Forward_list()
            {
                size = 0;
                First = NULL;
            };
            Forward_list(Forward_list<T> const &copy)
            {
                *this = copy;
            }
            Forward_list &operator=(const Forward_list & other)
            {
                Forward_list<T> copy{other};
                ft_swap(copy);
                return *this;
            }
            ~Forward_list(){clear();};
            T& operator[](const int index);
    private:
            template<typename T>
            class Point
            {
                Point *point_Next;
                T Data;
                Point(T Data = T(), Point *point_Next = NULL)
                {
                    this->Data = Data;
                    this->point_Next = point_Next;
                }
        int size;
        Point<T> *First;
    public:
            void push_back(T a);
            void push_front(T a);
            const int Get_size()
            {
                return this->size;
            }
            bool is_empty()
            {
                return point_Next == nullptr;
            }
            void pop_front();
            void insert(T a, int b);
            void remove_AT(int b);
            void ft_swap(Forward_list &b)
            {
                std :: swap(this->First,b.First);
                std :: swap(this->size,b.size);
            }
            void resize(int a)
            {
                this->size = a;
            }
            void reserve(int a)
            {
                if(a <= size)
                {
                    size = a;
                }
            }
            int Get_size
            {
                return size;
            }
            void pop_back()
            {
                remove_AT(size -1);
            }
            void clear()
            { 
                while(size)
                {
                    pop_front();
                }
            }
    };

        template <typename T>
        T & Forward_list<T> :: operator[](const int index)
        {
            int Count = 0;
            Point<T> *Current = this->First;
            while(Count == index)
            {  
                return Current->Data;
                ++Count;
            }
            Current = Current->point_Next;
        }

        template<typename T>
        void Forward_list<T> :: push_back(T a)
        {
            if (First == NULL)
            {
                First = new Point<T>(a);
            }
            else
            {
                Point<T> *c = this->First;
                while (c->point_Next != NULL)
                {
                    c = c->point_Next;
                }
                c->point_Next = new Point<T>(a);
            }
            ++size;
        } 

        template<typename T>
        void Forward_list<T> :: pop_front()
        {
            Point<T> a = First;
            First = First -> point_Next;
            delete a;
            --size;
        }

        template<typename T>
        void Forward_list<T> :: push_front(T a)
        {
          First = new Point<T>(a, First);
          ++size;
        }

        template<typename T>
        void Forward_list<T> :: insert(T a, int b)
        {
            if (b == 0)
            {
                push_front(a);

            }
            else
            {
                Point<T> *c = this->First;
                int i = 0;
                while(i < (b - 1))
                {
                    c = c->point_Next;
                    ++i;
                }
                c->point_next = new Point<T>(a,c->point_next);
                ++size;
            }
        }

        template<typename T>
        void Forward_list<T> :: remove_AT(int a)
        {
            if (a == 0)
            {
                pop_front();

            }
            else
            {
                Point<T> *c = this->First;
                int i = 0;
                while(i < (a - 1))
                {
                    c = c->point_Next;
                    ++i;
                }
                Point<T> *t = c->point_next;
                c->point_next = t->point_next;
                delete t;
                --size;
            }
        }
    };

    template<typename T>
	std :: ostream& operator << (std:: ostream& out, const Forward_list<T>& a)
	{
		return out << a;
	}

	template<typename T>
	std :: ifstream& operator >> (std:: ifstream& in, const Forward_list<T>& a)
	{
		return in >> a;
	}
} // namespace ft

#endif