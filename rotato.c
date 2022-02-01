/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotato.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:18:48 by njaros            #+#    #+#             */
/*   Updated: 2022/02/01 15:18:18 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	rotato_z(t_point **tab, double angle)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (tab[++j])
	{
		while (tab[j][++i].exist == 1)
		{
			tab[j][i].angle2D += angle;
			tab[j][i].x = cos(tab[j][i].angle2D) * tab[j][i].dist_centreXY;
			tab[j][i].y = sin(tab[j][i].angle2D) * tab[j][i].dist_centreXY;
		}
		i = -1;
	}
}

void	rotato_x(t_point **tab, double angle)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (tab[++j])
	{
		while (tab[j][++i].exist == 1)
		{
			tab[j][i].angle3DY += angle;
			tab[j][i].z += cos(tab[j][i].angle3DY) * tab[j][i].dist_centreYZ;
			tab[j][i].y += sin(tab[j][i].angle3DY) * tab[j][i].dist_centreYZ;
		}
	}
}

void	rotato_y(t_point **tab, double angle)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (tab[++j])
	{
		while (tab[j][++i].exist == 1)
		{
			tab[j][i].angle3DX += angle;
			tab[j][i].x += cos(tab[j][i].angle3DX) * tab[j][i].dist_centreXZ;
			tab[j][i].z += sin(tab[j][i].angle3DX) * tab[j][i].dist_centreXZ;
		}
	}
}