/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:30:36 by njaros            #+#    #+#             */
/*   Updated: 2022/01/17 10:43:06 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	fdf(t_list **map, int lg)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_list	*first;
	int		hauteur;
	int		pix_h;
	int		pix_c;
	int		x;
	int		y;
	char	*pixel;
	int		centre[2];

	x = 0;
	y = 0;
	ft_putnbr_fd(lg, 1);
	hauteur = compteur_ligne(*map);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(hauteur, 1);
	centre[0] = lg * 5 + 50;
	centre[1] = hauteur * 5 + 50;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, lg * 10 + 100, hauteur * 10 + 100, "fdf");
	first = *map;
	while (*map)
	{
		pixel = (*map)->content;
		while (pixel)
		{
			pix_h = ft_atoi(pixel);
			pix_c = color_search(pixel);
			/*ft_putnbr_fd(pix_h, 1);
			ft_putstr_fd(" color : ", 1);
			ft_putnbr_fd(pix_c, 1);
			ft_putchar_fd(' ', 1);*/
			mlx_pixel_put(mlx_ptr, win_ptr, (50 + x * 10), 50 + (y * 10) - pix_h, pix_c);
			pixel = next_pixel(pixel);
			x++;
		}
		x = 0;
		//ft_putchar_fd('\n', 1);
		*map = (*map)->next;
		y++;
	}
	mlx_loop(mlx_ptr);
	ft_lstclear(map, free);
	return (0);
}
