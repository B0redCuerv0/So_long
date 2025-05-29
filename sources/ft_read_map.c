/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:15:48 by inandres          #+#    #+#             */
/*   Updated: 2025/04/28 10:49:53 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_size(t_info_map *data)
{
	char	*line;
	int		fd;

	fd = open(data->txt, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
	{
		write(2, "Error de mapa\n", 14);
		exit (EXIT_FAILURE);
	}
	data->width = ft_strlen(line) - 1;
	data->hight = 0;
	while (line)
	{
		if ((int)ft_strlen(line) - 1 != data->width)
		{
			write(2, "Mapa no válido\n", 15);
			exit (EXIT_FAILURE);
		}
		data->hight++;
		free(line);
		line = get_next_line(fd);
	}
	line = NULL;
	close(fd);
}

void	ft_malloc_error(void)
{
	write(2, "error de malloc\n", 16);
	exit (EXIT_FAILURE);
}

void	ft_malloc_map(t_info_map *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(data->txt, O_RDONLY);
	i = 0;
	data->map = (char **)malloc(sizeof (char *) * (data->hight + 1));
	if (!data->map)
		ft_malloc_error();
	while (i < data->hight)
	{
		line = get_next_line(fd);
		if (!line)
			ft_malloc_error();
		data->map[i] = ft_strdup(line);
		if (!data->map[i])
			ft_malloc_error();
		data->map[i][data->width] = '\0';
		i++;
		free(line);
	}
	data->map[i] = NULL;
	close(fd);
}
