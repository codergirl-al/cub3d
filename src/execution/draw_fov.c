/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:22:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/11 14:32:23 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	reverse_bytes(int c)
{
	unsigned int	b;

	b = 0;
	b |= (c & 0xFF) << 24;
	b |= (c & 0xFF00) << 8;
	b |= (c & 0xFF0000) >> 8;
	b |= (c & 0xFF000000) >> 24;
	return (b);
}

static double	get_x_offset(const t_ray_data ray, const int texture_width)
{
	double	x_offset;

	if (ray.orientation == NORTH_TEXTURE || ray.orientation == SOUTH_TEXTURE)
		x_offset = fmodf(ray.coords[X] * (texture_width / MINIMAP_SIZE),
				texture_width);
	else
		x_offset = fmodf(ray.coords[Y] * (texture_width / MINIMAP_SIZE),
				texture_width);
	return (x_offset);
}

static void	draw_fov_line(t_loop_data *data, int i, int start[2], int end[2])
{
	const mlx_texture_t	*texture = data->texture[data->rays[i].orientation];
	const double		ratio = 1.0 * texture->height / abs(end[Y] - start[Y]);
	const uint32_t		*pixels = (uint32_t *)texture->pixels;
	const double		x_offset = get_x_offset(data->rays[i], texture->width);
	double				y_offset;

	y_offset = 0;
	while (start[Y] < end[Y])
	{
		if (start[X] >= 0 && start[X] < WIDTH && start[Y] >= 0
			&& start[Y] < HEIGHT)
			mlx_put_pixel(data->fov, start[X], start[Y], reverse_bytes(
					pixels[(int)y_offset * texture->width + (int)x_offset]));
		start[Y]++;
		y_offset += ratio;
	}
}

static float	get_height(t_loop_data *data, int i)
{
	const float	angle
		= adjust_angle(data->rays[i].angle - data->player->angle, 0);
	const float	distance_from_player = data->rays[i].distance;
	const float	distance_from_camera_pane = distance_from_player * cos(angle);
	float		height;

	height = MINIMAP_SIZE * HEIGHT / distance_from_camera_pane / tan(FOV / 2);
	if (height > HEIGHT)
		height = HEIGHT;
	return (height);
}

void	draw_fov(t_loop_data *data)
{
	const float	step_width = (float)WIDTH / RAY_COUNT;
	float		height;
	int			i;

	clear_image(data->fov);
	i = -1;
	while (++i < RAY_COUNT)
	{
		height = get_height(data, i);
		draw_fov_line(data, i, (int [2]){(i * step_width),
			(HEIGHT / 2) - (height / 2)},
			(int [2]){((i + 1) * step_width) - 1,
			(HEIGHT / 2) + (height / 2)});
	}
}
