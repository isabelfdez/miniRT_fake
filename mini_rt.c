/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:46:33 by isfernan          #+#    #+#             */
/*   Updated: 2020/03/06 20:06:52 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		neg;
	int		nb;

	i = 0;
	neg = 0;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg++;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		nb = nb * (-1);
	return (nb);
}

int		count_nb(int nb)
{
	int				rtrn;
	long long int	i;

	rtrn = 0;
	i = 1;
	while (nb / i)
	{
		i = i * 10;
		rtrn++;
	}
	if (nb <= 0)
		rtrn = rtrn + 1;
	return (rtrn);
}


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
	/*if (aux[j] == 'c')
		j = ft_camera(aux, j + 1, data);
	if (aux[j] == 'l')
		j = ft_light(aux, j + 1, data);*/
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
	float	nb;

	while (aux[i] == ' ')
		i++;
	nb = ft_atoi(aux + i);
	if (aux[++i] == '.' )
	{
		printf("la i es %i\n el numero es %i\n las cifras son %i\n", 
			i, ft_atoi(aux + i + 1), count_nb(ft_atoi(aux + i + 1)));
		nb = nb + ((float)(ft_atoi(aux + i + 1)) / (float)(powf(10.0, (float)count_nb(ft_atoi(aux + i + 1)))));
		data->al_ratio = nb;
	}
	while (ft_isdigit(aux[i]) || aux[i] == '.' || aux[i] == ' ')
		i++;
	data->al_col.x = ft_atoi(aux + i);
	while (aux[i] == ' ' || aux[i] == ',')
		i++;
	data->al_col.y = ft_atoi(aux + i);
	while (aux[i] == ' ' || aux[i] == ',')
		i++;
	data->al_col.z = ft_atoi(aux + i);
	while (aux[i] == ' ' || aux[i] == '\n')
		i++;
	printf("alratio = %f", data->al_ratio);
	return (i);
}



int		ft_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	else
		return (0);
}

/*void	to_base(unsigned int nb, char *base, t_data *data)
{
	if (nb >= (unsigned int)ft_strlen(base))
		to_base(nb / (ft_strlen(base)), base, data);
	putchr_add(nb % ft_strlen(base), base, data);
}*/
