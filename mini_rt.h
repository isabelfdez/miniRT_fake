/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:35:31 by isfernan          #+#    #+#             */
/*   Updated: 2020/03/10 19:53:55 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include "mlx.h"
# include "./get_next_line/get_next_line.h"
# include "./libft/libft.h"

typedef	struct	s_pointf
{
	float		x;
	float		y;
	float		z;
}				t_pointf;

typedef struct	s_pointi
{
	int			x;
	int			y;
	int			z;
}				t_pointi;

typedef struct	s_vectorf
{
	t_pointf	start;
	t_pointf	end;
}				t_vectorf;

typedef struct	s_vectori
{
	t_pointi	start;
	t_pointi	end;
}				t_vectori;

typedef struct	s_sph
{
	t_pointf	center;
	float		rad;	/* Me dan el diámetro */
	t_pointi	col;
}				t_sph;

typedef struct	s_plane
{
	t_pointf	p;
	t_vectorf	v;
	t_pointi	col;
}				t_plane;

typedef struct	s_sq
{
	t_pointf	center;
	t_vectorf	v;
	float		size;
	t_pointi	col;
}				t_sq;

typedef struct	s_cyl
{
	t_pointf	p;
	t_vectorf	v;
	float		rad;	/* Me dan el diámetro */
	float		h;
	t_pointi	col;
}				t_cyl;

typedef struct	s_trian
{
	t_pointf	f;
	t_pointf	s;
	t_pointf	t;
	t_pointi	col;
}				t_trian;

typedef struct  s_data
{
	int			resx;
	int			resy;
	float       al_ratio;
	t_pointi	al_col;
	t_pointf	c_coor;
	t_vectorf	c_ori;
	float		c_fov;
	t_vectorf	l_coor;
	float		l_int;
	t_pointi	l_col;
	char		id[2];
}               t_data;

void	ft_readfile(char *aux);
int		ft_resolution(char *aux, int i, t_data *data);
int		ft_ambient(char *aux, int i, t_data *data);
int		ft_camera(char *aux, int i, t_data *data);
int		skip_nsm(int i, char *aux);
int		skip_ns(int i, char *aux);








#endif

