/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player_floor_and_ceiling.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:01:23 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/11 14:23:40 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

mlx_image_t	*put_floor_and_ceiling(mlx_t *window, int floor, int ceiling)
{
	uint32_t	x;
	uint32_t	y;
	mlx_image_t	*img;

	img = mlx_new_image(window, WIDTH, HEIGHT);
	y = 0;
	while (y < HEIGHT / 2)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(img, x++, y, ceiling);
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
			mlx_put_pixel(img, x++, y, floor);
		y++;
	}
	mlx_image_to_window(window, img, 0, 0);
	return (img);
}

void	put_player(mlx_t *window, t_player player[1])
{
	player->img = mlx_new_image(window, (PLAYER_CENTER * 2) + 1,
			(PLAYER_CENTER * 2) + 1);
	redraw_player(player);
	mlx_image_to_window(window, player->img,
		(player->x * MINIMAP_SIZE) + MINIMAP_SIZE / 2 - PLAYER_CENTER,
		(player->y * MINIMAP_SIZE) + MINIMAP_SIZE / 2 - PLAYER_CENTER);
}

void	redraw_player(t_player player[1])
{
	mlx_image_t	*img;

	img = player->img;
	clear_image(img);
	draw_line(img, (int []){PLAYER_CENTER - 1, PLAYER_CENTER - 1},
		(int []){(int)(player->delta_x), (int)(player->delta_y)}, 0xff0000FF);
	mlx_put_pixel(img, PLAYER_CENTER - 1, PLAYER_CENTER - 1, 0xffffffFF);
}

static void	draw_minimap_tile(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SIZE - 1)
	{
		j = 0;
		while (j < MINIMAP_SIZE - 1)
			mlx_put_pixel(img, x + j++, y + i, color);
		i++;
	}
}

mlx_image_t	*put_minimap(mlx_t *window, t_loop_data *data)
{
	const char	**map = data->map;
	uint32_t	x;
	uint32_t	y;
	mlx_image_t	*minimap;

	minimap = mlx_new_image(window, data->map_width * MINIMAP_SIZE,
			data->map_height * MINIMAP_SIZE);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_minimap_tile(minimap, x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					MINIMAP_WALL_COLOR);
			else if (map[y][x] != ' ')
				draw_minimap_tile(minimap, x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					MINIMAP_FLOOR_COLOR);
			x++;
		}
		y++;
	}
	mlx_image_to_window(window, minimap, 0, 0);
	return (minimap);
}
