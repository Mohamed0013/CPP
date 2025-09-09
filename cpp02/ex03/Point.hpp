#include "Fixed.hpp"

class Point
{
private:
    Fixed const _x;
    Fixed const _y;
public:
    Point();
    Point(const float x, const float y);
    Point(const Point &point);
    Point &operator=(const Point &point);
    Fixed getX() const;
    Fixed getY() const;
    ~Point();
    bool bsp( Point const a, Point const b, Point const c, Point const point);
    Fixed cross_product( Point const a, Point const b, Point const point);
};
