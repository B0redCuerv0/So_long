/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:57:03 by inandres          #+#    #+#             */
/*   Updated: 2025/04/28 10:50:21 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_roof_and_wall_and_floor_and_etc_img(t_info_map *data, int y, int x)
{
	if (data->map[x][y] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->roof, (y) * 64, (x) * 64);
	else if (data->map[x][y] == '2')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->wall, (y) * 64, (x) * 64);
	else if (data->map[x][y] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->floor, (y) * 64, (x) * 64);
	else if (data->map[x][y] == 'Z')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->chest_closed, (y) * 64, (x) * 64);
	else if (data->map[x][y] == 'X')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images->enemy, (y) * 64, (x) * 64);
}

void	put_player_img(t_info_map *data, int *y, int *x)
{
	mlx_put_image_to_window(data->mlx, data->win,
		data->images->player, (*y) * 64, (*x) * 64);
	data->x = *y;
	data->y = *x;
}

void	ft_draw_map(t_info_map *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '1' || data->map[x][y] == '2'
				|| data->map[x][y] == '0' || data->map[x][y] == 'Z'
				|| data->map[x][y] == 'X')
				put_roof_and_wall_and_floor_and_etc_img(data, y, x);
			else if (data->map[x][y] == 'P')
				put_player_img(data, &y, &x);
			else if (data->map[x][y] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->coin, y * 64, x * 64);
			else if (data->map[x][y] == 'E')
				mlx_put_image_to_window(data->mlx, data->win,
					data->images->exit, y * 64, x * 64);
			y++;
		}
		x++;
	}
}
