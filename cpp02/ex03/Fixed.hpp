#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_fpValue;
		static const int	_bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
        Fixed(int const toconv);
        Fixed(float const toconv);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int 	toInt( void ) const;

		bool	operator>(const Fixed &fixed) const;
		bool	operator<(const Fixed &fixed) const;
		bool	operator>=(const Fixed &fixed) const;
		bool	operator<=(const Fixed &fixed) const;
		bool	operator==(const Fixed &fixed) const;
		bool	operator!=(const Fixed &fixed) const;

		Fixed	operator+(const Fixed &fixed) const;
		Fixed	operator-(const Fixed &fixed) const;
		Fixed	operator*(const Fixed &fixed) const;
		Fixed	operator/(const Fixed &fixed) const;

        Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);

		static Fixed &min(Fixed &num1, Fixed &num2);
		static const Fixed &min(Fixed const &num1, Fixed const &num2);
		static Fixed &max(Fixed &num1, Fixed &num2);
		static const Fixed &max(Fixed const &num1, Fixed const &num2);
};

std::ostream &operator<<(std::ostream &out, const Fixed& fixed);


#endif
