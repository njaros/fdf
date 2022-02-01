/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_build.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:00:47 by njaros            #+#    #+#             */
/*   Updated: 2022/02/01 14:51:25 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	projette_au_plan(t_point_plan *h, t_point a, int lg, int ht)
{
	double	projx;
	double	projy;

	projx = a.x;
	projy = a.y;
	h->x = dtoi(960.0 + projx * (1920.0 / ((double)lg * 2 * M_SQRT2)));
	h->y = dtoi(540.0 + projy * (1080.0 / ((double)ht * 2 * M_SQRT2)));
}

t_point_plan	*fill_plan(t_point *line, int lg, int ht)
{
	t_point_plan	*pouet;
	int				i;

	i = 0;
	pouet = malloc(sizeof(t_point_plan) * lg + 1);
	while (i < lg)
	{
		projette_au_plan(&pouet[i], line[i], lg, ht);
		pouet[i].exist = 1;
		i++;
	}
	pouet[i].exist = 0;
	return (pouet);
}

t_point_plan	**plan_build(t_point **tab, int lg, int ht)
{
	t_point_plan	**plan;
	int				i;

	i = 0;
	plan = malloc(sizeof(t_point_plan*) * ht + 1);
	while (i < ht)
	{
		plan[i] = fill_plan(tab[i], lg, ht);
		i++;
	}
	plan[i] = NULL;
	return (plan);
}
