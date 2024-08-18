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

int calc_map_rows_widths(t_data *playground)
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
