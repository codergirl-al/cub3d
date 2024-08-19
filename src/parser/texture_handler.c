/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:13:29 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/19 21:34:29 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	ft_check_texture(char *t)
{
	int	fd;

	fd = open(t, O_RDONLY);
	if (fd > 0)
	{
		close(fd);
		return (true);
	}
	return (false);
}

static bool	is_valid_texture_format(char *txtr, int i)
{
	if ((!ft_strncmp(txtr, "NO", 2) && i == 0)
		|| (!ft_strncmp(txtr, "SO", 2) && i == 1)
		|| (!ft_strncmp(txtr, "WE", 2) && i == 2)
		|| (!ft_strncmp(txtr, "EA", 2) && i == 3))
		return (true);
	return (false);
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
		if (is_valid_texture_format(d_txtr[0], i)
			&& ft_check_texture(d_txtr[1]))
			playground->file_path[i] = ft_strdup(d_txtr[1]);
		else
		{
			ft_arrfree(d_txtr);
			ft_arrfree(txtrs);
			return (ft_putstr_fd("Invalid texture format\n", 2), 1);
		}
		ft_arrfree(d_txtr);
		i++;
	}
	ft_arrfree(txtrs);
	return (0);
}
