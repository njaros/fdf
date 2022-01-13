/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:39:47 by njaros            #+#    #+#             */
/*   Updated: 2021/12/14 14:58:27 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

t_list	*fill_lst(int fd)
{
	t_list	*map;
	t_list	*secure;
	char	*ligne;

	map = NULL;
	ligne = get_next_line(fd);
	while (ligne)
	{
		secure = ft_lstnew(ligne);
		if (!secure)
		{
			ft_lstclear(&map, free);
			return (NULL);
		}
		ft_lstadd_back(&map, secure);
		ligne = get_next_line(fd);
	}
	return (map);
}
