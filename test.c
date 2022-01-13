#include "includes/fdf.h"

int	main (int ac, char **av)
{
	ft_putnbr_fd(color_search(av[1]), 1);
	ft_putchar_fd('\n', 1);
	return (0);
}