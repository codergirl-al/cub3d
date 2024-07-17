/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:19:53 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/17 20:47:23 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static mlx_image_t	**init_ray_images(mlx_t *window)
{
	static mlx_image_t	*ray[RAY_COUNT + 1];
	int					i;

	i = 0;
	while (i <= RAY_COUNT)
	{
		ray[i] = mlx_new_image(window, 1, 1);
		mlx_put_pixel(ray[i], 0, 0, 0xFF00FFFF);
		mlx_image_to_window(window, ray[i], 0, 0);
		i++;
	}
	return (ray);
}

static int	*get_closer_wall_to_player(t_loop_data *data, double angle)
{
	int		*coords;
	int		*horizontal;
	int		*vertical;
	int		hipotenuse;

	horizontal = get_coords_horizontal_ray(data, angle);
	vertical = get_coords_vertical_ray(data, angle);
	coords = vertical;
	return (coords);
}

void	cast_rays(t_loop_data *data)
{
	double				angle;
	static mlx_image_t	**ray = NULL;
	int					*wall_coords;
	int					i;

	if (ray == NULL)
		ray = init_ray_images(data->window);
	i = 0;
	angle = data->player->angle - ((FOV * PI / 180) / 2);
	while (i <= RAY_COUNT)
	{
		wall_coords = get_closer_wall_to_player(data, angle);
		ray[i]->instances->x = wall_coords[X];
		ray[i]->instances->y = wall_coords[Y];
		angle = adjust_angle(angle, COUNTER_CLOCKWISE);
		i++;
	}
}
