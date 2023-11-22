#include "ft_printf.h"

int	ft_print_unit(int n)
{
	unsigned int	u_nbr;
	char			*nbr;

	if (n < 0)
		u_nbr = n + 1 + UINT_MAX;
	else
		u_nbr = n;
	nbr = ft_itoa(u_nbr);
	ft_putstr_fd(nbr, 1);
	return (ft_strlen(nbr));
}