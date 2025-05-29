/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:06:43 by inandres          #+#    #+#             */
/*   Updated: 2025/05/28 17:29:34 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_img(t_info_map *data)
{
	int	img_hight;
	int	img_width;

	data->images = malloc(sizeof(t_images));
	data->images->player = mlx_xpm_file_to_image(data->mlx,
			PLAYER, &img_width, &img_hight);
	data->images->floor = mlx_xpm_file_to_image(data->mlx,
			FLOOR, &img_width, &img_hight);
	data->images->wall = mlx_xpm_file_to_image(data->mlx,
			WALL, &img_width, &img_hight);
	data->images->roof = mlx_xpm_file_to_image(data->mlx,
			ROOF, &img_width, &img_hight);
	data->images->exit = mlx_xpm_file_to_image(data->mlx,
			EXIT, &img_width, &img_hight);
	data->images->chest_closed = mlx_xpm_file_to_image(data->mlx,
			CHEST, &img_width, &img_hight);
	data->images->coin = mlx_xpm_file_to_image(data->mlx,
			COIN, &img_width, &img_hight);
	data->images->enemy = mlx_xpm_file_to_image(data->mlx,
			ENEMY, &img_width, &img_hight);
}

void	ft_reset_data(t_info_map *data, char *name)
{
	data->hight = 0;
	data->width = 0;
	data->x = 0;
	data->y = 0;
	data->player = 0;
	data->coin = 0;
	data->step = 0;
	data->finish = 0;
	data->txt = name;
	ft_load_img(data);
}

void	ft_check_all(t_info_map *data)
{
	ft_check_if_outline(data);
	ft_check_inputs(data);
	ft_check_objects(data);
	ft_check_format(data);
	ft_check_if_posible(data);
}

int	ft_window(t_info_map *data)
{
	mlx_clear_window(data->mlx, data->win);
	ft_draw_map(data);
	if (data->coin == 0 && data->player == 1 && data->finish == 1)
		ft_close(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_info_map	data;

	if (ac == 2)
	{
		data.mlx = mlx_init();
		ft_reset_data(&data, av[1]);
		ft_map_size(&data);
		ft_malloc_map(&data);
		ft_check_all(&data);
		data.win = mlx_new_window(data.mlx, data.width * 64,
				data.hight * 64, "so_long");
		mlx_hook(data.win, 17, 0, ft_close, &data);
		mlx_key_hook(data.win, ft_press_key, &data);
		ft_window(&data);
		mlx_loop(data.mlx);
	}
	return (0);
}
