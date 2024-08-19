/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:59:21 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/11 13:33:45 by JFikents         ###   ########.fr       */
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
	angle += direction * TURNING_ANGLE;
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

double	get_hypotenuse(int adjacent, int opposite)
{
	double	ratio;

	adjacent = abs(adjacent);
	opposite = abs(opposite);
	if (adjacent > opposite)
	{
		ratio = (double)opposite / adjacent;
		return (adjacent * sqrt(1.0 + ratio * ratio));
	}
	if (opposite == 0)
		return (0);
	ratio = (double)adjacent / opposite;
	return (opposite * sqrt(1.0 + ratio * ratio));
}
/*
All math for player movement can be seen in the following link:
https://www.geogebra.org/graphing/bkd7pzm4
*/