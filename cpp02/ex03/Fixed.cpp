#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
}

Fixed::Fixed( int const value ) : _value(value << _fractionalBits) {
}

Fixed::Fixed( float const value ) : _value(roundf(value * (1 << _fractionalBits))) {
}

Fixed::~Fixed() {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this == &other)
		return *this;
	_value = other.getRawBits();
	return *this;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {}

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

bool    Fixed::operator<(const Fixed& a) const
{
	return (_value < a._value);
}

bool    Fixed::operator>(const Fixed& a) const
{
	return (_value > a._value);
}

bool    Fixed::operator<=(const Fixed& a) const
{
	return (_value <= a._value);
}

bool    Fixed::operator>=(const Fixed& a) const
{
	return (_value >= a._value);
}

bool    Fixed::operator==(const Fixed& a) const
{
	return (_value == a._value);
}

bool    Fixed::operator!=(const Fixed& a) const
{
	return (_value != a._value);
}

Fixed   Fixed::operator+(const Fixed& a) const
{
	Fixed add;
	
	add.setRawBits(_value + a._value);
	return (add);
}

Fixed   Fixed::operator-(const Fixed& a) const
{
	Fixed sub;
	
	sub.setRawBits(_value - a._value);
	return (sub);
}

Fixed   Fixed::operator*(const Fixed& a) const
{
	Fixed mult(this->toFloat() * a.toFloat());
	return (mult);
}

Fixed   Fixed::operator/(const Fixed& a) const
{
	Fixed div(this->toFloat() / a.toFloat());
	return (div);
}

Fixed&	Fixed::operator++( void )
{
	_value++;
	return *this;
}

Fixed&	Fixed::operator--( void )
{
	_value--;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed	old = *this;
	_value++;
	return old;
}

Fixed	Fixed::operator--( int )
{
	Fixed	old = *this;
	_value--;
	return old;
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a._value > b._value) ? b : a;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a._value > b._value) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a._value > b._value) ? b : a; 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a._value > b._value) ? a : b; 
}
