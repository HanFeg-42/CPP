#include "Span.hpp"

int genRandom()
{
	return std::rand();
}

int main()
{
	try {
		// the subject's test
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << "---------------" << std::endl;

		// stress test
		Span s(100000);
		std::vector<int> v(100000);

		std::srand(time(0));
		std::generate(v.begin(), v.end(), genRandom);
		s.addRange(v.begin(), v.end());

		std::cout << s.shortestSpan() << std::endl;
		std::cout << s.longestSpan() << std::endl;
		std::cout << "---------------" << std::endl;

		// exception test
		Span e(4);
		std::vector<int> v1(5, 9); // 5 elements all equal to 9

		e.addRange(v1.begin(), v1.end());
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}