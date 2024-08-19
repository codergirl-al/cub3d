/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 00:22:43 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/18 16:31:25 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_calc_width(t_data *playground)
{
	unsigned long	i;
	unsigned long	longest;
	unsigned long	width;

	i = -1;
	longest = 0;
	while (++i < playground->map_height)
	{
        width = ft_strlen(playground->map_2d[i]);
        if (longest < width)
            longest = width;
	}
	playground->map_width = longest;
	return (0);
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

int	ft_count_directions(char *temp)
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
