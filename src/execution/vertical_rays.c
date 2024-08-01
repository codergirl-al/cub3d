/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:13:36 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/01 16:15:17 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_wall(t_loop_data *data, double angle, float coords[2])
{
	const float			ntan = -tan(angle);
	float				adjustment[2];
	int					map_coords[2];

	adjustment[X] = MINIMAP_SIZE;
	if (angle > PI / 2 && angle < 3 * PI / 2)
		adjustment[X] *= -1;
	adjustment[Y] = -adjustment[X] * ntan;
	map_coords[X] = (int)(coords[X] / MINIMAP_SIZE);
	map_coords[Y] = (int)(coords[Y] / MINIMAP_SIZE);
	while (is_inside_map(coords[X], coords[Y], data)
		&& data->map[map_coords[Y]][map_coords[X]] != '1')
	{
		coords[X] += adjustment[X];
		coords[Y] += adjustment[Y];
		map_coords[X] = (int)(coords[X] / MINIMAP_SIZE);
		map_coords[Y] = (int)(coords[Y] / MINIMAP_SIZE);
	}
	if (angle < PI / 2 || angle > 3 * PI / 2)
		coords[X] -= 1;
}

static double	get_adjustment_to_where_player_is_facing(double angle)
{
	if (angle > PI / 2 && angle < 3 * PI / 2)
		return (-0.0001);
	return (MINIMAP_SIZE);
}

int	*get_coords_vertical_ray(t_loop_data *data, double angle)
{
	static int	result[2];
	float		coords[2];
	const float	ntan = -tan(angle);
	const int	player_pos[2]
		= {data->player->img->instances->x + PLAYER_CENTER,
		(data->player->img->instances->y + PLAYER_CENTER)};

	coords[X] = normalize_coord_to_grid(player_pos[X]);
	coords[X] += get_adjustment_to_where_player_is_facing(angle);
	coords[Y] = (player_pos[X] - coords[X]) * ntan + player_pos[Y];
	find_wall(data, angle, coords);
	result[X] = coords[X];
	result[Y] = coords[Y];
	return (result);
}
