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
};

std::ostream &operator<<(std::ostream &out, const Fixed& fixed);


#endif
