#include "Point.hpp"

Fixed const getSide( Point const &a, Point const &b, Point const &p)
{
    return ((b.getX() - a.getX()) * (p.getY() - a.getY())
            - (b.getY() - a.getY()) * (p.getX() - a.getX()));
}

bool checkSide( Point const &a, Point const &b, Point const &c, Point const &point)
{
    Fixed const s1 = getSide(a, b, c);
    Fixed const s2 = getSide(a, b, point);
    
    return ((s1 > 0 && s2 > 0) || (s1 < 0 && s2 < 0)) ? true : false;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool side1 = checkSide(a, b, c, point);
    bool side2 = checkSide(a, c, b, point);
    bool side3 = checkSide(b, c, a, point);

    return (side1 && side2 && side3);
}
