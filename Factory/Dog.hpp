#pragma once

#include "Factory.hpp"
#include "Animals.hpp"

class Dog : public Animals
{
public:

	Dog(){}

	~Dog()
	{
	}

	virtual void foo() override
	{
		std::cout << "Dog" << std::endl;
	}
};

REGISTER_MESSAGE(Dog, "Dog");