/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:22:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/01 17:05:13 by JFikents         ###   ########.fr       */
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
		j = 0;
		while (++j + start[X] <= end[X])
		{
			if (start[X] + j < 0 || start[X] + j >= WIDTH
				|| start[Y] + i < 0 || start[Y] + i >= HEIGHT)
				continue ;
			mlx_put_pixel(img, start[X] + j, start[Y] + i, color);
		}
	}
}

static int	get_vertical_size(t_loop_data *data, int i)
{
	const double	angle = data->rays[i].angle - data->player->angle;
	const int		hypotenuse = data->rays[i].distance;
	const double	ray_distance = (hypotenuse * cos(angle));
	int				vertical_size;

	vertical_size = HEIGHT;
	if (ray_distance != 0)
		vertical_size = (int)((MINIMAP_SIZE * HEIGHT) / ray_distance);
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
	int			i;
	int			vertical_size;
	int			color;

	ft_bzero(data->fov->pixels, WIDTH * HEIGHT * sizeof(int));
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
