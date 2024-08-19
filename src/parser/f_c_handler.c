/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:23:19 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/19 19:44:01 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strcountchr(char *str, char c)
{
	int		i;
	size_t	counter;

	i = -1;
	counter = 0;
	while (str[++i])
	{
		if (str[i] == c)
			counter++;
	}
	return (counter);
}

static int	ft_parse_color(char *data, int colors[3])
{
	char	**rgb;
	char	**prsd;	

	prsd = ft_split(data, ' ');
	if (ft_strcountchr(prsd[1], ',') != 2)
		return (1);
	rgb = ft_split(prsd[1], ',');
	if (ft_arrlen(rgb) != 3)
		return (ft_arrfree(rgb), 1);
	colors[0] = ft_digit_check(rgb[0]);
	colors[1] = ft_digit_check(rgb[1]);
	colors[2] = ft_digit_check(rgb[2]);
	return (ft_arrfree(rgb), ft_arrfree(prsd), 0);
}

int	ft_handle_input(t_data *playground, char *data, char flag)
{
	if (flag == 'C')
	{
		ft_parse_color(data, playground->c_colors);
	}
	else if (flag == 'F')
	{
		ft_parse_color(data, playground->f_colors);
	}
	return (1);
}
