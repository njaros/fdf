/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traiteur.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:58:39 by njaros            #+#    #+#             */
/*   Updated: 2022/01/25 17:18:09 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	trace_trait(t_point_plan xyc1, int x2, int y2, t_data *data)
{
	double	a;

	a = (xyc1.y - y2) / (xyc1.x - x2);
	while (xyc1.x != x2)
	{
		if (xyc1.x > x2)
		{
			xyc1.x--;
			my_mlx_pixel_put(data, xyc1.x, dtoi(xyc1.y - a), xyc1.exist);
		}
		else
		{
			xyc1.x++;
			my_mlx_pixel_put(data, xyc1.x, dtoi(xyc1.y + a), xyc1.exist);
		}
		a += a;
	}
}

//A cause de la norminette je dois reduire les noms par des lettres
//Aux chiottes la norminette !!

void	traiteur(t_point_plan **p, t_point_plan c, t_data *data)
{
	t_point_plan	n;

	n.x = p[c.y][c.x].x;
	n.y = p[c.y][c.x].y;
	n.exist = c.exist;
	if (c.y > 0)
		trace_trait(n, p[c.y - 1][c.x].x, p[c.y - 1][c.x].y, data);
	if (c.x > 0)
		trace_trait(n, p[c.y][c.x - 1].x, p[c.y][c.x - 1].y, data);
}