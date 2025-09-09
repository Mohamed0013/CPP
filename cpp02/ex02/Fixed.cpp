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

/* Comparison Operators */

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->_fpValue > fixed.getRawBits());
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->_fpValue < fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->_fpValue >= fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->_fpValue <= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->_fpValue == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->_fpValue != fixed.getRawBits());
}


/* Arithmetic Operators */

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	if (fixed.toFloat() == 0)
		return Fixed(0);
	return Fixed(this->toFloat() / fixed.toFloat());
}

/* ++ -- */

Fixed	Fixed::operator++()
{
	this->_fpValue++;
	return (*this);
}

Fixed   Fixed::operator--()
{
    this->_fpValue--;
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp = *this;
    this->_fpValue++;
    return (tmp);
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp = *this;
    this->_fpValue--;
    return (tmp);
}

Fixed	&Fixed::min(Fixed &num1, Fixed &num2)
{
	return (num1 < num2) ? num1 : num2;
}

const Fixed	&Fixed::min(Fixed const &num1, Fixed const &num2)
{
	return (num1 < num2) ? num1 : num2;
}

Fixed	&Fixed::max(Fixed &num1, Fixed &num2)
{
	return (num1 > num2) ? num1 : num2;
}

const Fixed	&Fixed::max(Fixed const &num1, Fixed const &num2)
{
	return (num1 > num2) ? num1 : num2;
}