/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:19:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/22 17:47:04 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_straight(mlx_image_t *img, int *start, int *final, int color)
{
	int		i;

	i = -1;
	if (start[X] != final[X] && start[Y] != final[Y])
		return ;
	if (start[Y] > final[Y] || start[X] > final[X])
		return (draw_straight(img, final, start, color));
	while (++i + start[Y] <= final[Y] && start[X] == final[X])
		mlx_put_pixel(img, start[X], start[Y] + i, color);
	while (++i + start[X] <= final[X] && start[Y] == final[Y])
		mlx_put_pixel(img, start[X] + i, start[Y], color);
}

void	draw_line(mlx_image_t *img, int start[2], int end[2], int color)
{
	double	slope;
	double	y;
	double	i;

	if (start[X] > end[X])
		return (draw_line(img, end, start, color));
	if (start[X] == end[X] || start[Y] == end[Y])
		return (draw_straight(img, start, end, color));
	y = (double)start[Y];
	slope = (double)(end[Y] - start[Y]) / (end[X] - start[X]);
	while (start[X] <= end[X])
	{
		i = 1;
		while (slope < 0 && --i > slope && y + i >= end[Y])
			mlx_put_pixel(img, start[X], (int)(y + i), color);
		i = -1;
		while (slope > 0 && ++i < slope && y + i <= end[Y])
			mlx_put_pixel(img, start[X], (int)(y + i), color);
		y += slope;
		start[X]++;
	}
}

int	put_player(mlx_t *window, t_player player[1])
{
	player->img = mlx_new_image(window, (PLAYER_CENTER * 2) + 1,
			(PLAYER_CENTER * 2) + 1);
	redraw_player(player);
	mlx_image_to_window(window, player->img,
		(player->x * MINIMAP_SIZE) + MINIMAP_SIZE / 2 - PLAYER_CENTER,
		(player->y * MINIMAP_SIZE) + MINIMAP_SIZE / 2 - PLAYER_CENTER);
	return (0);
}

int	redraw_player(t_player player[1])
{
	mlx_image_t	*img;

	img = player->img;
	ft_bzero(img->pixels, img->width * img->height * sizeof(int));
	draw_line(img, (int []){PLAYER_CENTER - 1, PLAYER_CENTER - 1},
		(int []){(int)(player->delta_x), (int)(player->delta_y)}, 0xff0000FF);
	mlx_put_pixel(img, PLAYER_CENTER - 1, PLAYER_CENTER - 1, 0xffffffFF);
	mlx_put_pixel(img, 0, 0, 0xffff00FF);
	return (0);
}
