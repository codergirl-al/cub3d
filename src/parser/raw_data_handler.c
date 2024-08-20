/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_data_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:42:27 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 02:09:05 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_handle_raw_data(t_data *game)
{
	int		i;
	int		j;
	char	**data;

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
				game->textures = ft_strjoin(game->textures, data[i++]);
				game->textures = ft_strjoin(game->textures, "\n");
			}
			if (ft_handle_textures(game))
				return (ft_arrfree(data), ft_err(game, "Wrong textures\n"));
		}
		else
			return (ft_arrfree(data), ft_err(game, "Could't parse data\n"));
	}
	return (ft_arrfree(data), 1);
}
