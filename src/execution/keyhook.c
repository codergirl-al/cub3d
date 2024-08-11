/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:24:43 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/11 13:17:39 by JFikents         ###   ########.fr       */
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

static void	put_minimap_on_top(t_loop_data *data)
{
	const int	fov_z = data->fov->instances->z;
	const int	minimap_z = data->minimap->instances->z;
	const int	player_z = data->player->img->instances->z;

	if (data->minimap == NULL
		|| data->fov->instances->z < data->minimap->instances->z)
		return ;
	mlx_set_instance_depth(data->fov->instances, minimap_z);
	mlx_set_instance_depth(data->minimap->instances, player_z);
	mlx_set_instance_depth(data->player->img->instances, fov_z);
}

void	render_fov(void *param)
{
	t_loop_data *const	data = (t_loop_data *)param;

	if (data->fov == NULL)
	{
		data->fov = mlx_new_image(data->window, WIDTH, HEIGHT);
		mlx_image_to_window(data->window, data->fov, 0, 0);
	}
	data->rays = cast_rays(data);
	draw_fov(data);
	put_minimap_on_top(data);
}
