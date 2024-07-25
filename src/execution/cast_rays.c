/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:53 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/25 18:38:13 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_image_t	*init_ray_images(mlx_t *window)
{
	mlx_image_t	*ray;
	int			i;

	i = 0;
	ray = mlx_new_image(window, 1, 1);
	mlx_put_pixel(ray, 0, 0, 0xFF00FFFF);
	while (i <= RAY_COUNT)
	{
		mlx_image_to_window(window, ray, 0, 0);
		i++;
	}
	return (ray);
}

static int	*get_closer_wall_to_player(t_loop_data *data, double angle)
{
	int			*coords;
	int			*horizontal;
	int			*vertical;
	double		h_hypotenuse;
	const int	player_pos[2]
		= {data->player->img->instances->x + PLAYER_CENTER,
		data->player->img->instances->y + PLAYER_CENTER};

	horizontal = get_coords_horizontal_ray(data, angle);
	vertical = get_coords_vertical_ray(data, angle);
	h_hypotenuse = get_hypotenuse(horizontal[Y] - player_pos[Y], angle);
	coords = vertical;
	if (h_hypotenuse < get_hypotenuse(vertical[Y] - player_pos[Y], angle))
		coords = horizontal;
	return (coords);
}

mlx_image_t	*cast_rays(t_loop_data *data)
{
	double				angle;
	static mlx_image_t	*ray = NULL;
	int					*wall_coords;
	int					i;

	if (ray == NULL)
		ray = init_ray_images(data->window);
	i = 0;
	angle = data->player->angle - ((FOV * PI / 180) / 2);
	angle = adjust_angle(angle, 0);
	while (i <= RAY_COUNT)
	{
		wall_coords = get_closer_wall_to_player(data, angle);
		ray->instances[i].x = wall_coords[X];
		ray->instances[i].y = wall_coords[Y];
		angle += (FOV * PI / 180) / RAY_COUNT;
		angle = adjust_angle(angle, 0);
		i++;
	}
	return (ray);
}
