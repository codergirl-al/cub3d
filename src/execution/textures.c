/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 18:41:42 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/10 13:27:50 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_textures(t_loop_data *data)
{
	data->texture[NORTH_TEXTURE] = mlx_load_png(data->file_path[NORTH_TEXTURE]);
	data->texture[SOUTH_TEXTURE] = mlx_load_png(data->file_path[SOUTH_TEXTURE]);
	data->texture[EAST_TEXTURE] = mlx_load_png(data->file_path[EAST_TEXTURE]);
	data->texture[WEST_TEXTURE] = mlx_load_png(data->file_path[WEST_TEXTURE]);
}
