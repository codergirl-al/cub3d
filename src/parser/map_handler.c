/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/15 19:04:46 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <time.h>

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

static int	ft_validate_map(t_data *playground)
{
	char	*temp;

	temp = ft_strdup(playground->map_data);
	temp = ft_cut_chr(temp, '\n');
    temp = ft_cut_chr(temp, '0');
    temp = ft_cut_chr(temp, '1');
	if (ft_strlen(temp) == 0)
		return (ft_handle_invalid(playground)); // no player found
    temp = ft_cut_chr(temp, 'N');
    temp = ft_cut_chr(temp, 'S');
    temp = ft_cut_chr(temp, 'W');
    temp = ft_cut_chr(temp, 'E');
    if (ft_strlen(temp) > 0)
		return (ft_handle_invalid(playground));
	return (0);
}

int ft_handle_map(t_data * playground)
{
	size_t	j;
	size_t	i;

	playground->map_2d = ft_split(playground->map_data, '\n');
	i = 0;
	ft_validate_map(playground);
	ft_validate_full_ones(playground->map_2d[i]);
	while (i < ft_arrlen(playground->map_2d) - 1) {
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

