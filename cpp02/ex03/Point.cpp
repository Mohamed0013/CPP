#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {}

Point &Point::operator=(const Point &point)
{
    // (void)point;
    return (*this);
}

Point::~Point() {}

Fixed Point::cross_product( Point const a, Point const b, Point const point )
{
    Fixed	x1 = b.getX() - a.getX();
	Fixed	y1 = b.getY() - a.getY();
	Fixed	x2 = point.getX() - a.getX();
	Fixed	y2 = point.getY() - a.getY();

	return (x1 * y2 - y1 * x2);
}

bool Point::bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed res1, res2, res3;

	res1 = cross_product(a, b, point);
	res2 = cross_product(b, c, point);
	res3 = cross_product(c, a, point);

	return ((res1 > 0 && res2 > 0 && res3 > 0) || (res1 < 0 && res2 < 0 && res3 < 0));
}

Fixed	Point::getX() const
{
	return (this->_x);
}

Fixed	Point::getY() const
{
	return (this->_y);
}
