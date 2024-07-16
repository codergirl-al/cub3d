/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:59:21 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/16 18:27:39 by JFikents         ###   ########.fr       */
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

void	draw_h_ray(t_player *player)
{
	int					hit_coords[2];
	static mlx_image_t	*ray;
	const float			cot = -1 / tan(player->angle);

	if (player->angle > PI)
	{
		hit_coords[Y] = (((int)(player->img->instances->y + PLAYER_CENTER) >> 6)
				<< 6) - 0.0001;
		hit_coords[X] = ((int)player->img->instances->y + PLAYER_CENTER
				- hit_coords[Y]) * cot + player->img->instances->x;
	}
	if (player->angle < PI)
	{
		hit_coords[Y] = (((int)(player->img->instances->y + PLAYER_CENTER) >> 6)
				<< 6) + 64;
		hit_coords[X] = ((int)player->img->instances->y + PLAYER_CENTER
				- hit_coords[Y]) * cot + player->img->instances->x;
	}
	hit_coords[X] += PLAYER_CENTER;
	if (ray == NULL)
	{
		ray = mlx_new_image(player->window, 1, 1);
		mlx_put_pixel(ray, 0, 0, 0x00FF00FF);
		mlx_image_to_window(player->window, ray, hit_coords[X], hit_coords[Y]);
	}
	ray->instances->x = hit_coords[X];
	ray->instances->y = hit_coords[Y];
}

void	draw_v_ray(t_player *player)
{
	int					hit_coords[2];
	static mlx_image_t	*ray;
	const float			tangent = -tan(player->angle);

	if (player->angle > PI / 2 && player->angle < 3 * PI / 2)
	{
		hit_coords[X] = (((int)(player->img->instances->x + PLAYER_CENTER) >> 6)
				<< 6) - 0.0001;
		hit_coords[Y] = ((int)player->img->instances->x + PLAYER_CENTER
				- hit_coords[X]) * tangent + player->img->instances->y;
	}
	else
	{
		hit_coords[X] = (((int)(player->img->instances->x + PLAYER_CENTER) >> 6)
				<< 6) + 64;
		hit_coords[Y] = ((int)player->img->instances->x + PLAYER_CENTER
				- hit_coords[X]) * tangent + player->img->instances->y;
	}
	hit_coords[Y] += PLAYER_CENTER;
	if (ray == NULL)
	{
		ray = mlx_new_image(player->window, 1, 1);
		mlx_put_pixel(ray, 0, 0, 0xFF00FFFF);
		mlx_image_to_window(player->window, ray, hit_coords[X], hit_coords[Y]);
	}
	ray->instances->x = hit_coords[X];
	ray->instances->y = hit_coords[Y];
}

/*
All math can be seen in the following link:
https://www.geogebra.org/graphing/bkd7pzm4
*/