/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isfernan <isfernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:41:53 by isfernan          #+#    #+#             */
/*   Updated: 2020/03/03 21:18:45 by isfernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>

int		condition(int i, int j)
{
	if (sqrt(pow(i - 100, 2) + pow(j - 100, 2)) <= 20)
		return (1);
	return (0);
}

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	int i = 25;
	int j;
	int theta = 0;
	int r = 80;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "prueba");

	while (i < 50)
	{
		j = 25;
		while (j < 50)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFF00);
			j++;
		}
		i++;
	}
	i = 80;
	j = 80;
	while (i < 120)
	{
		j = 25;
		while (j < 120)
		{
			if (condition(i, j))
				mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFF00);
			j++;
		}
		i++;
	}
	mlx_loop(mlx_ptr);
}

