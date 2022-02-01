/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 15:19:08 by njaros            #+#    #+#             */
/*   Updated: 2022/02/01 15:49:14 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	rotate(int keycode, t_vars vars)
{
	if (keycode == 38)
		rotato_z(vars.tab, vars.angle);
	else if (keycode == 40)
		rotato_x(vars.tab, vars.angle);
	else if (keycode == 39)
		rotato_y(vars.tab, vars.angle);
	remplir_image(vars.data, vars.tab, vars.lg, vars.ht);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
	mlx_destroy_image(vars.mlx, vars.win);
	return (0);
}