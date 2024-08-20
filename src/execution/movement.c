/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 13:56:29 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/20 15:23:39 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_movement_x(t_player *const player, int direction, double angle)
{
	if (direction == BACKWARD || direction == FORWARD)
		return (direction * (PLAYER_CENTER - player->delta_x));
	return ((int)(get_delta_x(angle) - PLAYER_CENTER));
}

static int	get_movement_y(t_player *const player, int direction, double angle)
{
	if (direction == BACKWARD || direction == FORWARD)
		return (direction * (PLAYER_CENTER - player->delta_y));
	return ((int)(get_delta_y(angle) - PLAYER_CENTER));
}

static int	*avoid_walls(t_loop_data *data, double *delta)
{
	t_player *const	player = data->player;
	const int		player_pos[2]
		= {player->img->instances->x + PLAYER_CENTER,
		player->img->instances->y + PLAYER_CENTER};

	while (data->map[(int)(player_pos[Y] + delta[Y]) / MINIMAP_SIZE]
		[(int)(player_pos[X]) / MINIMAP_SIZE] == '1'
		|| data->map[(int)(player_pos[Y]) / MINIMAP_SIZE]
		[(int)(player_pos[X] + delta[X]) / MINIMAP_SIZE] == '1')
	{
		delta[X]--;
		delta[Y]--;
		if (delta[Y] == 0 || delta[X] == 0)
		{
			delta[Y] = 0;
			delta[X] = 0;
		}
		if (delta[Y] < 0 && delta[X] != 0)
			delta[Y] += 2;
		if (delta[X] < 0 && delta[Y] != 0)
			delta[X] += 2;
	}
	return ((int *)delta);
}

void	movement(t_loop_data *data, int direction)
{
	t_player *const	player = data->player;
	double			new_angle;
	double			delta[2];

	new_angle = adjust_angle(player->angle - (PI / 2), 0);
	if (direction == RIGHT)
		new_angle = adjust_angle(player->angle + (PI / 2), 0);
	delta[X] = get_movement_x(player, direction, new_angle);
	delta[Y] = get_movement_y(player, direction, new_angle);
	avoid_walls(data, delta);
	player->img->instances->x += delta[X];
	player->img->instances->y += delta[Y];
}
