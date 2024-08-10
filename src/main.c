/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:52:21 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/10 18:37:28 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// static const char	*map[16] = {
	// 	"                                 ",
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

	// data->map_height = 15;
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
	player->angle = NORTH;
	player->delta_x = get_delta_x(player->angle);
	player->delta_y = get_delta_y(player->angle);
	data->file_path[NORTH_TEXTURE] = "textures/wall_1.png";
	data->file_path[SOUTH_TEXTURE] = "textures/wall_2.png";
	data->file_path[EAST_TEXTURE] = "textures/wall_3.png";
	data->file_path[WEST_TEXTURE] = "textures/wall_4.png";
	ft_bzero(data->texture, sizeof(data->texture));
	return (map);
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
