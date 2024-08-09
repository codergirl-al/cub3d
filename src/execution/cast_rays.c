/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:53 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/09 19:00:58 by JFikents         ###   ########.fr       */
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
	bool		result;
	const int	player_pos[2] = {player->img->instances->x + PLAYER_CENTER,
		player->img->instances->y + PLAYER_CENTER};
	const int	adjecent[2] = {abs(vertical[X] - player_pos[X]),
		abs(horizontal[X] - player_pos[X])};
	const int	oposite[2] = {abs(vertical[Y] - player_pos[Y]),
		abs(horizontal[Y] - player_pos[Y])};
	static bool	last_result;

	result = adjecent[VERTICAL] + oposite[VERTICAL]
		< adjecent[HORIZONTAL] + oposite[HORIZONTAL];
	if (result == true)
		ray->distance = get_hypotenuse(adjecent[VERTICAL], 0, ray);
	else
		ray->distance = get_hypotenuse(0, oposite[HORIZONTAL], ray);
	if (adjecent[VERTICAL] + oposite[VERTICAL]
		== adjecent[HORIZONTAL] + oposite[HORIZONTAL])
		return (last_result);
	return (last_result = result);
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
	double				angle;
	double				angle_step;
	int					*wall_coords;
	int					i;

	if (rays_data->img == NULL)
		init_ray_images(data->window, rays_data, data);
	else
		ft_clear_image(rays_data->img);
	i = 0;
	angle_step = PI / 180;
	angle = data->player->angle - ((RAY_COUNT - 1) / 2 * angle_step);
	angle = adjust_angle(angle, 0);
	while (i < RAY_COUNT)
	{
		wall_coords = get_closer_wall_to_player(data, &rays_data[i]);
		rays_data[i].angle = angle;
		draw_line_from_player(rays_data->img, data->player, wall_coords,
			0xff00ffff);
		angle += angle_step;
		angle = adjust_angle(angle, 0);
		i++;
	}
	return (rays_data);
}
