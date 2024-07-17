/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:13:36 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/17 15:56:19 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_v_wall(t_loop_data *data, t_player *player, int coords[2])
{
	const float			ntan = -tan(player->angle);
	int					adjustment[2];

	adjustment[X] = 64;
	adjustment[Y] = -64 * ntan;
	if (player->angle > PI / 2 && player->angle < 3 * PI / 2)
	{
		adjustment[X] *= -1;
		adjustment[Y] *= -1;
	}
	while (is_inside_map(coords[X], coords[Y])
		&& data->map[coords[Y] / 64][coords[X] / 64] != '1')
	{
		coords[X] += adjustment[X];
		coords[Y] += adjustment[Y];
	}
	if (player->angle < PI / 2 || player->angle > 3 * PI / 2)
		coords[X] -= 1;
}

void	draw_vertical_ray(t_loop_data *data, t_player *player)
{
	int					hit_coords[2];
	static mlx_image_t	*ray;
	const float			ntan = -tan(player->angle);
	const int			player_pos[2]
		= {(int)(player->img->instances->x + PLAYER_CENTER),
		(player->img->instances->y + PLAYER_CENTER)};

	hit_coords[X] = normalize_coord_to_grid(player_pos[X]);
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
	find_v_wall(data, player, hit_coords);
	ray->instances->x = hit_coords[X];
	ray->instances->y = hit_coords[Y];
}
