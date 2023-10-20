
#include "Dog.hpp"

int main()
{
	Animals* p = Factory::produce("Dog");
	p->foo();  
	delete p;
}