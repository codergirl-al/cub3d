/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:22:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/06 15:21:41 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_rectangle(mlx_image_t *img, int start[2], int end[2],
	int color)
{
	int			i;
	int			j;

	i = -1;
	while (++i + start[Y] <= end[Y])
	{
		j = -1;
		while (++j + start[X] <= end[X])
		{
			if (start[X] + j < 0 || start[X] + j >= WIDTH
				|| start[Y] + i < 0 || start[Y] + i >= HEIGHT)
				continue ;
			mlx_put_pixel(img, start[X] + j, start[Y] + i, color);
		}
	}
}

static float	get_vertical_size(t_loop_data *data, int i)
{
	const float	angle = data->rays[i].angle - data->player->angle;
	const float	distance_from_player = data->rays[i].distance;
	const float	distance_from_camera_pane = distance_from_player * cos(angle);
	float		vertical_size;

	vertical_size = MINIMAP_SIZE * HEIGHT / distance_from_camera_pane;
	return (vertical_size);
}

static void	put_minimap_on_top(t_loop_data *data)
{
	const int	new_z = data->fov->instances->z + 1;

	if (data->minimap == NULL
		|| data->fov->instances->z < data->minimap->instances->z)
		return ;
	mlx_set_instance_depth(data->minimap->instances, new_z);
	mlx_set_instance_depth(data->player->img->instances, new_z + 1);
}

enum e_wall_orientation_color
{
	NORTH_TEXTURE_COLOR = 0x004400ff,
	SOUTH_TEXTURE_COLOR = 0x008800ff,
	EAST_TEXTURE_COLOR = 0x448800ff,
	WEST_TEXTURE_COLOR = 0x66cc00ff,
};

void	draw_fov(t_loop_data *data)
{
	const float	horizontal_step = (float)WIDTH / RAY_COUNT;
	float		vertical_size;
	int			i;
	int			color;

	ft_clear_image(data->fov);
	i = -1;
	while (++i < RAY_COUNT)
	{
		vertical_size = get_vertical_size(data, i);
		color = NORTH_TEXTURE_COLOR;
		if (data->rays[i].orientation == SOUTH_TEXTURE)
			color = SOUTH_TEXTURE_COLOR;
		if (data->rays[i].orientation == EAST_TEXTURE)
			color = EAST_TEXTURE_COLOR;
		if (data->rays[i].orientation == WEST_TEXTURE)
			color = WEST_TEXTURE_COLOR;
		draw_rectangle(data->fov, (int [2]){(i * horizontal_step),
			(HEIGHT / 2) - (vertical_size / 2)},
			(int [2]){((i + 1) * horizontal_step) - 1,
			(HEIGHT / 2) + (vertical_size / 2)}, color);
	}
	put_minimap_on_top(data);
}
