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

		auto		safeAddit( int lhs, int rhs ) const -> bool;
		auto		safeSubtr( int lhs, int rhs ) const -> bool;
		auto		safeMulti( int lhs, int rhs ) const -> bool;

	public:
		RPN();
		RPN( const RPN& ) = delete;
		auto operator=( const std::string& ) -> RPN& = delete;
		~RPN();

		auto	launchRPN( const std::string& ) -> int;
};
