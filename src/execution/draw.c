/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:19:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/18 13:39:40 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_straight(mlx_image_t *img, int *start, int *final, int color)
{
	int		i;

	i = -1;
	if (start[0] != final[0] && start[1] != final[1])
		return ;
	if (start[1] > final[1] || start[0] > final[0])
		return (draw_straight(img, final, start, color));
	while (++i + start[1] <= final[1] && start[0] == final[0])
		mlx_put_pixel(img, start[0], start[1] + i, color);
	while (++i + start[0] <= final[0] && start[1] == final[1])
		mlx_put_pixel(img, start[0] + i, start[1], color);
}

void	draw_line(mlx_image_t *img, int start[2], int end[2], int color)
{
	float	slope;
	float	y;
	float	i;

	if (start[0] > end[0])
		return (draw_line(img, end, start, color));
	if (start[0] == end[0] || start[1] == end[1])
		return (draw_straight(img, start, end, color));
	y = start[1];
	slope = (double)(end[1] - start[1]) / (end[0] - start[0]);
	while (*start <= end[0])
	{
		i = 1;
		while (--i > slope && slope < 0 && y + i >= end[1])
			mlx_put_pixel(img, *start, y + i, color);
		while (i++ < slope && slope > 0 && y + i <= end[1] && i >= 0)
			mlx_put_pixel(img, *start, y + i, color);
		y += slope;
		*start += 1;
	}
}

int	put_player(mlx_t *window, t_player player[1])
{
	player->img = mlx_new_image(window, (PLAYER_CENTER * 2) + 1,
			(PLAYER_CENTER * 2) + 1);
	redraw_player(player);
	mlx_image_to_window(window, player->img, player->x * MINIMAP_SIZE,
		player->y * MINIMAP_SIZE);
	return (0);
}

int	redraw_player(t_player player[1])
{
	ft_bzero(player->img->pixels,
		player->img->width * player->img->height * sizeof(int));
	draw_line(player->img, (int []){PLAYER_CENTER, PLAYER_CENTER},
		(int []){(player->delta_x), (player->delta_y)}, 0xff0000FF);
	mlx_put_pixel(player->img, PLAYER_CENTER, PLAYER_CENTER, 0xffffffFF);
	mlx_put_pixel(player->img, 0, 0, 0xffff00FF);
	return (0);
}
