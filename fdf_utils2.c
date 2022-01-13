/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:17:48 by njaros            #+#    #+#             */
/*   Updated: 2022/01/13 19:38:22 by njaros           ###   ########lyon.fr   */
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