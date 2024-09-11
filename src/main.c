/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:52:21 by apeposhi          #+#    #+#             */
/*   Updated: 2024/09/10 14:24:12 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_rgba(int r, int g, int b, int a)
{
	int	rgba;

	r = r << 24;
	g = g << 16;
	b = b << 8;
	rgba = r | g | b | a;
	return (rgba);
}

static void	init_exec_data(t_loop_data *data, t_data *parsing_data)
{
	data->map_height = parsing_data->map_height;
	data->map_width = parsing_data->map_width;
	data->player->x = parsing_data->player_x;
	data->player->y = parsing_data->player_y;
	if (parsing_data->player_d == 'N')
		data->player->angle = NORTH;
	else if (parsing_data->player_d == 'S')
		data->player->angle = SOUTH;
	else if (parsing_data->player_d == 'E')
		data->player->angle = EAST;
	else if (parsing_data->player_d == 'W')
		data->player->angle = WEST;
	data->player->delta_x = get_delta_x(data->player->angle);
	data->player->delta_y = get_delta_y(data->player->angle);
	data->file_path[NORTH_TEXTURE] = parsing_data->file_path[NORTH_TEXTURE];
	data->file_path[SOUTH_TEXTURE] = parsing_data->file_path[SOUTH_TEXTURE];
	data->file_path[EAST_TEXTURE] = parsing_data->file_path[EAST_TEXTURE];
	data->file_path[WEST_TEXTURE] = parsing_data->file_path[WEST_TEXTURE];
	data->map = (const char **)parsing_data->map_2d;
	data->floor_color = get_rgba(parsing_data->f_colors[0],
			parsing_data->f_colors[1], parsing_data->f_colors[2], 255);
	data->ceiling_color = get_rgba(parsing_data->c_colors[0],
			parsing_data->c_colors[1], parsing_data->c_colors[2], 255);
}

int	main(int argc, char **argv)
{
	t_loop_data	exec_data[1];
	t_data		parsing_data;

	ft_bzero(exec_data, sizeof(exec_data));
	ft_bzero(&parsing_data, sizeof(t_data));
	parsing_data.fd = open(argv[1], O_RDONLY);
	if (parsing_data.fd < 0)
		return (ft_err(&parsing_data, "No map was given\n"));
	ft_parse(argc, argv, &parsing_data);
	close(parsing_data.fd);
	init_exec_data(exec_data, &parsing_data);
	exec_data->window = mlx_init(WIDTH, HEIGHT, "Cub3D", true);
	exec(exec_data);
	mlx_loop(exec_data->window);
	ft_free_data(&parsing_data);
	return (0);
}
