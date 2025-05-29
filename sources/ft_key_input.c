/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:32:28 by inandres          #+#    #+#             */
/*   Updated: 2025/05/28 17:29:34 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//		if (data->map[data->y - 1][data->x] == 'E')
//		{
//			data->map[data->y - 1][data->x] = 'J';
//		}

void	w_movement(t_info_map *data)
{
	if (data->map[data->y - 1][data->x] != '1'
		&& data->map[data->y - 1][data->x] != '2'
		&& data->map[data->y - 1][data->x] != 'E')
	{
		if (data->map[data->y - 1][data->x] == '0'
			|| data->map[data->y - 1][data->x] == 'C')
		{
			if (data->map[data->y - 1][data->x] == 'C')
				data->coin--;
			data->map[data->y][data->x] = '0';
			data->map[data->y - 1][data->x] = 'P';
		}
		if (data->map[data->y - 1][data->x] == 'Z')
		{
			data->map[data->y - 1][data->x] = 'C';
			data->coin++;
		}
		data->y--;
		data->step++;
		ft_write_itoa(data->step);
	}
	else if (data->map[data->y - 1][data->x] == 'E' && data->coin == 0)
		data->finish = 1;
}

void	a_movement(t_info_map *data)
{
	if (data->map[data->y][data->x - 1] != '1'
		&& data->map[data->y][data->x - 1] != '2'
		&& data->map[data->y][data->x - 1] != 'E')
	{
		if (data->map[data->y][data->x - 1] == '0'
			|| data->map[data->y][data->x - 1] == 'C')
		{
			if (data->map[data->y][data->x - 1] == 'C')
				data->coin--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x - 1] = 'P';
		}
		if (data->map[data->y][data->x - 1] == 'Z')
		{
			data->map[data->y][data->x - 1] = 'C';
			data->coin++;
		}
		data->x--;
		data->step++;
		ft_write_itoa(data->step);
	}
	else if (data->map[data->y][data->x - 1] == 'E' && data->coin == 0)
	{
		data->finish = 1;
	}
}

void	s_movement(t_info_map *data)
{
	if (data->map[data->y + 1][data->x] != '1'
		&& data->map[data->y + 1][data->x] != '2'
		&& data->map[data->y + 1][data->x] != 'E')
	{
		if (data->map[data->y + 1][data->x] == '0'
			|| data->map[data->y + 1][data->x] == 'C')
		{
			if (data->map[data->y + 1][data->x] == 'C')
				data->coin--;
			data->map[data->y][data->x] = '0';
			data->map[data->y + 1][data->x] = 'P';
		}
		if (data->map[data->y + 1][data->x] == 'Z')
		{
			data->map[data->y + 1][data->x] = 'C';
			data->coin++;
		}
		data->y++;
		data->step++;
		ft_write_itoa(data->step);
	}
	else if (data->map[data->y + 1][data->x] == 'E' && data->coin == 0)
	{
		data->finish = 1;
	}
}

void	d_movement(t_info_map *data)
{
	if (data->map[data->y][data->x + 1] != '1'
		&& data->map[data->y][data->x + 1] != '2'
		&& data->map[data->y][data->x + 1] != 'E')
	{
		if (data->map[data->y][data->x + 1] == '0'
			|| data->map[data->y][data->x + 1] == 'C')
		{
			if (data->map[data->y][data->x + 1] == 'C')
				data->coin--;
			data->map[data->y][data->x] = '0';
			data->map[data->y][data->x + 1] = 'P';
		}
		if (data->map[data->y][data->x + 1] == 'Z')
		{
			data->map[data->y][data->x + 1] = 'C';
			data->coin++;
		}
		data->x++;
		data->step++;
		ft_write_itoa(data->step);
	}
	else if (data->map[data->y][data->x + 1] == 'E' && data->coin == 0)
	{
		data->finish = 1;
	}
}

int	ft_press_key(int keycode, t_info_map *data)
{
	if (keycode == ESC)
		ft_close(data);
	else if (keycode == W && data->finish == 0)
		w_movement(data);
	else if (keycode == A && data->finish == 0)
		a_movement(data);
	else if (keycode == S && data->finish == 0)
		s_movement(data);
	else if (keycode == D && data->finish == 0)
		d_movement(data);
	ft_window(data);
	return (0);
}

/* 	printf("x %d y %d\n", data->x, data->y);
	while (data->map[i])
		printf("%s\n", data->map[i++]);
	printf("-----------------\n"); */
