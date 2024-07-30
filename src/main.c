/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:52:21 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/30 15:39:37 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// static const char	*map[15] = {
	// 	"1111111111111111111111111",
	// 	"1000000000110000000000001",
	// 	"1011000001110000000000001",
	// 	"100100000000000000000000111111111",
	// 	"111111111011000001110000000000001",
	// 	"100000000011000001110111100011111",
	// 	"11110111111111011100000010001",
	// 	"11110111111111011101010010001",
	// 	"11000000110101011100000010001",
	// 	"10000000000000001100000010001",
	// 	"10000000000000001101010010001",
	// 	"11000001110101011111011110N0111",
	// 	"11110111 1110101 101111010001",
	// 	"11111111 1111111 111111111111", NULL};

	// data->map_height = 14;
	// data->map_width = 33;
	// player->x = 26;
	// player->y = 11;

const char	**get_map(t_player player[1], t_loop_data *data)
{
	static const char	*map[11] = {
		"111111111111",
		"100010000001",
		"100010000001",
		"100001000001",
		"10000N000001",
		"100000000001",
		"100100000001",
		"100010000001",
		"100000000001",
		"111111111111", NULL};

	data->map_height = 10;
	data->map_width = 13;
	player->x = 5;
	player->y = 4;
	player->angle = 3 * PI / 2;
	player->delta_x = get_delta_x(player->angle);
	player->delta_y = get_delta_y(player->angle);
	return (map);
}

void	draw_minimap_tile(mlx_image_t *img, int x, int y, int color)
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

static mlx_image_t	*put_floor_and_ceiling(mlx_t *window, int floor,
	int ceiling)
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

int	main(void)
{
	t_loop_data	data[1];

	data->map = get_map(data->player, data);
	data->window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	put_floor_and_ceiling(data->window, 0x888888FF, 0x008888FF);
	data->minimap = put_minimap(data->window, data);
	put_player(data->window, data->player);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_setting(MLX_FULLSCREEN, true);
	mlx_key_hook(data->window, player_moves, (void *)data);
	mlx_loop_hook(data->window, render_fov, (void *)data);
	mlx_loop(data->window);
	return (0);
}
