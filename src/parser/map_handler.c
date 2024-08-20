/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 02:09:34 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_fill_2(char *s2, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		s2[i] = '2';
	return (s2);
}

int	ft_allocate_mem(t_data *playground, char ***r_map)
{
	int	i;

	i = 0;
	while (i < playground->map_height + 2)
	{
		(*r_map)[i] = ft_calloc(playground->map_width + 3, sizeof(char));
		if (!(*r_map)[i])
		{
			while (--i >= 0)
				free((*r_map)[i]);
			free(*r_map);
			return (ft_err(playground, "Calloc failed\n"));
		}
		ft_fill_2((*r_map)[i], playground->map_width + 2);
		i++;
	}
	return (1);
}

int	ft_fill_r_map(t_data *playground, char ***r_map)
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
			if (j < (int)ft_strlen(playground->map_2d[k]) + 1)
			{
				(*r_map)[i][j] = playground->map_2d[k][l];
				if (playground->map_2d[k][l++] == ' ')
					(*r_map)[i][j] = '2';
			}
		}
		k++;
	}
	return (0);
}

int	ft_validate(char **r_map)
{
	int	i;
	int	j;

	i = -1;
	while (r_map[++i])
	{
		j = -1;
		while (r_map[i][++j])
		{
			if (r_map[i][j] == '0')
			{
				if (r_map[i - 1][j] == '2' || r_map[i + 1][j] == '2' \
					|| r_map[i][j - 1] == '2' || r_map[i][j + 1] == '2' \
					|| r_map[i - 1][j - 1] == '2' || r_map[i - 1][j + 1] == '2'
					|| r_map[i + 1][j - 1] == '2' || r_map[i + 1][j + 1] == '2')
					return (1);
			}
		}
	}
	return (0);
}

int	ft_map_checkup(t_data *playground)
{
	char	**r_map;
	int		i;

	i = -1;
	r_map = ft_calloc(playground->map_height + 3, sizeof(char *));
	ft_fill_r_map(playground, &r_map);
	if (ft_validate(r_map))
		return (ft_err(playground, "Invalid map\n"));
	ft_arrfree(r_map);
	return (0);
}

int	ft_validate_map_elements(t_data *playground)
{
	char	*temp;

	temp = ft_strtrim(playground->map_data, " \n01");
	if (ft_strlen(temp) != 1)
		return (free(temp), ft_err(playground, "Invalid map elements given\n"));
	playground->player_d = temp[0];
	free(temp);
	ft_assign_values(playground);
	return (0);
}

int	ft_handle_map(t_data *playground)
{
	playground->map_2d = ft_split(playground->map_data, '\n');
	playground->map_height = ft_arrlen(playground->map_2d);
	playground->map_width = ft_calc_width(playground);
	ft_validate_map_elements(playground);
	ft_map_checkup(playground);
	return (1);
}
