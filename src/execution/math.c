/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:59:21 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/25 18:32:43 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_delta_x(double angle)
{
	return (PLAYER_CENTER * (1 + cos(angle)));
}

double	get_delta_y(double angle)
{
	return (PLAYER_CENTER * (1 + sin(angle)));
}

double	adjust_angle(double angle, int direction)
{
	angle += direction * RADIAN_STEP;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}

int	normalize_coord_to_grid(int coord)
{
	return ((coord >> (int)log2(MINIMAP_SIZE)) << (int)log2(MINIMAP_SIZE));
}

double	get_hypotenuse(int opposite, double angle)
{
	return (opposite / sin(angle));
}

/*
All math can be seen in the following link:
https://www.geogebra.org/graphing/bkd7pzm4
*/