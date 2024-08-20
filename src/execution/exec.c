/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 14:09:52 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/20 21:25:24 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_textures(t_loop_data *data)
{
	data->texture[NORTH_TEXTURE] = mlx_load_png(data->file_path[NORTH_TEXTURE]);
	data->texture[SOUTH_TEXTURE] = mlx_load_png(data->file_path[SOUTH_TEXTURE]);
	data->texture[EAST_TEXTURE] = mlx_load_png(data->file_path[EAST_TEXTURE]);
	data->texture[WEST_TEXTURE] = mlx_load_png(data->file_path[WEST_TEXTURE]);
}

int	exec(t_loop_data *data)
{
	put_floor_and_ceiling(data->window, data->floor_color, data->ceiling_color);
	data->minimap = put_minimap(data->window, data);
	put_player(data->window, data->player);
	get_textures(data);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx_set_setting(MLX_FULLSCREEN, true);
	mlx_key_hook(data->window, player_moves, (void *)data);
	mlx_loop_hook(data->window, render_fov, (void *)data);
	return (0);
}
