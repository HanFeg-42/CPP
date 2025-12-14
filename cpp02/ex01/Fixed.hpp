#pragma once
#include <iostream>
#include <cmath>

class	Fixed {
private	:
	int	_value;
	static const int	_fractionalBits;

public	:
	Fixed();
	~Fixed();
	Fixed( int const value );
	Fixed( float const value );
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);	

	int	getRawBits( void ) const;
	void	setRawBits( int const raw );
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

