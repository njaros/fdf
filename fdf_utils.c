/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:13:19 by njaros            #+#    #+#             */
/*   Updated: 2022/01/13 19:45:48 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	next_line(t_list **lst)
{
	t_list *temp;

	temp = (*lst)->next;
	ft_lstdelone(*lst, free);
	*lst = temp;
}

char	*next_pixel(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '\n')
		i++;
	while (line[i] == ' ')
		i++;
	if (!line[i] || line[i] == '\n')
		return (NULL);
	return (&line[i]);
}

int	hexa_to_int(char *str)
{
	int	i;
	int	j;
	int	nb;

	nb = 0;
	j = 0;
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n')
	{
		str[i] = ft_tolower((int)str[i]);
		i++;
	}
	while (str[--i] != 'x')
	{
		nb += calcul_poids(str[i], "0123456789abcdef", j);
		j++;
	}
	return (nb);
}

int	color_search(char *pixel)
{
	int	i;

	i = 0;
	while (pixel[i] == ' ')
		i++;
	if (pixel[i] == '-' || pixel[i] == '+')
		i++;
	while (ft_isdigit((int)pixel[i]))
		i++;
	if (pixel[i] == ' ' || pixel[i] == '\n' || pixel[i] == 0)
		return (0xffffff);
	else
		return (hexa_to_int(&pixel[i + 3]));
}

int	compteur_ligne(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
