/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:22:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/10 18:35:26 by JFikents         ###   ########.fr       */
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

// static void	put_pixel_slice(t_loop_data *data, t_ray_data *ray, int pos[2],
// 	int height)
// {
// 	while (height-- > 0)
// 	{
// 		if (pos[Y] + height < 0 || pos[Y] + height >= HEIGHT)
// 			continue ;
// 		mlx_put_pixel(data->fov, pos[X], pos[Y] + (int)height,
// 			data->texture[ray->orientation]->pixels[
// 				(int)(pos[X] % MINIMAP_SIZE) + (int)(height)]);
// 	}
// }

// static void	draw_fov_chunk(t_loop_data *data, int i, int step_width,
// 	float height[2])
// {
// 	float		slope;
// 	float		y;
// 	int			x;
// 	const int	start[2]
// 		= {(i * step_width), (HEIGHT / 2) - (height[0] / 2)};

// 	slope = (height[1] - height[0]) / step_width;
// 	y = (float)start[Y];
// 	x = 0;
// 	while (x < step_width)
// 	{
// 		put_pixel_slice(data, &data->rays[i],
// 			(int [2]){start[X] + x, (int)y}, (int)(height[0] + (slope * x)));
// 		y -= slope;
// 		x++;
// 	}
// }

static float	get_height(t_loop_data *data, int i)
{
	const float	angle
		= adjust_angle(data->rays[i].angle - data->player->angle, 0);
	float		distance_from_player = data->rays[i].distance;
	float		distance_from_camera_pane;
	float		height;

	distance_from_player = data->rays[i].distance;
	distance_from_camera_pane = distance_from_player * cos(angle);
	height = MINIMAP_SIZE * HEIGHT / distance_from_camera_pane;
	return (height);
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
	const float	step_width = (float)WIDTH / RAY_COUNT;
	float		height;
	int			i;
	int			color;

	ft_clear_image(data->fov);
	i = -1;
	while (++i < RAY_COUNT)
	{
		height = get_height(data, i);
		color = NORTH_TEXTURE_COLOR;
		if (data->rays[i].orientation == SOUTH_TEXTURE)
			color = SOUTH_TEXTURE_COLOR;
		if (data->rays[i].orientation == EAST_TEXTURE)
			color = EAST_TEXTURE_COLOR;
		if (data->rays[i].orientation == WEST_TEXTURE)
			color = WEST_TEXTURE_COLOR;
		draw_rectangle(data->fov, (int [2]){(i * step_width),
			(HEIGHT / 2) - (height / 2)},
			(int [2]){((i + 1) * step_width) - 1,
			(HEIGHT / 2) + (height / 2)}, color);
	}
	put_minimap_on_top(data);
}
	// float		next_v_size;
	// next_v_size = get_height(data, 0);
	// if (data->texture[NORTH_TEXTURE] == NULL)
	// 	get_textures(data);
		// height = next_v_size;
		// if (i + 1 < RAY_COUNT)
		// 	next_v_size = get_height(data, i + 1);
		// draw_fov_chunk(data, i, step_width,
		// 	(float [2]){height, next_v_size});
