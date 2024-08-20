/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:22:43 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 02:36:02 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_calc_width(t_data *playground)
{
	int	i;
	int	longest;
	int	width;

	i = -1;
	longest = 0;
	while (++i < playground->map_height)
	{
		width = ft_strlen(playground->map_2d[i]);
		if (longest < width)
			longest = width;
	}
	return (longest);
}

size_t	ft_strlen_updated(const char *s)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = -1;
	count = 0;
	while (s[++i] != '\0')
		if (s[i] != ' ')
			count++;
	return (count);
}

void	ft_assign_values(t_data *playground)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (playground->map_2d[++i] != NULL)
	{
		j = -1;
		while (playground->map_2d[i][++j] != '\0')
		{
			if (playground->map_2d[i][j] == 'N' \
				|| playground->map_2d[i][j] == 'S' \
				|| playground->map_2d[i][j] == 'W' \
				|| playground->map_2d[i][j] == 'E')
			{
				playground->player_x = j;
				playground->player_y = i;
				playground->map_2d[i][j] = '0';
				return ;
			}
		}
	}
}
