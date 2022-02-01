/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:30:36 by njaros            #+#    #+#             */
/*   Updated: 2022/02/01 16:25:12 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	fdf(t_list **map, int lg)
{
	void	*mlx_ptr;
	t_data	img;
	int		nbr_line;
	void	*win_ptr;
	t_vars	vars;

	mlx_ptr = mlx_init();
	nbr_line = compteur_ligne(*map);
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "fdf V2");
	vars.tab = tab_build(map, lg, nbr_line);
	vars.angle = M_PI / 32;
	vars.data = &img;
	vars.lg = lg;
	vars.ht = nbr_line;
	vars.img = img.img;
	vars.mlx = mlx_ptr;
	vars.win = win_ptr;
	/*rotato_z(tab, M_PI / 6);
	rotato_x(tab, M_PI / 6);
	rotato_y(tab, M_PI / 6);*/
	remplir_image(&img, vars.tab, lg, nbr_line);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_destroy_image(mlx_ptr, img.img);
	mlx_hook(win_ptr, 2, 0, rotate, &vars);
	mlx_loop(mlx_ptr);
	return (0);
}
