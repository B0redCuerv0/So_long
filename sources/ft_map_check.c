/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:19:52 by inandres          #+#    #+#             */
/*   Updated: 2025/04/17 11:15:19 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* void	ft_check_format(t_info_map *data)
{
	if (ft_strcmpr(&data->txt[ft_strlen(data->txt) - 4], ".ber", 5) != 0 
		|| ft_strlen (data->txt) <= 4)
	{
		write(2, "No es un .ber\n", 14);
		exit (EXIT_FAILURE);
	}
} */

void	ft_check_format(t_info_map *data)
{
	if (ft_strlen(data->txt) <= 4
		|| ft_strncmp(&data->txt[ft_strlen(data->txt) - 4], ".ber", 4) != 0)
	{
		write(2, "No es un .ber\n", 14);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_if_outline(t_info_map *data)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (i < data->width)
	{
		if (data->map[0][i] != '1' || data->map[data->hight - 1][i] != '1')
			error = 1;
		i++;
	}
	i = 0;
	while (i < data->hight)
	{
		if (data->map[i][0] != '1' || data->map[i][data->width - 1] != '1')
			error = 1;
		i++;
	}
	if (error != 0)
	{
		write(2, "Tan mal los bordes\n", 19);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_inputs(t_info_map *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] != '1' && data->map[y][x] != '2'
				&& data->map[y][x] != '0' && data->map[y][x] != 'C'
				&& data->map[y][x] != 'P' && data->map[y][x] != 'E'
				&& data->map[y][x] != 'X' && data->map[y][x] != 'Z')
			{
				write(2, "El mapa no tiene lo que necesita\n", 33);
				exit (EXIT_FAILURE);
			}
			else
				x++;
		}
		y++;
	}
}

void	ft_check_objects(t_info_map *data)
{
	int	x;
	int	y;
	int	end;

	end = 0;
	y = -1;
	while (data->map[++y])
	{
		x = -1;
		while (data->map[y][++x])
		{
			if (data->map[y][x] == 'P')
				data->player++;
			if (data->map[y][x] == 'C')
				data->coin++;
			if (data->map[y][x] == 'E')
				end++;
		}
	}
	if (data->player != 1 || data->coin < 1 || end != 1)
	{
		write(2, "Algo tiene que estar mal con los objetos\n", 41);
		exit (EXIT_FAILURE);
	}
}

void	ft_check_if_posible(t_info_map *data)
{
	int	x[2];
	int	y[2];
	int	obj;

	obj = 0;
	x[0] = -1;
	while (data->map[++x[0]])
	{
		x[1] = -1;
		while (data->map[x[0]][++x[1]])
		{
			if (data->map[x[0]][x[1]] == 'P')
			{
				y[0] = x[0];
				y[1] = x[1];
			}
			if (data->map[x[0]][x[1]] == 'E' || data->map[x[0]][x[1]] == 'C')
				obj++;
		}
	}
	ft_posible(data, y[0], y[1], obj);
}
