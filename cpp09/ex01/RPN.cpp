#include "RPN.hpp"
#include <cctype>
#include <sstream>

RPN::RPN()
{
}
RPN::~RPN()
{
}



int RPN::evaluate(const std::string& expression)
{
	std::stringstream   ss(expression);
	char                token;
	int a, b, result = 0;

	while (ss >> token)
	{
		if (std::isdigit(token))
			s.push(token - '0');
		else if (token == '*' || token == '+' || token == '-' || token == '/')
		{
			if (s.size() >= 2)
			{
				b = s.top();
				s.pop();
				a = s.top();
				s.pop();
			}
			else
				throw std::runtime_error("Error");
			if (token == '*')
				result = a * b;
			else if (token == '/')
			{
				if (b != 0)
					result = a / b;
				else
					throw std::runtime_error("Error");
			}
			else if (token == '+')
				result = a + b;
			else
				result = a - b;
			s.push(result);
		}
		else
			throw std::runtime_error("Error");
	}
	if (s.empty() || s.size() > 1)
		throw std::runtime_error("Error");

	return result;
}
