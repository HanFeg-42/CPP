#pragma once

#include "Fixed.hpp"

class Point {
private	:
	Fixed const	_x;
	Fixed const	_y;
public	:
	Point();
	~Point();
	Point(const float x, const float y);
	Point(const Fixed& other);
	Point& operator=(const Fixed& other);
}

bool bsp( Point const a, Point const b, Point const c, Point const point);
