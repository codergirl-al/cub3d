/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/19 18:12:35 by JFikents         ###   ########.fr       */
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
	if (gd->map_data)
		free(gd->map_data);
	if (gd->textur.north)
		ft_free_textures(gd->textur);
}
