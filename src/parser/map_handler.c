/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/18 13:09:46 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h>

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

static int	ft_skip_spaces(char **temp, int x)
{
	int	i;
	
	i = 0;
	while (temp[x][i] == ' ')
		i++;
	return (i);
		
}

static int ft_validate_full_ones(char **map)
{
	size_t	j;
	size_t	map_length;
	int		found_one;

	j = ft_skip_spaces(map, 0);
	found_one = 0;
	while (map[0][++j] != '\0')
	{
		if (map[0][j] == '1')
			found_one = 1;
		else if (map[0][j] != '1')
			return (0);
	}
	if (!found_one)
		return (0);
	map_length = 0;
	while (map[map_length] != NULL)
		map_length++;
	j = ft_skip_spaces(map, map_length - 1);
	found_one = 0;
	while (map[map_length - 1][++j] != '\0') {
		if (map[map_length - 1][j] == '1')
			found_one = 1;
		else if (map[map_length - 1][j] != '1')
			return (0);
	}
	if (!found_one)
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

static int	ft_count_directions(char *temp)
{
	int	directions[4];
	int	count;
	int	i;
	
	ft_bzero(directions, sizeof(directions));
        count = 0;
        i = -1;
	while (temp[++i]) {
		if (temp[i] == 'N')
			directions[0]++;
		else if (temp[i] == 'S')
			directions[1]++;
		else if (temp[i] == 'W')
			directions[2]++;
		else if (temp[i] == 'E')
			directions[3]++;
	}
	i = -1;
	while (++i < 4)
	  count += directions[i];
	return (count);
}

static int	ft_assign_values(t_data *playground)
{
	size_t	i;
	size_t	j;
	char	*temp;

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
				playground->player_d = playground->map_2d[i][j];
				temp = ft_strdup(playground->map_2d[i]);
				temp[j] = '0';
				playground->map_2d[i] = ft_strdup(temp);
				free(temp);
			}
		}
	}
	return (1);
}

static int	ft_validate_map_elements(t_data *playground)
{
	char *temp;
	int total_directions;

	temp = ft_strdup(playground->map_data);
	temp = ft_cut_chr(temp, '\n');
	temp = ft_cut_chr(temp, ' ');
	temp = ft_cut_chr(temp, '0');
	temp = ft_cut_chr(temp, '1');
	if (ft_strlen(temp) == 0)
		return (ft_handle_invalid(playground));
	total_directions = ft_count_directions(temp);
	if (total_directions != 1)
		return (free(temp), ft_handle_invalid(playground));
	ft_assign_values(playground);
	if (ft_strlen(temp) != 1)
        return (free(temp), ft_handle_invalid(playground));
    free(temp);
	return (0);
}

int ft_handle_map(t_data * playground)
{
	playground->map_2d = ft_split(playground->map_data, '\n');
	ft_validate_map_elements(playground);
	playground->map_height = ft_arrlen(playground->map_2d);
	if (!ft_validate_full_ones(playground->map_2d))
		return (ft_handle_invalid(playground));
	ft_handle_side(playground);
	return (1);
}
