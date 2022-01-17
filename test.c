#include "includes/fdf.h"

int	puterror(int error)
{
	ft_putstr_fd(strerror(error), 2);
	return (error);
}

int	main (int ac, char **av)
{
	int	fd;
	t_list	*map;
	char	*pixel;
	int	xmax;
	int ymax;
	int x = -1;
	int y = -1;
	t_point	**tab;

	(void) ac;
	pixel = NULL;
	fd = open(av[1], O_RDONLY);
	map = fill_lst(fd);
	xmax = parsing_map(map);
	if (xmax > 0)
	{
		ft_lstclear(&map, free);
		return (puterror(xmax));
	}
	xmax = -xmax;
	ymax = compteur_ligne(map);
	tab = tab_build(&map, xmax, ymax);
	while (++y < ymax)
	{
		ft_putstr_fd("ligne : ", 1);
		ft_putnbr_fd(y, 1);
		ft_putchar_fd('\n', 1);
		while (++x < xmax)
		{
			ft_putstr_fd("x : ", 1);
			ft_putnbr_fd(tab[y][x].x, 1);
			ft_putstr_fd("  et y : ", 1);
			ft_putnbr_fd(tab[y][x].y, 1);
			ft_putstr_fd("  |  ", 1);
			printf(" angle xOy : %f", tab[y][x].angle2D);
		}
		x = -1;
		ft_putchar_fd('\n', 1);
	}
	freeteuse(tab, ymax);
	close(fd);
	return (0);
}
