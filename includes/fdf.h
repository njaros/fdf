/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:38:04 by njaros            #+#    #+#             */
/*   Updated: 2022/01/25 17:09:04 by njaros           ###   ########lyon.fr   */
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

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_data;

typedef struct s_point_plan
{
	int	x;
	int	y;
	int	exist;
}	t_point_plan;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	double	dist_centreXY;
	double	dist_centreXZ;
	double	dist_centreYZ;
	int		color;
	double	angle2D;  //angle sur le plan xy entre le point et le centre de la fenêtre
	double	angle3DX; //angle entre axe x et z par rapport au point de vue
	double	angle3DY; //angle entre axe y et z par rapport au point de vue
	int		exist;
}	t_point;

// Parsing et sauvegarde des points

int				contain(char c, char *str);
int				contain_return(char *s);
int				casse_ctrl(int pos, char *str);
int				pos_hexa(char c, char *str);
int				convert_hexa_int(char *str);
int				count_nbr(char *to_check, int *count);
t_list			*fill_lst(int fd);
char			*ft_return_and_keep(char **temp, char *line, int n);
char			*ft_strjoin_free(char *s1, char *s2, int del);
size_t			ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_substr_free(char *s, unsigned int start, size_t len);
char			*get_next_line(int fd);
int				is_color(char *str, int *pos);
int				is_nbr(char	*str, int *pos);
int				main(int ac, char **av);
int				parsing_map(t_list *map);

// Placement des points sur la mlx

int				fdf(t_list **map, int lg);
int 			compteur_ligne(t_list *lst);
int				color_search(char *pixel);
int				hexa_to_int(char *str);
char			*next_pixel(char *line);
void			next_line(t_list **lst);
int				calcul_poids(char c, char *base, int exp);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			remplir_image(t_data *data, t_point **tab, int lg, int ht);
t_point			**tab_build(t_list **map, int lg, int hauteur);
void			projette_au_plan(t_point_plan *h, t_point a);
t_point_plan	*fill_plan(t_point *line, int lg);
t_point_plan	**plan_build(t_point **tab, int lg, int ht);
void			traiteur(t_point_plan **p, t_point_plan c, t_data *data);
void			trace_trait(t_point_plan xyc1, int x2, int y2, t_data *data);

// Outils de transformations

void			rotato_z(t_point **tab, double angle);
void			rotato_x(t_point **tab, double angle);
void			rotato_y(t_point **tab, double angle);

// Outils pratiques

t_point			**freeteuse(t_point **tab, int end);
int				dtoi(double d);

//A supprimer avant rendu

void			ft_display(t_list *map);

#endif
