/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 19:19:44 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/15 18:52:44 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_coord_valid(int *xy, const mlx_image_t *image)
{
	uint32_t	x;
	uint32_t	y;

	x = *xy;
	y = xy[1];
	if (x < 0 || x >= image->width || y < 0 || y >= image->height)
		return (0);
	return (1);
}

void	put_pixel(const mlx_image_t *img, int x, int y, int color)
{
	mlx_image_t	*image;

	image = (mlx_image_t *)img;
	if (is_coord_valid((int []){x, y}, img))
		mlx_put_pixel(image, x, y, color);
}

static void	draw_straight(const mlx_image_t *img, int *start, int *final,
		int color)
{
	int		i;

	i = -1;
	if (start[0] != final[0] && start[1] != final[1])
		return ;
	if (start[1] > final[1] || start[0] > final[0])
		return (draw_straight(img, final, start, color));
	while (++i + start[1] <= final[1] && start[0] == final[0])
		put_pixel(img, start[0], start[1] + i, color);
	while (++i + start[0] <= final[0] && start[1] == final[1])
		put_pixel(img, start[0] + i, start[1], color);
}

void	draw_line(const mlx_image_t *img, int start[2], int end[2],
		int color)
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
			put_pixel(img, *start, y + i, color);
		while (i++ < slope && slope > 0 && y + i <= end[1] && i >= 0)
			put_pixel(img, *start, y + i, color);
		y += slope;
		*start += 1;
	}
}

int	put_player(mlx_t *window, t_player player[1])
{
	player->img = mlx_new_image(window, 33, 33);
	redraw_player(player);
	mlx_image_to_window(window, player->img, player->x * 64, player->y * 64);
	return (0);
}

int	redraw_player(t_player player[1])
{
	const double	left_angle = adjust_angle(player->angle + (3 * PI / 2), 0);
	const double	right_angle = adjust_angle(player->angle + (PI / 2), 0);

	ft_bzero(player->img->pixels,
		player->img->width * player->img->height * sizeof(int));
	draw_line(player->img, (int []){PLAYER_CENTER, PLAYER_CENTER},
		(int []){(player->delta_x), (player->delta_y)}, 0xff0000FF);
	draw_line(player->img,
		(int []){get_delta_x(left_angle), get_delta_y(left_angle)},
		(int []){get_delta_x(right_angle), get_delta_y(right_angle)},
		0x00ff00FF);
	mlx_put_pixel(player->img, PLAYER_CENTER, PLAYER_CENTER, 0xffffffFF);
	return (0);
}
