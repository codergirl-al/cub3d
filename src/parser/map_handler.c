/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/18 00:30:54 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

static int	ft_validate_full_ones(char *row)
{
	if (ft_strcountchr(row, '1') == ft_strlen_updated(row))
		return (1);
	return (0);
}

static int ft_handle_side(t_data *playground, size_t i, size_t j)
{
	if (playground->map_2d[i][j] == 1)
	{
		if (j == 0)
		{
			if (playground->map_2d[i][j])
				return (ft_handle_invalid(playground));
		}
		else if (j == ft_strlen(playground->map_2d[i] - 1))
		{
			if (playground->map_2d[i][j])
				return (ft_handle_invalid(playground));
		}
	}
	return (0);
}

static int	ft_count_directions(char *temp)
{
	int	directions[4];
	int	total_directions;
	int	i;
	
	ft_bzero(directions, sizeof(directions));
	total_directions = ft_count_directions(temp);
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
	  total_directions += directions[i];
	return (0);
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
	free(temp);
	if (total_directions != 1)
		return (ft_handle_invalid(playground));
	return (0);
}

int ft_handle_map(t_data * playground)
{
	size_t	j;
	size_t	i;

	playground->map_2d = ft_split(playground->map_data, '\n');
	i = 0;
	ft_validate_map_elements(playground);
	playground->map_height = ft_arrlen(playground->map_2d);
	ft_validate_full_ones(playground->map_2d[i]);
	while (i < playground->map_height - 1)
	{
		j = -1;
		while (playground->map_2d[i][++j])
		{
			if ((j == 0 || j == (ft_strlen(playground->map_2d[i] - 1))))
				ft_handle_side(playground, i, j);
			while (playground->map_2d[i][j] == ' ')
				j++;
		}
	}
	ft_validate_full_ones(playground->map_2d[i]);
	return (1);
}
