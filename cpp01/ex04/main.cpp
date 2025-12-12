#include <iostream>
#include <iostream>
#include <fstream>
#include <string>

std::string replace(std::string line, std::string s1, std::string s2)
{
	std::string ret;
	size_t start = 0;

	if (s1.empty())
		return (line);
	size_t pos = line.find(s1);
	while (pos != std::string::npos)
	{
		ret.append(line, start, pos - start);
		ret.append(s2);
		start = pos + s1.length();
		pos = line.find(s1, start);
	}
	ret.append(line, start, std::string::npos);
	return (ret);
}

int	main(int ac, char *av[])
{
	std::string	filename;
	if (ac != 4)
	{
		std::cerr << "Error : Invalid argument" << std::endl;
		return 1;
	}
	filename = av[1];
	std::ofstream outFile((filename + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cout << "Error : Opening file for writing" << std::endl;
		return 1;
	}
	std::ifstream inFile(av[1]);
	if (!inFile.is_open())
	{
		std::cout << "Error : Opening file for reading" << std::endl;
		return 1;
	}
	std::string line;
	std::string newLine;
	while (std::getline(inFile, line))
	{
		newLine = replace(line, av[2], av[3]);
		outFile << newLine << std::endl;
	}
	outFile.close();
	inFile.close();
	return 0;		
}

