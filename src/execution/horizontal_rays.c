/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_rays.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:02:55 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/18 11:16:44 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_inside_map(int x, int y)
{
	return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

static void	find_wall(t_loop_data *data, double angle, int coords[2])
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

static double	get_adjustment_to_where_player_is_facing(double angle)
{
	if (angle > PI)
		return (-0.0001);
	return (64);
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
