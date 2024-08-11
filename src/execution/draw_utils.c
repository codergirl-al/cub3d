/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:19:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/11 14:23:40 by JFikents         ###   ########.fr       */
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

void	clear_image(mlx_image_t *img)
{
	ft_bzero(img->pixels, img->width * img->height * sizeof(int));
}

void	draw_line_from_player(mlx_image_t *img, t_player *player, int coords[2],
	int color)
{
	int		start[2];
	int		end[2];

	start[X] = player->img->instances->x + PLAYER_CENTER;
	start[Y] = player->img->instances->y + PLAYER_CENTER;
	end[X] = coords[X];
	end[Y] = coords[Y];
	draw_line(img, start, end, color);
}
