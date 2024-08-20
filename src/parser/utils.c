/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 20:52:21 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_data(t_data *gd)
{
	if (gd->map_2d)
		ft_arrfree(gd->map_2d);
	if (gd->textures)
		free(gd->textures);
	if (gd->raw_data)
		free(gd->raw_data);
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

int	ft_err(t_data *playground, char *message)
{
	ft_free_data(playground);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit (0);
}
