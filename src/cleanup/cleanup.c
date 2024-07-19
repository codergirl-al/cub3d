/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/18 23:25:01 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_data(t_data *gd)
{
	int	i;

	if (gd->map_2d)
		free(gd->map_2d);
	if (gd->textures)
	{
		i = 0;
		while (gd->textures[i++])
			free(gd->textures[i]);
		free(gd->textures);
	}	
}

