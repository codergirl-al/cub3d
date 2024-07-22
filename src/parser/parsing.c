/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:25 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/22 16:59:56 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdio.h>

int ft_read_map(t_data *playground, char *filename, char **data, int iter, int skip) {
  int i;
  char *temp;

  playground->fd = open(filename, O_RDONLY);
  if (playground->fd < 0)
    return ft_print_err("Couldn't open file to read.", 0);
  temp = ft_calloc(1, sizeof(char *));
  free(temp);
  if (skip) {
    temp = get_next_line(playground->fd);
    free(temp);
  }
  i = 0;
  while (i < iter || iter == 0) {
    temp = get_next_line(playground->fd);
    if (temp == NULL) {
      free(temp);
      break;
    }
    *data = ft_strjoin(*data, temp);
    free(temp);
    if (!data) {
      return ft_print_err("Couldn't read data.", 0);
    }
    i++;
  }
  close(playground->fd);
  return (0);
}

int ft_analyze_input_file(char **argv, t_data *playground)
{
  ft_read_map(playground, argv[1], &playground->textures, 4, 0);
  if (!playground->textures || !ft_handle_textures(playground))
    return (ft_print_err("Empty file given.", 0));
  ft_read_map(playground, argv[1], &playground->floor_data, 1, 1);
  if (!playground->floor_data || !ft_handle_input(playground, 'F'))
    return (ft_print_err("Couldn't read floor data", 0));
  ft_read_map(playground, argv[1], &playground->ceiling_data, 1, 0);
  if (!playground->ceiling_data || !ft_handle_input(playground, 'C'))
    return (ft_print_err("Couldn't read ceiling data", 0));
  ft_read_map(playground, argv[1], &playground->map_data, 0, 1);
  if (!playground->map_data || !ft_handle_map(playground))
    return (ft_print_err("Couldn't read map.", 0));
  return (1);
}

int ft_init_map_data(t_data *playground) {
  playground->map_data = malloc(sizeof(char *));
  if (!playground->map_data)
    return (ft_print_err("Couldn't initialize map data", 0));
  return 1;
}

// Main parsing function
t_data ft_parse(int argc, char **argv)
{
  t_data playground;  playground.fd = 3;

  
  if (argc != 2 || !ft_check_ending(argv[1])) {
    write(1, "Error: Something wrong with the arguments given.", 47);
    exit(0);
  }

  ft_init_map_data(&playground);
  ft_analyze_input_file(argv, &playground);

  return playground;
}