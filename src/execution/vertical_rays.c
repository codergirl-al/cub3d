/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:13:36 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/18 17:13:57 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_wall(t_loop_data *data, double angle, int coords[2])
{
	const float			ntan = -tan(angle);
	int					adjustment[2];

	adjustment[X] = MINIMAP_SIZE;
	adjustment[Y] = -MINIMAP_SIZE * ntan;
	if (angle > PI / 2 && angle < 3 * PI / 2)
	{
		adjustment[X] *= -1;
		adjustment[Y] *= -1;
	}
	while (is_inside_map(coords[X], coords[Y], data)
		&& data->map[coords[Y] / MINIMAP_SIZE][coords[X] / MINIMAP_SIZE] != '1')
	{
		coords[X] += adjustment[X];
		coords[Y] += adjustment[Y];
	}
	if (angle < PI / 2 || angle > 3 * PI / 2)
		coords[X] -= 1;
}

static double	get_adjustment_to_where_player_is_facing(double angle)
{
	if (angle > PI / 2 && angle < 3 * PI / 2)
		return (-0.005);
	return (MINIMAP_SIZE);
}

int	*get_coords_vertical_ray(t_loop_data *data, double angle)
{
	static int			coords[2];
	const float			ntan = -tan(angle);
	const int			player_pos[2]
		= {(int)(data->player->img->instances->x + PLAYER_CENTER),
		(data->player->img->instances->y + PLAYER_CENTER)};

	coords[X] = normalize_coord_to_grid(player_pos[X]);
	coords[X] += get_adjustment_to_where_player_is_facing(angle);
	coords[Y] = (player_pos[X] - coords[X]) * ntan + player_pos[Y];
	find_wall(data, angle, coords);
	return (coords);
}
