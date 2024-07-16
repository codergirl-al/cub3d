/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:59:21 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/16 20:37:08 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_delta_x(double angle)
{
	return (PLAYER_CENTER * (1 + cos(angle)));
}

double	get_delta_y(double angle)
{
	return (PLAYER_CENTER * (1 + sin(angle)));
}

double	adjust_angle(double angle, int direction)
{
	angle += direction * 0.08727;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

void	draw_h_ray(t_loop_data *data, t_player *player)
{
	int					hit_coords[2];
	static mlx_image_t	*ray;
	const float			ncot = -1 / tan(player->angle);
	const int			player_pos[2]
		= {(player->img->instances->x + PLAYER_CENTER),
		(int)(player->img->instances->y + PLAYER_CENTER)};

	hit_coords[Y] = ((player_pos[Y] >> 6) << 6);
	if (player->angle > PI)
		hit_coords[Y] -= 0.0001;
	if (player->angle < PI)
		hit_coords[Y] += 64;
	hit_coords[X] = (player_pos[Y] - hit_coords[Y]) * ncot + player_pos[X];
	if (ray == NULL)
	{
		ray = mlx_new_image(data->window, 1, 1);
		mlx_put_pixel(ray, 0, 0, 0x00FF00FF);
		mlx_image_to_window(data->window, ray, hit_coords[X], hit_coords[Y]);
	}
	ray->instances->x = hit_coords[X];
	ray->instances->y = hit_coords[Y];
}

void	draw_v_ray(t_loop_data *data, t_player *player)
{
	int					hit_coords[2];
	static mlx_image_t	*ray;
	const float			ntan = -tan(player->angle);
	const int			player_pos[2]
		= {(int)(player->img->instances->x + PLAYER_CENTER),
		(player->img->instances->y + PLAYER_CENTER)};

	hit_coords[X] = ((player_pos[X] >> 6) << 6);
	if (player->angle > PI / 2 && player->angle < 3 * PI / 2)
		hit_coords[X] -= 0.0001;
	else
		hit_coords[X] += 64;
	hit_coords[Y] = (player_pos[X] - hit_coords[X]) * ntan + player_pos[Y];
	if (ray == NULL)
	{
		ray = mlx_new_image(data->window, 1, 1);
		mlx_put_pixel(ray, 0, 0, 0xFF00FFFF);
		mlx_image_to_window(data->window, ray, hit_coords[X], hit_coords[Y]);
	}
	ray->instances->x = hit_coords[X];
	ray->instances->y = hit_coords[Y];
}

/*
All math can be seen in the following link:
https://www.geogebra.org/graphing/bkd7pzm4
*/