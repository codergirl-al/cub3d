/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/12 14:35:06 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_data(t_data *gd)
{
	if (gd->map_2d)
		free(gd->map_2d);
	if (gd->map)
		free(gd->map);
	if (gd->ff)
		free(gd->ff);
	if (gd->cc)
		free(gd->cc);
	if (gd->ture)
		free(gd->map_2d);
	if (gd->map_2d)
		free(gd->map_2d);
	if (gd->map_2d)
		free(gd->map_2d);
}
