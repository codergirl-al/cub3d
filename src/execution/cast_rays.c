/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:53 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/10 17:56:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_ray_images(mlx_t *window, t_ray_data *ray, t_loop_data *data)
{
	ray->img = mlx_new_image(window, MINIMAP_SIZE * data->map_width,
			MINIMAP_SIZE * data->map_height);
	mlx_image_to_window(window, ray->img, 0, 0);
	mlx_set_instance_depth(ray->img->instances, 27);
}

static bool	is_vertical_closer_to_player(int vertical[2], int horizontal[2],
	t_player *player, t_ray_data *ray)
{
	const int	player_pos[2] = {player->img->instances->x + PLAYER_CENTER,
		player->img->instances->y + PLAYER_CENTER};
	const int	adj[2] = {abs(vertical[X] - player_pos[X]),
		abs(horizontal[X] - player_pos[X])};
	const int	opos[2] = {abs(vertical[Y] - player_pos[Y]),
		abs(horizontal[Y] - player_pos[Y])};
	static bool	last_result;
	double		distance[2];

	distance[VERTICAL] = get_hypotenuse(adj[VERTICAL], opos[VERTICAL]);
	distance[HORIZONTAL] = get_hypotenuse(adj[HORIZONTAL], opos[HORIZONTAL]);
	if (distance[VERTICAL] > distance[HORIZONTAL])
		ray->distance = distance[HORIZONTAL];
	else
		ray->distance = distance[VERTICAL];
	if (distance[VERTICAL] == distance[HORIZONTAL])
		return (last_result);
	return (last_result = distance[VERTICAL] < distance[HORIZONTAL]);
}

static int	*get_closer_wall_to_player(t_loop_data *data, t_ray_data *ray)
{
	int			*horizontal;
	int			*vertical;

	horizontal = get_coords_horizontal_ray(data, ray->angle);
	vertical = get_coords_vertical_ray(data, ray->angle);
	if (is_vertical_closer_to_player(vertical, horizontal, data->player, ray))
	{
		ray->orientation = WEST_TEXTURE;
		if (ray->angle <= NORTH && ray->angle >= SOUTH)
			ray->orientation = EAST_TEXTURE;
		return (vertical);
	}
	ray->orientation = NORTH_TEXTURE;
	if (ray->angle <= WEST && ray->angle >= EAST)
		ray->orientation = SOUTH_TEXTURE;
	return (horizontal);
}

t_ray_data	*cast_rays(t_loop_data *data)
{
	static t_ray_data	rays_data[RAY_COUNT];
	int					opos;
	double				angle;
	int					*wall_coords;
	int					i;

	if (rays_data->img == NULL)
		init_ray_images(data->window, rays_data, data);
	else
		ft_clear_image(rays_data->img);
	opos = -RAY_COUNT / 2;
	i = -1;
	while (++i < RAY_COUNT)
	{
		angle = atan((double)opos / (RAY_COUNT / 2)) + data->player->angle;
		rays_data[i].angle = adjust_angle(angle, 0);
		wall_coords = get_closer_wall_to_player(data, &rays_data[i]);
		draw_line_from_player(rays_data->img, data->player, wall_coords,
			0xff00ffff);
		opos++;
	}
	return (rays_data);
}
