/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:25 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/16 23:46:42 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int ft_read_map()
{
	return (1);
}

int ft_check_map(char *argv, t_data *playground)
{
    int		i;
	char	*temp;

	i = -1;
	while (++i < 4)
	{
		temp = get_next_line(argv[1]);
	}
}

int ft_check_settings(char *argv, t_data *playground)
{
		
}

static void  ft_init_map_data(t_data *playground)
{
  // playground->
}

int	ft_validate_map(char *argv, t_data *playground)
{
	ft_init_map_data(&playground);
	if (ft_check_settings(argv, playground))
		return (1);
	if (ft_check_map(argv, playground))
		return (1);
	return (1);
}

t_data	ft_parse(int argc, char **argv)
{
	t_data	playground;
	int		c;

	if (argc != 2 || ft_check_ending(argv[1]))
	{
		write(1, "Error: Something wrong with the arguments given.", 47);
    exit(0);
	}
  ft_validate_map(argv, &playground);
  // initialize game
  // ft_execution();
  return (playground);
}
