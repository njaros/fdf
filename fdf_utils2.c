/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:17:48 by njaros            #+#    #+#             */
/*   Updated: 2022/01/25 15:22:08 by njaros           ###   ########lyon.fr   */
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
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tab[y])
	{
		while (tab[y][x].exist == 1)
		{
			my_mlx_pixel_put(data, 50 + (lg / 2 + tab[y][x].x) * 10, 50 + (ht / 2 + tab[y][x].y) * 10, tab[y][x].color);
			x++;
		}
		x = 0;
		y++;
	}
}
