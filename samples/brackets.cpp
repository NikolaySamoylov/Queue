#include <iostream>
#include "queue.h"
#include <string>

bool expression_is_correct(const std::string& expression)
{
	Stack<char> s;
	char paired_bracket = ' ';
	for (size_t i = 0; i < expression.size(); i++)
		if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{'))
		{
			s.push(expression[i]);
		}
		else
			if ((expression[i] == ')') || (expression[i] == ']') || (expression[i] == '}'))
			{
				if (expression[i] == ')')
					paired_bracket = '(';
				if (expression[i] == ']')
					paired_bracket = '[';
				if (expression[i] == '}')
					paired_bracket = '{';
				if ((s.empty() == false) && (s.top() == paired_bracket))
					s.pop();
				else
					return false;
			}
		return s.empty();
}

int main(int argc, char** argv)
{
	std::cout << expression_is_correct(argv[1]) << std::endl;
	return 0;
}