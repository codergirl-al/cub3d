/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:25 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/19 01:30:07 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <fcntl.h>

int ft_analyze_input_file(char **argv, t_data *playground) {
  int i;
  char *temp;
  char *input;

  playground->fd = open(argv[1], O_RDONLY);
  if (playground->fd < 0)
    return ft_print_err("Error: Couldn't open file.", 0);

  input = ft_strdup("");
  if (!input)
    return ft_print_err("Couldn't allocate memory.", 0);

  i = 0;
  while (i < 4 && (temp = get_next_line(playground->fd)) != NULL) {
    input = ft_strjoin(input, temp);
    free(temp);

    if (!input)
      return ft_print_err("Couldn't allocate memory.", 0);

    i++;
  }

  if (i == 0) {
    free(input);
    return ft_print_err("Empty file has been entered.", 0);
  }

  // playground->textures = ft_split(input, '\n');
  free(input);

  // if (!playground->textures)
  //   return ft_print_err("Couldn't split input.", 0);

  // printf("Printing example 1: %s\n", playground->textures[0]);

  close(playground->fd);
  return 1;
}

// Function to initialize map data
int ft_init_map_data(t_data *playground) {
  playground->textures = malloc(sizeof(char *) * 4);
  if (!playground->textures)
    return ft_print_err("Couldn't initialize map data", 0);
  return 1;
}

// Main parsing function
t_data ft_parse(t_data *playground, int argc, char **argv) {
  if (argc != 2 || !ft_check_ending(argv[1])) {
    write(1, "Error: Something wrong with the arguments given.", 47);
    exit(0);
  }

  ft_init_map_data(playground);
  // ft_analyze_input_file(argv, playground);

  return *playground;
}