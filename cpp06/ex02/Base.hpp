#pragma once

#include <random>
#include <iostream>

class Base
{
	public:
		virtual ~Base();

		Base*	generate();
		void	identify( Base* p );
		void	identify( Base& p );
};
