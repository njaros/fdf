/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:19:50 by njaros            #+#    #+#             */
/*   Updated: 2022/01/13 13:28:20 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	contain(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	ft_putendl_fd("Une couleur doit être codée en hexadecimal", 1);
	return (0);
}

int	casse_ctrl(int pos, char *str)
{
	char	c1;
	int		i;
	int		stop;

	stop = 0;
	i = 1;
	c1 = str[pos];
	if (ft_isdigit((int)c1) || pos == 3)
		return (1);
	while ((pos - i >= 3) && stop == 0)
	{
		if (ft_isalpha((int)str[pos - i]))
		{
			stop = 1;
			if (((c1 >= 'A' && c1 <= 'Z') && (str[pos - i] >= 'a' && str[pos - i] <= 'z'))
				|| ((c1 >= 'a' && c1 <= 'z') && (str[pos - i] >= 'A' && str[pos - i] <= 'Z')))
			{
				ft_putendl_fd("Non respect de la casse, lecture refusée", 2);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	pos_hexa(char c, char *str)
{
	int	i;
	i = 0;

	while (str[i] != c)
		i++;
	return (i);
}

int	convert_hexa_int(char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	while (str[++i] && str[i] != ' ' && str[i] != '\n')
	{
		str[i] = ft_tolower(str[i]);
		nb = 16 * nb + pos_hexa(str[i], "0123456789abcdef");
	}
	return nb;
}
