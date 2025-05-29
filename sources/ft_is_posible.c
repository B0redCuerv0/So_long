/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_posible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 11:16:00 by inandres          #+#    #+#             */
/*   Updated: 2025/04/24 12:43:49 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	malloc_and_fill(t_checker *c, t_info_map *data)
{
	int	x;
	int	y;

	c->map = malloc(sizeof(int *) * data->hight);
	x = -1;
	while (++x < data->hight)
	{
		c->map[x] = malloc(sizeof(int *) * data->width);
	}
	x = -1;
	while (++x < data->hight)
	{
		y = -1;
		while (++y < data->width)
		{
			c->map[x][y] = 0;
		}
	}
}

void	free_checker(t_checker *c, int hight)
{
	int	i;

	i = -1;
	while (++i < hight)
		free(c->map[i]);
	free(c->map);
	c->map = NULL;
}

void	iter_checker(t_checker *c, t_info_map *data, int x, int y)
{
	if (c->coins_left == 0)
		return ;
	if (c->map[x][y] == 0 && data->map[x][y] != '1' && data->map[x][y] != '2')
	{
		c->map[x][y] = 1;
		if (data->map[x][y] == 'C' || data->map[x][y] == 'E')
			c->coins_left--;
		if (data->map[x][y] == 'E')
			return ;
		iter_checker(c, data, x + 1, y);
		iter_checker(c, data, x - 1, y);
		iter_checker(c, data, x, y + 1);
		iter_checker(c, data, x, y - 1);
	}
}

void	ft_posible(t_info_map *data, int x, int y, int left)
{
	t_checker	c;

	c.coins_left = left;
	malloc_and_fill (&c, data);
	iter_checker(&c, data, x, y);
	if (c.coins_left != 0)
	{
		write(2, "Mapa imposible\n", 15);
		exit(EXIT_FAILURE);
	}
	free_checker(&c, data->hight);
}
