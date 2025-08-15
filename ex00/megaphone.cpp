#include <iostream>
#include <string>
#include <cctype>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
		return (0);
	}
	for (int j = 1; j < ac; j++)
	{
		std::string str(av[j]);
		for (unsigned int i = 0; i < str.length(); i++)
		{
			std::cout << (char)toupper(str[i]);
		}
	}
	std::cout << std::endl;
	return (0);
}