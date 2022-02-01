/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traiteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:58:39 by njaros            #+#    #+#             */
/*   Updated: 2022/02/01 13:01:48 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	trace_trait_y(t_point_plan xyc1, int x2, int y2, t_data *data)
{
	double	a;
	double	b;

	a = (double)(xyc1.x - x2) / (double)(xyc1.y - y2);
	b = a;
	while (xyc1.y != y2)
	{
		if (xyc1.y > y2)
		{
			if (--xyc1.y != y2)
				my_mlx_pixel_put(data, dtoi(xyc1.x - a), xyc1.y, xyc1.exist);
		}
		else
		{
			if (++xyc1.y != y2)
				my_mlx_pixel_put(data, dtoi(xyc1.x + a), xyc1.y, xyc1.exist);
		}
		a += b;
	}
}

void	trace_trait(t_point_plan xyc1, int x2, int y2, t_data *data)
{
	double	a;
	double	b;

	if (abs(xyc1.y - y2) > abs(xyc1.x - x2))
		trace_trait_y(xyc1, x2, y2, data);
	else
	{
		a = (double)(xyc1.y - y2) / (double)(xyc1.x - x2);
		b = a;
		while (xyc1.x != x2)
		{
			if (xyc1.x > x2)
			{
				if (--xyc1.x != x2)
					my_mlx_pixel_put(data, xyc1.x, dtoi(xyc1.y - a), xyc1.exist);
			}
			else
			{
				if (++xyc1.x != x2)
					my_mlx_pixel_put(data, xyc1.x, dtoi(xyc1.y + a), xyc1.exist);
			}
			a += b;
		}
	}
}

//A cause de la norminette je dois reduire les noms par des lettres
//Aux chiottes la norminette !!

void	traiteur(t_point_plan **p, t_point_plan c, t_data *data)
{
	t_point_plan	n;

	n.x = p[c.y][c.x].x;
	n.y = p[c.y][c.x].y;
	ft_putnbr_fd(c.x, 1);
	ft_putchar_fd('|', 1);
	ft_putnbr_fd(c.y, 1);
	ft_putchar_fd('\t', 1);
	n.exist = c.exist;
	if (c.y > 0)
		trace_trait(n, p[c.y - 1][c.x].x, p[c.y - 1][c.x].y, data);
	if (c.x > 0)
		trace_trait(n, p[c.y][c.x - 1].x, p[c.y][c.x - 1].y, data);
}
