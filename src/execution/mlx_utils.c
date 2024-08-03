/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:53:37 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/03 14:58:11 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_clear_image(mlx_image_t *img)
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
