#pragma once

#include <iostream>
#include <stack>
#include <string>

class RPN
{
private:
	std::stack<int> s;
public:
	RPN();
	~RPN();
	int evaluate(const std::string& expression);
};
