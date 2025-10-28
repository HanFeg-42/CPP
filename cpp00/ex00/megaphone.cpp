#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	int i = 1;
	int j;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{	
			std::cout << (char)(std::toupper(av[i][j]));
			// std::cout << static_cast<char>(std::toupper(av[i][j]));
			j++;
		}
		i++;
	}
	std::cout << std::endl;
}

