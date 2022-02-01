/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:05:36 by njaros            #+#    #+#             */
/*   Updated: 2022/02/01 13:33:42 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

double	gemme_angle(int x, int y, double dist)
{
	double	angle;

	if (dist == 0)
		return (0);
	angle = acos(x / dist);
	if (y < 0)
		angle = 2 * M_PI - angle;
	return (angle);
}

double	gemme_distance(int x, int y)
{
	return (sqrt(pow(x, 2) + pow(y, 2)));
}

t_point	*fill_tab(char *pixel, int lg, int y, int hauteur)
{
	t_point	*pouet;
	int	i;

	pouet = malloc(sizeof(t_point) * lg + 1);
	if (!pouet)
		return (NULL);
	i = 0;
	while (pixel)
	{
		pouet[i].x = i - lg / 2;
		pouet[i].y = y - hauteur / 2;
		pouet[i].z = 0;
		pouet[i].color = color_search(pixel);
		pouet[i].dist_centreXY = gemme_distance(pouet[i].x, pouet[i].y);
		pouet[i].dist_centreXZ = gemme_distance(pouet[i].x, ft_atoi(pixel));
		pouet[i].dist_centreYZ = gemme_distance(pouet[i].y, ft_atoi(pixel));
		pouet[i].angle2D = gemme_angle(pouet[i].x, pouet[i].y, pouet[i].dist_centreXY);
		pouet[i].angle3DX = M_PI / 2;
		pouet[i].angle3DY = 0;
		pouet[i].exist = 1;
		i++;
		pixel = next_pixel(pixel);
	}
	pouet[i].exist = 0;
	return (pouet);
}

t_point	**tab_build(t_list **map, int lg, int hauteur)
{
	int		i;
	t_point	**tab;
	char	*line;

	tab = malloc(sizeof(t_point *) * hauteur + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (*map)
	{
		line = (*map)->content;
		tab[i] = fill_tab(line, lg, i, hauteur);
		if (!tab[i])
			return (freeteuse(tab, i));
		next_line(map);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
