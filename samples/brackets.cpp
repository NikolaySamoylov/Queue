#include <iostream>
#include "queue.h"
#include <string>

bool expression_is_correct(const std::string& expression)
{
	Stack<char> s;
	char paired_bracket = ' ';
	bool result = true;
	int presence_of_expression_with_opening_brackets = 0;
	for (size_t i = 0; i < expression.size(); i++)
		if ((expression[i] == '(') || (expression[i] == '[') || (expression[i] == '{'))
		{
			s.push(expression[i]);
			presence_of_expression_with_opening_brackets++;
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
	if (presence_of_expression_with_opening_brackets == 0)
		return false;
	if (s.empty() == true)
		return result;
	else
		return !result;
}

int main(int argc, char** argv)
{
	std::cout << expression_is_correct(argv[1]) << std::endl;
	return 0;
}