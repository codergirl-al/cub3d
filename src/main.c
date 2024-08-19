/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:52:21 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/19 11:05:49 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

	// static const char	*map[11] = {
	// 	"111111111111",
	// 	"100010000001",
	// 	"100010000001",
	// 	"100001000001",
	// 	"10000N000001",
	// 	"100000000001",
	// 	"100100000001",
	// 	"100010000001",
	// 	"100000000001",
	// 	"111111111111", NULL};

	// data->map_height = 10;
	// data->map_width = 13;
	// player->x = 5;
	// player->y = 4;

const char	**get_map(t_player player[1], t_loop_data *data)
{
	static const char	*map[16] = {
		"                                 ",
		"1111111111111111111111111",
		"1000000000110000000000001",
		"1011000001110000000000001",
		"100100000000000000000000111111111",
		"111111111011000001110000000000001",
		"100000000011000001110111100011111",
		"11110111111111011100000010001",
		"11110111111111011101010010001",
		"11000000110101011100000010001",
		"10000000000000001100000010001",
		"10000000000000001101010010001",
		"11000001110101011111011110N0111",
		"11110111 1110101 101111010001",
		"11111111 1111111 111111111111", NULL};

	data->map_height = 15;
	data->map_width = 33;
	player->x = 26;
	player->y = 11;
	player->angle = NORTH;
	player->delta_x = get_delta_x(player->angle);
	player->delta_y = get_delta_y(player->angle);
	data->file_path[NORTH_TEXTURE] = "textures/north.png";
	data->file_path[SOUTH_TEXTURE] = "textures/south.png";
	data->file_path[EAST_TEXTURE] = "textures/east.png";
	data->file_path[WEST_TEXTURE] = "textures/west.png";
	return (map);
}

int	main(void)
{
	t_loop_data	data[1];

	ft_bzero(data, sizeof(data));
	data->map = get_map(data->player, data);
	data->window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	exec(data);
	mlx_loop(data->window);
	return (0);
}
