/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:02:55 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/06 12:11:07 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_inside_map(int x, int y, t_loop_data *data)
{
	return (x >= 0 && x < MINIMAP_SIZE * data->map_width
		&& y >= 0 && y < MINIMAP_SIZE * data->map_height);
}

static void	find_wall(t_loop_data *data, double angle, float coords[2])
{
	const float	ncot = -1 / tan(angle);
	float		adjustment[2];
	int			map_coords[2];

	adjustment[Y] = -MINIMAP_SIZE;
	if (angle < PI)
		adjustment[Y] *= -1;
	adjustment[X] = -adjustment[Y] * ncot;
	map_coords[X] = (int)(coords[X] / MINIMAP_SIZE);
	map_coords[Y] = (int)(coords[Y] / MINIMAP_SIZE);
	while (is_inside_map(coords[X], coords[Y], data)
		&& data->map[map_coords[Y]][map_coords[X]] != '1')
	{
		coords[Y] += adjustment[Y];
		coords[X] += adjustment[X];
		map_coords[X] = (int)(coords[X] / MINIMAP_SIZE);
		map_coords[Y] = (int)(coords[Y] / MINIMAP_SIZE);
	}
}

static double	get_adjustment_to_where_player_is_facing(double angle)
{
	if (angle > PI)
		return (-0.0001);
	return (MINIMAP_SIZE);
}

int	*get_coords_horizontal_ray(t_loop_data *data, double angle)
{
	static int	result[2];
	float		coords[2];
	const float	ncot = -1 / tan(angle);
	const int	player_pos[2]
		= {data->player->img->instances->x + PLAYER_CENTER,
		data->player->img->instances->y + PLAYER_CENTER};

	coords[Y] = normalize_coord_to_grid(player_pos[Y]);
	coords[Y] += get_adjustment_to_where_player_is_facing(angle);
	coords[X] = (player_pos[Y] - coords[Y]) * ncot + player_pos[X];
	find_wall(data, angle, coords);
	result[X] = (int)floor(coords[X]);
	result[Y] = (int)floor(coords[Y]);
	return (result);
}
