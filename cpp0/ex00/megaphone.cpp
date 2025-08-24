#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int j = 1; j < ac; j++)
		{
			std::string str(av[j]);
			for (size_t i = 0; i < str.length(); i++)
				std::cout << (char)std::toupper(str[i]);
		}
	}
	std::cout << std::endl;
	return (0);
}