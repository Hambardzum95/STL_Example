#ifndef FT_CONTAINER_VECTOR_HPP
#define FT_CONTAINER_VECTOR_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h> 

namespace ft
{
	template<typename T>
	class ft_vector
	{
	public:
		ft_vector()
		{
			this->cap = 1;
			this->size = 0;
			this->arg = T();
			this->vector =  new T[cap];
		}
		ft_vector(T arg)
		{
			this->arg = arg;
		}
		ft_vector(ft_vector<T> const &copy)
		{
			*this = copy;
		}
		ft_vector &operator=(const ft_vector &src)
		{
			if(this != src)
			{
				this->src;
			}
			return  *this;
		}
		T &operator[](int src)
		{
			return vector[src];
		}
		~ft_vector() {delete [] vector;}
	private:
		int cap;
		int size;
		T arg;
		T *vector;
	public:
		void ft_push_back(T arg)
		{
			if (size >= cap)
			{
				cap = size * 2;
				T* tmp = new T[cap];
				int i = 0;
				while(i < size)
				{
					tmp[i] = vector[i];
					i++;
				}
				delete[] vector;
				vector = tmp;
			}
			vector[size] = arg;
			size++;
		}
		int get_size()const;
		void print();

		void ft_emplace_back(T arg);//c++11
		void ft_clear();
		int ft_capasity()
		{
			return this->cap;
		}
		void ft_pop_back();
		T & ft_at(int i);
		T & ft_back()
		{
			return vector[size - 1];
		}
		T &ft_front()
		{
			return vector[0];
		}
		void ft_swap(ft_vector &b)
		{
			std :: swap(this->vector,b.vector);
			std :: swap(this->size,b.size);
			std :: swap(this->cap,b.cap);
		}
		bool ft_empty()
		{
			if (vector != NULL)
			{
				return false;
			}
			else if (vector == NULL)
			{
				return	true;
			}
			return 0;
		}
		void ft_resize(int a)
		{
			if (a > size)
			{
				size = a;
			}
			else if(a <= size)
			{
				size = a;
			}
		}
		int ft_max_size()
		{
			return this->size;
		}
		void ft_reserve(int a)
		{
			if (a != 0 || a == cap)
			{
				cap = a;
			}
		}
		void ft_assign(int a, T b)
		{
			int i = size;
			if(size == 0 || a == 0)
			{
				size = a;
			}
			size += a;
			cap *= size;
			while(i < size)
			{
				vector[i] = b;
				i++;
			}
		}
	};
	template<typename T>
	T & ft_vector<T> :: ft_at(int i)
	{
		if (i > size -1)
		{
			std :: cout << "Error cant return i. " << i<<"-i index  > size-"<<this->size << std :: endl;
			exit(EXIT_FAILURE);
		}
			return vector[i];
	}
	template<typename T>
	int ft_vector<T> :: get_size() const
	{
		return this->size;
	}

	template<typename T>
	void ft_vector<T> :: print()
	{
		int i = 0;
		while(i < size)
		{
			std :: cout << vector[i] << std :: endl;
			i++;
		}
	}

	template<typename T>
	void  ft_vector<T> :: ft_emplace_back(T arg)
	{
		ft_push_back(arg);
	}

	template<typename T>
	void ft_vector<T> :: ft_clear()
	{
		if (vector != NULL)
		{
			delete[] vector;
		}
	}
	template<typename T>
	void ft_vector<T> :: ft_pop_back()
	{
		if (vector != NULL)
		{
			T *tmp = new T[cap];
			int i = -1;
			while(i < size - 1)
			{
				tmp[i] = vector[i];
				i++;
			}
			delete [] vector;
			vector = tmp;
		}
		size--;
	}
	
	// fstream
	template<typename T>
	std :: ostream& operator << (std:: ostream& out, const ft_vector<T>& a)
	{
		return out << a;
	}
	template<typename T>
	std :: ifstream& operator >> (std:: ifstream& in, const ft_vector<T>& a)
	{
		return in >> a;
	}
}
#endif
