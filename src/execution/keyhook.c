/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:24:43 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/22 16:30:10 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	recalculate_deltas(t_player *player)
{
	player->delta_x = get_delta_x(player->angle);
	player->delta_y = get_delta_y(player->angle);
}

void	player_moves(mlx_key_data_t key, void *param)
{
	t_loop_data *const	data = (t_loop_data *)param;
	t_player *const		player = data->player;

	if (key.key == MLX_KEY_ESCAPE)
		exit(0);
	if (key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		movement(data, FORWARD);
	if (key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		movement(data, BACKWARD);
	if (key.key == MLX_KEY_A)
		movement(data, LEFT);
	if (key.key == MLX_KEY_D)
		movement(data, RIGHT);
	if (key.key == MLX_KEY_LEFT)
		player->angle = adjust_angle(player->angle, CLOCKWISE);
	if (key.key == MLX_KEY_RIGHT)
		player->angle = adjust_angle(player->angle, COUNTER_CLOCKWISE);
	recalculate_deltas(player);
	redraw_player(player);
}

void	render_fov(void *param)
{
	t_loop_data *const	data = (t_loop_data *)param;

	data->rays = cast_rays(data);
}
