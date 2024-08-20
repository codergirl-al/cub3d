/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 21:05:12 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_validate_map_elements(t_data *playground)
{
	char	*temp;

	temp = ft_strtrim(playground->map_data, " \n01");
	if (ft_strlen(temp) != 1)
		return (free(temp), ft_err(playground, "Invalid map elements given\n"));
	if (ft_strchr("NSWE", temp[0]) == NULL)
		return (free(temp), ft_err(playground, "Invalid player direction\n"));
	playground->player_d = temp[0];
	free(temp);
	ft_assign_values(playground);
	return (0);
}

int	ft_handle_map(t_data *playground)
{
	playground->map_2d = ft_split(playground->map_data, '\n');
	if (!playground->map_2d)
		return (ft_err(playground, "Map is empty\n"));
	playground->map_height = ft_arrlen(playground->map_2d);
	playground->map_width = ft_calc_width(playground);
	ft_validate_map_elements(playground);
	ft_validate_map_layout(playground);
	return (1);
}
