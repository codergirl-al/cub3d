/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_data_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 04:42:27 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/19 19:45:00 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_handle_raw_data(t_data *playground)
{
	int		i;
	int		j;
	char	**data;

	i = -1;
	data = ft_split(playground->raw_data, '\n');
	while (++i < 6)
	{
		if (data[i][0] == 'F')
			ft_handle_input(playground, data[i], 'F');
		else if (data[i][0] == 'C')
			ft_handle_input(playground, data[i], 'C');	
		else if (data [i][0] == 'N')
		{
			j = -1;
			while (++j < 4)
			{
				playground->textures = ft_strjoin(playground->textures, data[i++]);
				playground->textures = ft_strjoin(playground->textures, "\n");
			}
			ft_handle_textures(playground);
		}
		else
			return (ft_arrfree(data), ft_handle_invalid(playground));
	}
	return (ft_arrfree(data), 1);
}
