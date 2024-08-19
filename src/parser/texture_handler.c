/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:13:29 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/18 16:36:39 by apeposhi         ###   ########.fr       */
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
	return (1);
}

int	ft_handle_textures(t_data *playground)
{
	char	**txtrs;
	char	**d_txtr;
	int		i;

	txtrs = ft_split(playground->textures, '\n');
	i = 0;
	while (i < 4)
	{
		d_txtr = ft_split(txtrs[i], ' ');
		if ((!ft_strncmp(d_txtr[0], "NO", 2) && i == 0 && ft_check_texture(d_txtr[1])) ||
			(!ft_strncmp(d_txtr[0], "SO", 2) && i == 1 && ft_check_texture(d_txtr[1])) ||
			(!ft_strncmp(d_txtr[0], "WE", 2) && i == 2 && ft_check_texture(d_txtr[1])) ||
			(!ft_strncmp(d_txtr[0], "EA", 2) && i == 3 && ft_check_texture(d_txtr[1])))
			*(&playground->textur.north + i) = d_txtr[1];
		else
		{
			ft_arrfree(d_txtr);
			ft_arrfree(txtrs);
			return (ft_handle_invalid(playground));
		}
		ft_arrfree(d_txtr);
		i++;
	}
	ft_arrfree(txtrs);
	return (1);
}
