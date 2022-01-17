/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:05:36 by njaros            #+#    #+#             */
/*   Updated: 2022/01/17 16:58:00 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

double	gemme_angle(int x, int y)
{
	double	distance;
	double	angle;

	distance = sqrt(pow(x, 2) + pow(y, 2));
	angle = acos(x / distance);
	if (y < 0)
		angle = 2 * M_PI - angle;
	return (angle);
}

t_point	*fill_tab(char *pixel, int lg, int y, int hauteur)
{
	t_point	*pouet;
	int	i;

	pouet = malloc(sizeof(t_point) * lg);
	i = 0;
	while (pixel)
	{
		pouet[i].x = i - lg / 2;
		pouet[i].y = y - hauteur / 2;
		pouet[i].z = ft_atoi(pixel);
		pouet[i].color = color_search(pixel);
		pouet[i].angle2D = gemme_angle(i, y);
		pouet[i].angle3DX = 0;
		pouet[i].angle3DY = 0;
		i++;
		pixel = next_pixel(pixel);
	}
	return (pouet);
}

t_point	**tab_build(t_list **map, int lg, int hauteur)
{
	int		i;
	t_point	**tab;
	char	*line;

	tab = malloc(sizeof(t_point *) * hauteur);
	if (!tab)
		return (NULL);
	i = 0;
	while (*map)
	{
		line = (*map)->content;
		tab[i] = fill_tab(line, lg, i, hauteur);
		next_line(map);
		i++;
	}
	return (tab);
}
