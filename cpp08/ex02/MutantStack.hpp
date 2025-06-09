#pragma once

#include <stack>
#include <deque>

template<typename T, typename C = std::deque<T>>
class MutantStack : public std::stack<T, C>
{
	public:
		using iterator = C::iterator;
		using const_iterator = C::const_iterator;

		MutantStack() : std::stack<T, C>() {}
		MutantStack( const MutantStack& other ) : std::stack<T, C>(other) {}
		auto operator=( const MutantStack& other ) -> MutantStack&
		{
			if (this != &other)
				std::stack<T, C>::operator=(other);
			return (*this);
		}
		MutantStack( const MutantStack&& other ) : std::stack<T, C>(other) {}
		auto operator=( const MutantStack&& other ) -> MutantStack&
		{
			if (this != &other)
				std::stack<T, C>::operator=(other);
			return (*this);
		}
		virtual ~MutantStack() {}

		auto	begin() -> iterator { return (std::stack<T, C>::c.begin()); }
		auto	end() -> iterator { return (std::stack<T, C>::c.end()); }

		auto	cbegin() -> const_iterator { return (std::stack<T, C>::c.cbegin()); }
		auto	cend() -> const_iterator { return (std::stack<T, C>::c.cend()); }
};
