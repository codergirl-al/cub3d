/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_layout.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 20:58:08 by JFikents          #+#    #+#             */
/*   Updated: 2024/08/20 21:07:02 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_allocate_mem(t_data *playground, char ***r_map)
{
	int	i;

	i = 0;
	while (i < playground->map_height + 2)
	{
		(*r_map)[i] = ft_calloc(playground->map_width + 3, sizeof(char));
		if (!(*r_map)[i])
		{
			ft_arrfree(*r_map);
			return ((void)ft_err(playground, "Calloc failed\n"));
		}
		ft_memset((*r_map)[i], '2', playground->map_width + 2);
		i++;
	}
}

static int	ft_fill_r_map(t_data *playground, char ***r_map)
{
	int	i;
	int	j;
	int	k;
	int	l;

	ft_allocate_mem(playground, r_map);
	i = 0;
	k = 0;
	while (++i < playground->map_height + 2)
	{
		j = 0;
		l = 0;
		while (++j < playground->map_width + 3)
		{
			if (j < (int)ft_strlen(playground->map_2d[k]) + 1
				&& playground->map_2d[k][l++] != ' ')
				(*r_map)[i][j] = playground->map_2d[k][l - 1];
		}
		k++;
	}
	return (0);
}

static bool	is_any_2_arround(char **r_map, int i, int j)
{
	const int	cell_above = i - 1;
	const int	cell_below = i + 1;
	const int	cell_left = j - 1;
	const int	cell_right = j + 1;

	if (r_map[cell_above][j] == '2'
		|| r_map[cell_below][j] == '2'
		|| r_map[i][cell_left] == '2'
		|| r_map[i][cell_right] == '2'
		|| r_map[cell_above][cell_left] == '2'
		|| r_map[cell_above][cell_right] == '2'
		|| r_map[cell_below][cell_left] == '2'
		|| r_map[cell_below][cell_right] == '2')
		return (true);
	return (false);
}

static bool	is_map_enclosed(char **r_map)
{
	int	i;
	int	j;

	i = -1;
	while (r_map[++i])
	{
		j = -1;
		while (r_map[i][++j])
		{
			if (r_map[i][j] == '0' && is_any_2_arround(r_map, i, j))
				return (false);
		}
	}
	return (true);
}

int	ft_validate_map_layout(t_data *playground)
{
	char	**r_map;
	int		i;

	i = -1;
	r_map = ft_calloc(playground->map_height + 3, sizeof(char *));
	ft_fill_r_map(playground, &r_map);
	if (is_map_enclosed(r_map) == false)
		return (ft_err(playground, "Invalid map\n"));
	ft_arrfree(r_map);
	return (0);
}
