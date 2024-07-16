/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:25 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/15 20:03:24 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_read_map() 
{
	return (1);
}

int	ft_validate_map() {

	return (1);
}

t_data	ft_parse(int argc, char **argv)
{
	t_data	playground;
	int		c;

	if (argc != 2 || ft_check_ending(argv[1]))
	{
		write()
	}

  // init data structure
  // validate arguments
  if (ft_validate_arguments(argc, argv))
    return (1);
  // read into map
  if (ft_read_map(game, char *map))
    return (1);
  // validate the map
  // initialize game
  return (playground);
}
