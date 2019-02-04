#include "libft.h"

int ft_pow(int nbr, unsigned int pow)
{
	int res;

	res = 1;
	while (pow--)
		res *= nbr;
	return (res);
}