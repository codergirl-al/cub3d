/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:24:43 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/15 19:40:02 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	movement(t_player *player, int direction)
{
	double			new_angle;
	double			delta_x;
	double			delta_y;

	if (direction == BACKWARD || direction == FORWARD)
	{
		delta_x = player->delta_x;
		delta_y = player->delta_y;
		player->img->instances->y += direction * (PLAYER_CENTER - delta_y);
		player->img->instances->x += direction * (PLAYER_CENTER - delta_x);
		return ;
	}
	new_angle = adjust_angle(player->angle - (PI / 2), 0);
	if (direction == RIGHT)
		new_angle = adjust_angle(player->angle + (PI / 2), 0);
	delta_x = get_delta_x(new_angle) - PLAYER_CENTER;
	delta_y = get_delta_y(new_angle) - PLAYER_CENTER;
	player->img->instances->x += delta_x;
	player->img->instances->y += delta_y;
}

void	player_moves(mlx_key_data_t key, void *param)
{
	t_player *const	player = (t_player *)param;

	if (key.key == MLX_KEY_ESCAPE)
		exit(0);
	if (key.key == MLX_KEY_W)
		movement(player, FORWARD);
	if (key.key == MLX_KEY_S)
		movement(player, BACKWARD);
	if (key.key == MLX_KEY_A)
		movement(player, LEFT);
	if (key.key == MLX_KEY_D)
		movement(player, RIGHT);
	if (key.key == MLX_KEY_LEFT)
	{
		player->angle = adjust_angle(player->angle, -1);
		player->delta_x = get_delta_x(player->angle);
		player->delta_y = get_delta_y(player->angle);
	}
	if (key.key == MLX_KEY_RIGHT)
	{
		player->angle = adjust_angle(player->angle, 1);
		player->delta_x = get_delta_x(player->angle);
		player->delta_y = get_delta_y(player->angle);
	}
	redraw_player(player);
}
