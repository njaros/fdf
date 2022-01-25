/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:30:36 by njaros            #+#    #+#             */
/*   Updated: 2022/01/19 16:52:42 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	fdf(t_list **map, int lg)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		ymax;
	t_point	**tab;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ymax = compteur_ligne(*map);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, lg * 10 + 100, ymax * 10 + 100, "fdf");
	tab = tab_build(map, lg, ymax);
	while (tab[y])
	{
		while (tab[y][x].exist)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, 50 + (lg / 2 + tab[y][x].x) * 10, 50 + (ymax / 2 + tab[y][x].y) * 10, tab[y][x].color);
			x++;
		}
		x = 0;
		y++;
	}
	mlx_loop(mlx_ptr);
	ft_lstclear(map, free);
	return (0);
}
