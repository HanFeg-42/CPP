#pragma once
#include <iostream>

class	Fixed {
private	:
	int	fixedPoint;
	static const int	fractionalBits;

public	:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	
};
