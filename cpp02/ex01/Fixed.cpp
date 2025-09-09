#include "Fixed.hpp"

Fixed::Fixed() : _fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->setRawBits(fixed.getRawBits());
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int		Fixed::getRawBits(void) const
{
	return (this->_fpValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

Fixed::Fixed(int const toconv) : _fpValue(toconv << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const toconv) : _fpValue(roundf(toconv * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fpValue / (1 << _bits));
}

int Fixed::toInt(void) const
{
	return (this->_fpValue >> _bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}