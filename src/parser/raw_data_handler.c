/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_data_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:42:27 by apeposhi          #+#    #+#             */
/*   Updated: 2024/09/14 20:17:03 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_handle_raw_data(t_data *game)
{
	char	**data;
	int		i;
	int		j;

	i = -1;
	data = ft_split(game->raw_data, '\n');
	while (++i < 6)
	{
		if (data[i][0] == 'F' || data[i][0] == 'C')
			ft_handle_input(game, data[i], data[i][0]);
		else if (data [i][0] == 'N')
		{
			j = -1;
			while (++j < 4)
			{
				game->textures = ft_strjoin(game->textures, data[i + j]);
				game->textures = ft_strjoin(game->textures, "\n");
			}
			i += 3;
			if (ft_handle_textures(game))
				return (ft_arrfree(data), ft_err(game, "Wrong textures\n"));
		}
		else
			return (ft_arrfree(data), ft_err(game, "Could't parse data\n"));
	}
	return (ft_arrfree(data), 1);
}
