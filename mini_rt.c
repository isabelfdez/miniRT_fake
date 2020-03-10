/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:46:33 by isfernan          #+#    #+#             */
/*   Updated: 2020/03/10 20:00:19 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Tengo que corregir lo de que también se salte los símbolos -
// Hay que tratar los errores

#include "mini_rt.h"

int	main(int argc, char **argv)
{
	char    *file;
	int     fd;
	char	*str;
	char	*aux;
	char	*aux2;

	file = argv[1];
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &str))
	{
		if (!aux)
			aux = ft_strdup(str);
		else
		{
			aux2 = ft_strjoin(aux, str);
			free(aux);
			aux = ft_strdup(aux2); /* Esto igual no hace falta */
			free(aux2);
		}
	}
	printf("%s\n", aux);

	ft_readfile(aux);
	return (0);
}

void	ft_readfile(char *aux)
{
	t_data	*data;
	int		j;

	j = 0;

	if (!(data = malloc(sizeof(t_data))))
		return ; /* Aquí hay que ver qué hacemos */
	if (aux[j] == 'R')
		j = ft_resolution(aux, j + 1, data);
	printf("%c %i\n", aux[j], j);
	if (aux[j] == 'A')
		j = ft_ambient(aux, j + 1, data);
	if (aux[j] == 'c')
		j = ft_camera(aux, j + 1, data);
	if (aux[j] == 'l')
		j = ft_light(aux, j + 1, data);
	/* Hay que ver qué hacemos con las figuras */
}

int	ft_resolution(char *aux, int i, t_data *data)
{
	while (aux[i] == ' ')
		i++;
	data->resx = ft_atoi(aux + i);
	while (ft_isdigit(aux[i]) || aux[i] == ' ')
		i++;
	data->resy = ft_atoi(aux + i);
	while(ft_isdigit(aux[i]) || aux[i] == ' ' || aux[i] == '\n')
		i++;
	printf("resx = %i, resy = %i\n", data->resx, data->resy);
	return (i);
}

int	ft_ambient(char *aux, int i, t_data *data)
{
	while (aux[i] == ' ')
		i++;
	data->al_ratio = ft_atof(aux, i);
	while (ft_isdigit(aux[i]) || aux[i] == '.')
		i++;
	while (aux[i] == ' ')
		i++;
	data->al_col.x = ft_atoi(aux + i);
	i = i + count_nb(data->al_col.x) + 1; /* Saltamos 1 por la coma */
	data->al_col.y = ft_atoi(aux + i);
	i = i + count_nb(data->al_col.y) + 1;
	data->al_col.z = ft_atoi(aux + i);
	i = i + count_nb(data->al_col.z);
	while (aux[i] == ' ' || aux[i] == '\n')
		i++;
	return (i);
}

int		ft_camera(char *aux, int i, t_data *data)
{
	t_pointf st;
	t_pointf end;

	st.x = 0;
	st.y = 0;
	st.z = 0;
	while (aux[i] == ' ')
		i++;
	data->c_coor.x = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	data->c_coor.y = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	data->c_coor.z = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	while (aux[i] == ' ')
		i++;
	data->c_ori.start = st;
	end.x = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	end.y = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	end.z = ft_atof(aux, i);
	i = skip_nsm(i, aux) - 1;
	data->c_ori.end = end;
	while (aux[i] == ' ')
		i++;
	data->c_fov = ft_atof(aux, i);
	while (aux[i] == ' ' || aux[i] == '\n')
		i++;
	printf("las coordenadas son: %f,%f,%f\nla orintación es %f,%f,%f  %f,%f,%f y el fov es %f", 
		data->c_coor.x, data->c_coor.y, data->c_coor.z, data->c_ori.start.x, data->c_ori.start.y,
		data->c_ori.start.z, data->c_ori.end.x, data->c_ori.end.y, data->c_ori.end.z, data->c_fov);
	return (i);	
}

int		ft_light(char *aux, int i, t_data *data)
{
	while (aux[i] == ' ')
		i++;
	data->l_coor.x = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	data->l_coor.y = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	data->l_coor.z = ft_atof(aux, i);
	i = skip_nsm(i, aux);
	while (aux[i] == ' ')
		i++;
	data->l_int = ft_atof(aux, i);
	i = skip_ns(i, aux);
	while (aux[i] == ' ')
		i++;
	data->l_col.x = ft_atoi(aux + i);
	i = i + count_nb(data->al_col.x) + 1; /* Saltamos 1 por la coma */
	data->l_col.y = ft_atoi(aux + i);
	i = i + count_nb(data->al_col.y) + 1;
	data->l_col.z = ft_atoi(aux + i);
	i = i + count_nb(data->al_col.z);
	while (aux[i] == ' ' || aux[i] == '\n')
		i++;
	return (i);	
}

int		skip_nsm(int i, char *aux)
{
	while (ft_isdigit(aux[i]) || aux[i] == '.' || aux[i] == '-')
		i++;
	i = i + 1; /* Para saltarse la coma */
	return (i);
}

int		skip_ns(int i, char *aux)
{
	while (ft_isdigit(aux[i]) || aux[i] == '.')
		i++;
	i = i + 1; /* Para saltarse la coma */
	return (i);
}