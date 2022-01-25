#include "includes/fdf.h"

int	main (int ac, char **av)
{
	(void)ac;
	(void)av;
	double d = 124612.18;
	int i;

	i = dtoi(d);
	ft_putnbr_fd(i, 1);
	d = 15.8;
	i = dtoi(d);
	ft_putchar_fd('\t', 1);
	ft_putnbr_fd(i, 1);
}
