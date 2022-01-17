/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:38:04 by njaros            #+#    #+#             */
/*   Updated: 2022/01/17 16:56:29 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
#include "mlx.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

typedef struct s_point
{
	int		x;
	int		y;
	int		z;
	int		color;
	double	angle2D;  //angle sur le plan xy entre le point et le centre de la fenêtre
	double	angle3DX; //angle entre axe x et z par rapport au point de vue
	double	angle3DY; //angle entre axe y et z par rapport au point de vue
}	t_point;

// Parsing et sauvegarde des points

int		contain(char c, char *str);
int		contain_return(char *s);
int		casse_ctrl(int pos, char *str);
int		pos_hexa(char c, char *str);
int		convert_hexa_int(char *str);
int		count_nbr(char *to_check, int *count);
t_list	*fill_lst(int fd);
char	*ft_return_and_keep(char **temp, char *line, int n);
char	*ft_strjoin_free(char *s1, char *s2, int del);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_substr_free(char *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		is_color(char *str, int *pos);
int		is_nbr(char	*str, int *pos);
int		main(int ac, char **av);
int		parsing_map(t_list *map);

// Placement des points sur la mlx

int		fdf(t_list **map, int lg);
int 	compteur_ligne(t_list *lst);
int		color_search(char *pixel);
int		hexa_to_int(char *str);
char	*next_pixel(char *line);
void	next_line(t_list **lst);
int		calcul_poids(char c, char *base, int exp);
t_point	**tab_build(t_list **map, int lg, int hauteur);

// Outils pratiques

void	freeteuse(t_point **tab, int end);

//A supprimer avant rendu

void	ft_display(t_list *map);

#endif
