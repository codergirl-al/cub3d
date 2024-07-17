/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:43 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/17 17:05:38 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static char	*ft_get_map(t_data *gd)
{
	gd->map = ft_strdup("");
	while (gd->line)
	{
		if (gd->line[0] == '\n')
		{
			write(1, "Error\nEmpty line entered\n", 25);
			return (ft_free_data(gd), NULL);
		}
	}
}

int	ft_read_map(void)
{
	return (1);
}

int	ft_validate_map(void)
{
	return (1);
}
