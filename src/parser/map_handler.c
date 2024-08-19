/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 01:50:56 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_validate_full_ones(char **map)
{
	size_t	j;
	size_t	map_length;

	j = ft_skip_space(map, 0);
	while (map[0][++j] != '\0')
		if (map[0][j] != '1')
		{
			if (map[0][i] == ' ')
			{
				if (map[0][i + 1] != '1')
					return (0);
			}
			else
				return (0);
		}
	map_length = 0;
	while (map[map_length] != NULL)
		map_length++;
	j = ft_skip_space(map, map_length - 1);
	while (map[map_length - 1][++j] != '\0')
		if (map[map_length - 1][j] != '1')
			return (0);
	return (1);
}

static int	ft_handle_side(t_data *playground)
{
	size_t	i;
	size_t	first;
	size_t	last;
	char	*row;

	if (!playground || !playground->map_2d)
		return (0);

	i = -1;
	while (playground->map_2d[++i] != NULL)
	{
		row = playground->map_2d[i];
		first = 0;
		while (row[first] == ' ')
			first++;
		last = ft_strlen(row) - 1;
		while (last > 0 && row[last] == ' ')
			last--;
		if (last <= first || row[first] != '1' || row[last] != '1')
			return (ft_handle_invalid(playground));
	}
	return (1);
}

static void	ft_assign_values(t_data *playground)
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
				return ;
			}
		}
	}
}

static int	ft_validate_map_elements(t_data *playground)
{
	char	*temp;

	temp = ft_strtrim(playground->map_data, " \n01");
	if (ft_strlen(temp) != 1)
		return (free(temp), ft_handle_invalid(playground));
	playground->player_d = temp[0];
	free(temp);
	ft_assign_values(playground);
	return (0);
}

int ft_handle_map(t_data *playground)
{
	int	indicator;

	playground->map_2d = ft_split(playground->map_data, '\n');
	indicator = ft_validate_first(playground);
	ft_validate_map_elements(playground);
	playground->map_height = ft_arrlen(playground->map_2d);
	if (!ft_validate_full_ones(playground->map_2d))
		return (ft_handle_invalid(playground));
	ft_handle_side(playground);
	return (1);
}
