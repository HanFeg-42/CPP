#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed( int const value ) : _value(value << _fractionalBits) {
}

Fixed::Fixed( float const value ) : _value(roundf(value * (1 << _fractionalBits))) {
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this == &other)
		return *this;
	_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

int	Fixed::getRawBits( void ) const
{
	return _value;
}

void	Fixed::setRawBits( int const raw )
{
	_value = raw;
}

int	Fixed::toInt( void ) const
{
	return (_value >> _fractionalBits);
}

float	Fixed::toFloat( void ) const
{
	return (float)_value / (1 << _fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
