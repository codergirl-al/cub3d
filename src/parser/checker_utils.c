/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:14:11 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/15 23:17:31 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_ending(char *filename)
{
	char *d_pos;

	if (!filename)
		return (0);
	d_pos = ft_strrchr(filename, '.');
	if (d_pos && !ft_strcmp(d_pos, ".cub"))
		return (1);
	return (0);
}

