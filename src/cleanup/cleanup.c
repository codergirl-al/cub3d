/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/11 18:45:51 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_textures(t_texture	textur)
{
	if (textur.north)
		free(textur.north);
	if (textur.south)
		free(textur.south);
	if (textur.east)
		free(textur.east);
	if (textur.west)
		free(textur.west);
}

void	ft_free_data(t_data *gd)
{
	if (gd->map_2d)
		free(gd->map_2d);
	// if (gd->textures)
	// 	free(gd->textures);
	if (gd->floor_data)
		free(gd->floor_data);
	if (gd->ceiling_data)
		free(gd->ceiling_data);
	if (gd->map_data)
		free(gd->map_data);
	if (gd->textur.north)
		ft_free_textures(gd->textur);
	// if (gd->raw_data)
	// 	free(gd->raw_data);
}
