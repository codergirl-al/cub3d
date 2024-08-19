/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 00:29:33 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_data(t_data *gd)
{
	if (gd->map_2d)
		free(gd->map_2d);
	if (gd->map_data)
		free(gd->map_data);
	if (gd->file_path[NORTH_TEXTURE])
		free(gd->file_path[NORTH_TEXTURE]);
	if (gd->file_path[SOUTH_TEXTURE])
		free(gd->file_path[SOUTH_TEXTURE]);
	if (gd->file_path[EAST_TEXTURE])
		free(gd->file_path[EAST_TEXTURE]);
	if (gd->file_path[WEST_TEXTURE])
		free(gd->file_path[WEST_TEXTURE]);
}
