#include "RPN.hpp"

#include <array>
#include <sstream>
#include <stdexcept>

RPN::RPN() {}
RPN::~RPN() { this->clearStack(); }

auto	RPN::clearStack() -> void
{
	while (!_stack.empty())
		static_cast<void>(_stack.pop());
}

auto	RPN::whichOperator( const char& c ) -> int
{
	static std::array<char, 5>	ops{'+', '-', '/', '*'};

	for (size_t idx = 0; idx < ops.size(); ++idx)
	{
		if (ops[idx] == c)
			return (idx);
	}
	return (-1);
}

auto	RPN::stackTopPop() -> int
{
	int temp;

	if (_stack.empty())
		throw (std::runtime_error("Error"));
	temp = _stack.top();
	_stack.pop();

	return (temp);
}

auto	RPN::applyOperator( const int& type ) -> void
{
	int	right, left, result;

	right = stackTopPop();
	left = stackTopPop();
	switch (type)
	{
		case 0:
			result = left + right;
			break;
		case 1:
			result = left - right;
			break;
		case 2:
			if (right == 0)
				throw (std::logic_error("Error: division by zero"));
			result = left / right;
			break;
		case 3:
			result = left * right;
			break;
		default:
			throw (std::runtime_error("Error"));
	}
	_stack.push(result);
}

auto	RPN::launchRPN( const std::string& data ) -> int
{
	std::istringstream	ss(data);
	int					valInt;
	char				valChar;
	std::string			temp;

	if (!ss)
		throw (std::runtime_error("Error"));

	this->clearStack();

	while (!ss.eof())
	{
		ss >> temp;

		if (ss.fail())
			throw (std::runtime_error("Error"));
		if (temp.empty())
			continue ;

		try
		{
			valInt = std::stoi(temp);
			_stack.push(valInt);
		}
		catch(...)
		{
			valChar = temp[0];
			if (whichOperator(valChar) != -1)
				applyOperator(whichOperator(valChar));
			else
				throw (std::runtime_error("Error"));
		}
	}
	if (_stack.empty())
		throw (std::runtime_error("Error"));
	valInt = _stack.top();
	_stack.pop();
	if (!_stack.empty())
		throw (std::runtime_error("Error"));
	return (valInt);
}
