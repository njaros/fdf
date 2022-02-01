/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:17:48 by njaros            #+#    #+#             */
/*   Updated: 2022/02/01 13:18:54 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	calcul_poids(char c, char *base, int exp)
{
	int poids;
	int	i;

	i = 0;
	poids = 1;
	if (exp != 0)
	{
		while (exp != 0)
		{
			poids *= 16;
			exp--;
		}
	}
	while (c != base[i])
		i++;
	return (i * poids);
}

//ci dessous fonction qui retourne un int qui est un arrondi d'un double
int	dtoi(double d)
{
	int		aprox;

	aprox = d;
	if ((d - aprox) * 10 >= 5)
		return (aprox + 1);
	return (aprox);
}

t_point	**freeteuse(t_point **tab, int end)
{
	while (--end >= 0)
		free(tab[end]);
	free(tab);
	return (NULL);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	remplir_image(t_data *data, t_point **tab, int lg, int ht)
{
	t_point_plan	**plan;
	int				x;
	int				y;
	t_point_plan	magouille_norminage;

	plan = plan_build(tab, lg, ht);
	x = 0;
	y = 0;
	while (plan[y])
	{
		while (plan[y][x].exist == 1)
		{
			magouille_norminage.x = x;
			magouille_norminage.y = y;
			magouille_norminage.exist = tab[y][x].color;
			my_mlx_pixel_put(data, plan[y][x].x, plan[y][x].y, tab[y][x].color);
			traiteur(plan, magouille_norminage, data);
			x++;
		}
		x = 0;
		y++;
	}
}
