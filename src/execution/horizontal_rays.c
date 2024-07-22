/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:02:55 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/18 17:13:46 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_inside_map(int x, int y, t_loop_data *data)
{
	return (x >= 0 && x < MINIMAP_SIZE * data->map_width
		&& y >= 0 && y < MINIMAP_SIZE * data->map_height);
}

static void	find_wall(t_loop_data *data, double angle, int coords[2])
{
	const float			ncot = -1 / tan(angle);
	int					adjustment[2];

	adjustment[X] = MINIMAP_SIZE * ncot;
	adjustment[Y] = -MINIMAP_SIZE;
	if (angle < PI)
	{
		adjustment[X] *= -1;
		adjustment[Y] *= -1;
	}
	while (is_inside_map(coords[X], coords[Y], data)
		&& data->map[coords[Y] / MINIMAP_SIZE][coords[X] / MINIMAP_SIZE] != '1')
	{
		coords[Y] += adjustment[Y];
		coords[X] += adjustment[X];
	}
	if (angle < PI)
		coords[Y] -= 1;
}

static double	get_adjustment_to_where_player_is_facing(double angle)
{
	if (angle > PI)
		return (-0.0001);
	return (MINIMAP_SIZE);
}

int	*get_coords_horizontal_ray(t_loop_data *data, double angle)
{
	static int	coords[2];
	const float	ncot = -1 / tan(angle);
	const int	player_pos[2]
		= {data->player->img->instances->x + PLAYER_CENTER,
		data->player->img->instances->y + PLAYER_CENTER};

	coords[Y] = normalize_coord_to_grid(player_pos[Y]);
	coords[Y] += get_adjustment_to_where_player_is_facing(angle);
	coords[X] = (player_pos[Y] - coords[Y]) * ncot + player_pos[X];
	find_wall(data, angle, coords);
	return (coords);
}
