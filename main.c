/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:03:38 by njaros            #+#    #+#             */
/*   Updated: 2022/01/25 10:26:14 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	puterror(int error)
{
	ft_putstr_fd(strerror(error), 2);
	return (error);
}

int	main(int ac, char **av)
{
	int		fd;
	int		linesize_or_error;
	t_list	*map;

	if (ac < 2)
		return (puterror(5));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (puterror(9));
	map = fill_lst(fd);
	if (!map)
		return (puterror(11));
	linesize_or_error = parsing_map(map);
	if (linesize_or_error > 0)
	{
		ft_lstclear(&map, free);
		return (puterror(linesize_or_error));
	}
	ft_putendl_fd("map OK", 1);
	return (fdf(&map, -linesize_or_error));
}
