/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:05:54 by njaros            #+#    #+#             */
/*   Updated: 2022/01/13 15:07:16 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

int	err_color(int erreur)
{
	if (erreur == 1)
		ft_putendl_fd("Au moins un code couleur incomplet", 2);
	if (erreur == 2)
		ft_putendl_fd("Code couleur : 8 hexa max avec respect de la casse", 2);
	if (erreur == 3)
		ft_putendl_fd("Au moins un code couleur incomplet", 2);
	ft_putendl_fd("Rappel : ,0x + au plus 8 hexa (ex: 8,0xcaca69)", 2);
	return (0);
}

int	is_color(char *str, int *pos)
{
	int	i;
	int	j;

	i = 0;
	if (str[i] == ' ' || str[i] == '\n' || (!ft_strncmp(&str[i], ",-1", 3)
			&& (str[i + 3] == ' ' || str[i + 3] == '\n'
			|| str[i + 3] == '\0')))
		return (1);
	if (ft_strncmp(&str[i], ",0x", 3) != 0)
		return (err_color(1));
	j = i + 2;
	while (str[++j] && str[j] != ' ' && str[j] != '\n')
	{
		if (!contain(str[j],"0123456789abcdefABCDEF")
			|| !casse_ctrl(j, str) || j == i + 9)
			return (err_color(2));
	}
	if (j == i + 3)
		return (err_color(3));
	*pos += j;
	return (1);
}

int	is_nbr(char	*str, int *pos)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != ',')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putendl_fd("Au moins un élément n'est pas un nombre", 2);
			return (0);
		}
		i++;
	}
	if (str[i] && !is_color(&str[i], &i))
		return (0);
	while (str[i] == ' ')
		i++;
	*pos = *pos + i;
	return (1);
}

int	count_nbr(char *to_check, int *count)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (to_check[i] == ' ')
		i++;
	while (to_check[i] && to_check[i] != '\n')
	{
		if (!is_nbr(&to_check[i], &i))
			return (22);
		c++;
	}
	if (c != *count && *count != -1)
	{
		ft_putendl_fd("Les lignes doivent comporter le même nombre d'éléments", 2);
		return (22);
	}
	if (*count == -1)
		*count = c;
	return (0);
}

int	parsing_map(t_list *map)
{
	int	error;
	int	count;

	count = -1;
	while (map)
	{
		error = count_nbr(map->content, &count);
		if (!count)
		{
			ft_putendl_fd("ligne vide detectée", 2);
			return (22);
		}
		if (error != 0)
			return (error);
		map = map->next;
	}
	return (-count);
}
