/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inandres <inandres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 10:40:29 by inandres          #+#    #+#             */
/*   Updated: 2025/04/28 10:44:15 by inandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define COIN   "./sprites/coin.xpm"
# define PLAYER "./sprites/player.xpm"
# define FLOOR  "./sprites/floor.xpm"
# define WALL   "./sprites/wall.xpm"
# define ROOF   "./sprites/roof.xpm"
# define ENEMY  "./sprites/enemy.xpm"
# define EXIT  "./sprites/exit.xpm"
# define CHEST  "./sprites/chest_closed.xpm"

# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "../get_next_line/get_next_line.h"
# include "../mlx/mlx.h"

typedef struct s_images
{
	void	*coin;
	void	*floor;
	void	*wall;
	void	*roof;
	void	*exit;
	void	*player;
	void	*enemy;
	void	*chest_closed;
}	t_images;

typedef struct s_checker
{
	int	**map;
	int	coins_left;
}	t_checker;

typedef struct s_info_map
{
	int				hight;
	int				width;
	int				x;
	int				y;
	int				player;
	int				coin;
	int				finish;
	unsigned int	step;
	char			*txt;
	char			**map;
	void			*mlx;
	void			*win;
	t_images		*images;
}	t_info_map;

void	ft_map_size(t_info_map *data);
void	ft_malloc_map(t_info_map *data);

void	ft_check_format(t_info_map *data);
void	ft_check_if_outline(t_info_map *data);
void	ft_check_inputs(t_info_map *data);
void	ft_check_objects(t_info_map *data);
void	ft_check_if_posible(t_info_map *data);

void	malloc_and_fill(t_checker *c, t_info_map *data);
void	free_checker(t_checker *c, int hight);
void	iter_checker(t_checker *c, t_info_map *data, int x, int y);
void	ft_posible(t_info_map *data, int x, int y, int left);

int		ft_window(t_info_map *data);

void	ft_draw_map(t_info_map *data);

void	w_movement(t_info_map *data);
void	a_movement(t_info_map *data);
void	s_movement(t_info_map *data);
void	d_movement(t_info_map *data);
int		ft_press_key(int keycode, t_info_map *data);

int		ft_close(t_info_map *data);

int		ft_strcmpr(char *s1, char *s2);
void	ft_itoa(unsigned int n);
void	ft_write_itoa(unsigned int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(char *s1);
#endif
