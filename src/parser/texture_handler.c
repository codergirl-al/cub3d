/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:13:29 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/12 04:53:12 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_check_texture(char *t)
{
	int	fd;

	fd = open(t, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (0);
	}
	close (fd);
	return (1);
}

int	ft_handle_textures(t_data *playground)
{
	char	**txtrs;
	char	**d_txtr;

	txtrs = ft_split(playground->textures, '\n');
	d_txtr = ft_split(txtrs[0], ' ');
	if (!ft_strncmp(d_txtr[0], "NO", 2) && ft_check_texture(d_txtr[1]))
		playground->textur.north = d_txtr[1];
	else
		return (ft_handle_invalid(playground));
	d_txtr = ft_split(txtrs[1], ' ');
	if (!ft_strncmp(d_txtr[0], "SO", 2) && ft_check_texture(d_txtr[1]))
		playground->textur.south = d_txtr[1];
	else
		return (ft_handle_invalid(playground));
	d_txtr = ft_split(txtrs[2], ' ');
	if (!ft_strncmp(d_txtr[0], "WE", 2) && ft_check_texture(d_txtr[1]))
		playground->textur.west = d_txtr[1];
	else
		return (ft_handle_invalid(playground));
	d_txtr = ft_split(txtrs[3], ' ');
	if (!ft_strncmp(d_txtr[0], "EA", 2) && ft_check_texture(d_txtr[1]))
		playground->textur.east = d_txtr[1];
	else
		return (ft_handle_invalid(playground));
	return (1);
}
