#include "FT_Container_Vector.hpp"

int main()
{
	ft :: ft_vector<int> a;
	ft :: ft_vector<int> b;
	
	//a vector pop_back + push_back and emplace_back <------------------------------------------------------------------
	a.ft_emplace_back(1);
	a.ft_push_back(2);
	a.ft_push_back(3);
	a.ft_push_back(4);
	a.ft_push_back(5);
	a.ft_pop_back();

	// b vector pop_back + push_back and emplace_back <------------------------------------------------------------------
	b.ft_push_back(6);
	b.ft_emplace_back(17);
	b.ft_push_back(7);
	b.ft_push_back(8);
	b.ft_push_back(9);
	b.ft_pop_back();
	a.print();
	std :: cout << std :: endl;
	b.print();
	
	//Clear <------------------------------------------------------------------
	a.ft_clear();

	// Reserve <------------------------------------------------------------------
	a.ft_reserve(23);
	std :: cout << a.ft_capasity() << std:: endl;

	//Resize <------------------------------------------------------------------
	std :: cout << "Resize "<< std :: endl;
	std :: cout << std :: endl;
	a.ft_resize(6);
	b.ft_resize(8);
	std :: cout << "a - size: " << a.get_size() << std :: endl;
	std :: cout << "b - size: " << b.get_size() << std :: endl;
	a.print();
	std :: cout << std :: endl;
	b.print();
	std :: cout << std :: endl;
	
	//assign <------------------------------------------------------------------

	int y = 100;
	a.ft_assign(3,y);
	b.ft_assign(4,45);
	std :: cout << "Assign "<< std :: endl;
	a.print();
	b.print();

	// Empty <------------------------------------------------------------------
	if(a.ft_empty() && b.ft_empty())  
	{
		std :: cout << "Vector v is empty" << std ::endl;
	}
    else
	{
		std :: cout << "Vector v is not empty" << std :: endl;
	}

	// GetSize + Front and Back <------------------------------------------------------------------
	
	std :: cout << "a - size: " << a.get_size() << std :: endl;
	std :: cout << "b - size: " << b.get_size() << std :: endl;
	std :: cout << "a - cap: " << a.ft_capasity() << std :: endl;
	std :: cout << "b - cap: " << b.ft_capasity() << std :: endl << std :: endl;
	std :: cout << "a - print" << std :: endl;
	a.print();
	std :: cout << "b - print" << std :: endl;
	
	b.print();
	std :: cout << std :: endl << "a.front" << std :: endl;
	std :: cout << a.ft_front() << std :: endl;
	
	std :: cout << "a.back" << std :: endl;
	std :: cout << a.ft_back() << std :: endl;
	
	std :: cout << "b.front" << std :: endl;
	std :: cout << b.ft_front() << std :: endl;
	
	std :: cout << "b.back" << std :: endl;
	std :: cout << b.ft_back() << std :: endl << std :: endl;


	// Max_Size <------------------------------------------------------------------
	std :: cout << a.ft_max_size() << std :: endl << b.ft_max_size() << std :: endl;
	

	// Swap <------------------------------------------------------------------
	a.ft_swap(b);
	std :: cout << "ft_swap" << std :: endl;
	std :: cout << "a print" << std :: endl;
	
	a.print();
	std :: cout << std :: endl;
	b.print();
	std :: cout << std :: endl;
	
	std :: cout << "a - size: " << a.get_size() << std :: endl;
	std :: cout << "b - size: " << b.get_size() << std :: endl;

	std :: cout << "a - cap: " << a.ft_capasity() << std :: endl;
	std :: cout << "b - cap: " << b.ft_capasity() << std :: endl;
	
	std :: cout << "b print" << std :: endl;
	std :: cout << std :: endl;
	

	// At <------------------------------------------------------------------
	
	std :: cout << "ft_at"<<std :: endl;
	std :: cout << "a - ft_at function "<< "is a ->" << a.ft_at(2);
	std :: cout << std :: endl;
	std :: cout << "b - ft_at function "<< "is a ->" << b.ft_at(1);
	std :: cout << std :: endl;
	
	return 0;
}