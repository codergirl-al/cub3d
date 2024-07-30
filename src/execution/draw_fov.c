/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 16:22:28 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/30 15:26:42 by JFikents         ###   ########.fr       */
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

static int	get_vertical_size(t_loop_data *data, int i)
{
	const double	angle
		= adjust_angle(data->player->angle + (i * PI / 180), 0);
	const int		opposite_side = (data->rays->instances[i].y
			- (data->player->img->instances->y + PLAYER_CENTER));
	const int		hypotenuse = (int) get_hypotenuse(opposite_side, angle);
	const double	ray_distance = (hypotenuse * cos((i * PI / 180)));
	int				vertical_size;

	vertical_size = 0;
	if (ray_distance != 0)
		vertical_size = (int)((MINIMAP_SIZE * HEIGHT) / ray_distance);
	return (vertical_size);
}

static void	put_minimap_on_top(t_loop_data *data)
{
	const int			new_z = data->fov->instances->z + 1;

	if (data->minimap == NULL
		|| data->fov->instances->z < data->minimap->instances->z)
		return ;
	mlx_set_instance_depth(data->minimap->instances, new_z);
	mlx_set_instance_depth(data->player->img->instances, new_z + 1);
}

void	draw_fov(t_loop_data *data)
{
	const int	horizontal_step = WIDTH / (RAY_COUNT - 1);
	int			i;
	int			vertical_size;

	ft_bzero(data->fov->pixels, WIDTH * HEIGHT * sizeof(int));
	i = -1;
	while (++i <= RAY_COUNT)
	{
		vertical_size = get_vertical_size(data, i);
		draw_rectangle(data->fov, (int [2]){i * horizontal_step,
			(HEIGHT / 2) - (vertical_size / 2)},
			(int [2]){(i + 1) *horizontal_step, (HEIGHT / 2)
			+ (vertical_size / 2)},
			0x004400ff);
	}
	put_minimap_on_top(data);
}
