/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:24:43 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/15 18:54:07 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	perpendicular_movement(t_player *player, int direction)
{
	const double	left_angle = adjust_angle(player->angle - (PI / 2), 0);
	const double	right_angle = adjust_angle(player->angle + (PI / 2), 0);
	double			delta_x;
	double			delta_y;

	delta_x = get_delta_x(right_angle) - PLAYER_CENTER;
	delta_y = get_delta_y(right_angle) - PLAYER_CENTER;
	if (direction == -1)
	{
		delta_x = get_delta_x(left_angle) - PLAYER_CENTER;
		delta_y = get_delta_y(left_angle) - PLAYER_CENTER;
	}
	player->img->instances->x += delta_x;
	player->img->instances->y += delta_y;
}

void	player_moves(mlx_key_data_t key, void *param)
{
	t_player	*player;

	player = (t_player *)param;
	if (key.key == MLX_KEY_ESCAPE)
		exit(0);
	if (key.key == MLX_KEY_W)
	{
		player->img->instances->y += player->delta_y - PLAYER_CENTER;
		player->img->instances->x += player->delta_x - PLAYER_CENTER;
	}
	if (key.key == MLX_KEY_S)
	{
		player->img->instances->y += PLAYER_CENTER - player->delta_y;
		player->img->instances->x += PLAYER_CENTER - player->delta_x;
	}
	if (key.key == MLX_KEY_A)
		perpendicular_movement(player, -1);
	if (key.key == MLX_KEY_D)
		perpendicular_movement(player, 1);
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
