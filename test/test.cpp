#include <iostream>
#include <shared_ptr.hpp>

class Entity
{
	int x, y;
	std::string name;

public:
	Entity(int xp, int yp, std::string n)
		: x(xp), y(yp), name(n)
	{
		std::cout << "Initialized " << name << std::endl;
	}

	void print() const
	{
		std::cout << name << "( " << x << ", " << y << ")" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed " << name << std::endl;
	}
};

int main()
{
	std::cin.get();
}
