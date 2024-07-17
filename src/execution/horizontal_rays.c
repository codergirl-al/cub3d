/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:02:55 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/17 16:55:20 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_inside_map(int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

void	find_h_wall(t_loop_data *data, double angle, int coords[2])
{
	const float			ncot = -1 / tan(angle);
	int					adjustment[2];

	adjustment[X] = 64 * ncot;
	adjustment[Y] = -64;
	if (angle < PI)
	{
		adjustment[X] *= -1;
		adjustment[Y] *= -1;
	}
	while (is_inside_map(coords[X], coords[Y])
		&& data->map[coords[Y] / 64][coords[X] / 64] != '1')
	{
		coords[Y] += adjustment[Y];
		coords[X] += adjustment[X];
	}
	if (angle < PI)
		coords[Y] -= 1;
}

void	draw_horizontal_rays(t_loop_data *data, t_player *player)
{
	int					hit_coords[2];
	static mlx_image_t	*ray;
	const float			ncot = -1 / tan(player->angle);
	const int			player_pos[2]
		= {(player->img->instances->x + PLAYER_CENTER),
		(int)(player->img->instances->y + PLAYER_CENTER)};

	hit_coords[Y] = normalize_coord_to_grid(player_pos[Y]);
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
	find_h_wall(data, player->angle, hit_coords);
	ray->instances->x = hit_coords[X];
	ray->instances->y = hit_coords[Y];
}
