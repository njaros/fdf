#include "includes/fdf.h"

int	main (int ac, char **av)
{
	int	fd;
	t_list	*map;
	char	*pixel;
	int	i;

	i = 0;
	pixel = NULL;
	fd = open(av[1], O_RDONLY);
	map = fill_lst(fd);
	while (map)
	{
		ft_putnbr_fd(++i, 1);
		ft_putendl_fd(" est la ligne lue", 1);
		pixel = map->content;
		while (pixel)
		{
			ft_putnbr_fd(ft_atoi(pixel), 1);
			ft_putstr_fd("col: ", 1);
			ft_putnbr_fd(color_search(pixel), 1);
			ft_putchar_fd(' ', 1);
			pixel = next_pixel(pixel);
		}
		next_line(&map);
	}
	//ft_putchar_fd('\n', 1);
	close(fd);
	return (0);
}