/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:25 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/17 22:43:35 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <fcntl.h>

// int ft_read_map()
// {
// 	return (1);
// }

int	ft_check_map(char **argv, t_data *playground)
{
	int 	i;
	char	**temp;
	char	**temp2;
	int		fd;

	temp = malloc(sizeof(char *) * 5);
	if (!temp)
	  return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
	  perror("Error opening file");
	  free(temp);
	  return (0);
	}
	i = -1;
	while (++i < 4)
	{
	  temp[i] = get_next_line(fd);
	  if (!temp[i])
	    break;

	  temp2 = ft_split(temp[i], ' ');
	  textures[i] = 
	  if (!playground->textures) {
	    perror("Error splitting line");
	    free(temp);
	    close(fd);
	    return (0);
	  }
	  printf("Printing example 1: %s\n", playground->texture_2d[i]);
	  // printf("Printing example 2: %s\n", playground->texture_2d[2]);
	}

	for (int j = 0; j < i; j++)
	  free(temp[j]);
	free(temp);
	close(fd);
	return (0);
}

// int ft_check_settings(char *argv, t_data *playground)
// {
		
// }

// static void  ft_init_map_data(t_data *playground)
// {
//   // playground->
// }

int	ft_validate_map(char **argv, t_data *playground)
{
	// ft_init_map_data(&playground);
	// if (ft_check_settings(argv, playground))
	// 	return (1);
	if (ft_check_map(argv, playground))
		return (1);
	return (1);
}

t_data	ft_parse(t_data *playground, int argc, char **argv)
{
	// int		c;

	if (argc != 2 || !ft_check_ending(argv[1]))
	{
		write(1, "Error: Something wrong with the arguments given.", 47);
    exit(0);
	}
  ft_validate_map(argv, playground);
  // initialize game
  // ft_execution();
  return (*playground);
}
