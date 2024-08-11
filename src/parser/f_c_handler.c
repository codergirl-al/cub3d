/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_c_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:23:19 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/12 01:07:52 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	ft_count_chstr()
{
	
}

static int	ft_parse_color(t_data *playground)
{
	char	**rgb;

	if (ft_count_chstr())
}

int ft_handle_input(t_data *playground, char *data, char flag)
{
	playground->ceiling_data = "bkabala";
	data[1] = 'f';
	if (flag == 'C')
 		printf("============== %c: %s\n", flag, playground->ceiling_data);
	else
		printf("============== %c: %s\n", flag, playground->floor_data);
	return (1);
}
