/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 21:06:22 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/17 20:48:17 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_data(t_data *gd)
{
	if (gd->map_2d)
		free(gd->map_2d);
	if (gd->texture_2d)
		free(gd->texture_2d);
}

