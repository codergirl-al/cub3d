/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/22 00:32:23 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_data(t_data *gd)
{
	if (gd->map_2d)
		free(gd->map_2d);
	if (gd->textures)
		free(gd->textures);
	if (gd->map_data)
		free(gd->map_data);
}

