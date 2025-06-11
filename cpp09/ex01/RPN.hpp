#pragma once

#include <stack>
#include <iostream>

class RPN
{
	private:
		std::stack<int>	_stack;

		auto		clearStack() -> void;
		auto		applyOperator( const int& ) -> void;
		static auto	whichOperator( const char& ) -> int;
		auto		stackTopPop() -> int;

	public:
		RPN();
		RPN( const RPN& ) = delete;
		auto operator=( const std::string& ) -> RPN& = delete;
		~RPN();

		auto	launchRPN( const std::string& ) -> int;
};
