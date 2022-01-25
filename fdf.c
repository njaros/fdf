/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:30:36 by njaros            #+#    #+#             */
/*   Updated: 2022/01/25 11:27:52 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	fdf(t_list **map, int lg)
{
	void	*mlx_ptr;
	t_data	img;
	int		nbr_line;
	void	*win_ptr;
	t_point	**tab;

	mlx_ptr = mlx_init();
	nbr_line = compteur_ligne(*map);
	img.img = mlx_new_image(mlx_ptr, lg * 10 + 100, nbr_line * 10 + 100);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	win_ptr = mlx_new_window(mlx_ptr, lg * 10 + 100, nbr_line * 10 + 100, "fdf V2");
	tab = tab_build(map, lg, nbr_line);
	remplir_image(&img, tab, lg, nbr_line);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return (0);
}
