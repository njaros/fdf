/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:30:36 by njaros            #+#    #+#             */
/*   Updated: 2022/01/13 19:24:46 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	fdf(t_list **map, int lg)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		hauteur;
	int		pix_h;
	int		pix_c;
	int		x;
	int		y;
	char	*pixel;

	x = 0;
	y = 0;
	ft_putnbr_fd(lg, 1);
	hauteur = compteur_ligne(*map);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(hauteur, 1);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, lg * 10 + 100, hauteur * 10 + 100, "fdf");
	while (y <= hauteur)
	{
		while (x <= lg)
		{
			if (!pixel)
				pixel = (*map)->content;
			else
				pixel = next_pixel(pixel);
			pix_h = ft_atoi(pixel);
			pix_c = color_search(pixel);
			mlx_pixel_put(mlx_ptr, win_ptr, 50 + x * 10, 50 + (y * 10) - pix_h, pix_c);
			x++;
		}
		next_line(map);
		y++;
	}
	mlx_loop(mlx_ptr);
	ft_lstclear(map, free);
	return (0);
}
