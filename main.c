/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:03:38 by njaros            #+#    #+#             */
/*   Updated: 2022/01/13 17:44:16 by njaros           ###   ########lyon.fr   */
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
	int		err_parsing;
	t_list	*map;

	if (ac < 2)
		return (puterror(5));
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (puterror(9));
	map = fill_lst(fd);
	//ft_display(map);
	if (!map)
		return (puterror(11));
	err_parsing = parsing_map(map);
	if (err_parsing > 0)
	{
		ft_lstclear(&map, free);
		return (puterror(err_parsing));
	}
	ft_putendl_fd("map OK", 1);
	return (fdf(&map, -err_parsing));
}
