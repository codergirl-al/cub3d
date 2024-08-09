/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:01:23 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/09 18:38:48 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_minimap_tile(mlx_image_t *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINIMAP_SIZE - 1)
	{
		j = 0;
		while (j < MINIMAP_SIZE - 1)
			mlx_put_pixel(img, x + j++, y + i, color);
		i++;
	}
}

mlx_image_t	*put_minimap(mlx_t *window, t_loop_data *data)
{
	const char	**map = data->map;
	uint32_t	x;
	uint32_t	y;
	mlx_image_t	*minimap;

	minimap = mlx_new_image(window, data->map_width * MINIMAP_SIZE,
			data->map_height * MINIMAP_SIZE);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_minimap_tile(minimap, x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					MINIMAP_WALL_COLOR);
			else if (map[y][x] != ' ')
				draw_minimap_tile(minimap, x * MINIMAP_SIZE, y * MINIMAP_SIZE,
					MINIMAP_FLOOR_COLOR);
			x++;
		}
		y++;
	}
	mlx_image_to_window(window, minimap, 0, 0);
	return (minimap);
}
