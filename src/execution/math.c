/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:59:21 by JFikents          #+#    #+#             */
/*   Updated: 2024/07/15 18:50:27 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	get_delta_x(double angle)
{
	return (PLAYER_CENTER + (PLAYER_CENTER * cos(angle)));
}

double	get_delta_y(double angle)
{
	return (16 + (16 * sin(angle)));
}

double	adjust_angle(double angle, int direction)
{
	angle += direction * 0.05;
	if (angle < 0)
		angle += 2 * PI;
	if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}
