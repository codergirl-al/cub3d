/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:18:28 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/12 05:49:53 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_strlen_updated(const char *s)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = -1;
	while (s[++i] != '\0')
		if (s[i] != ' ')
			count++;
	return (count);
}

  static int ft_validate_full_ones(char *row) {
    if (ft_strcountchr(row, '1') == ft_strlen_updated(row))
		return (1);
	return (0);
  }

  static int ft_validate_map(t_data * playground) {
	
  }

  int ft_handle_map(t_data * playground) {
    int longest;
    int j;
    int i;

    playground->map_2d = ft_split(playground->map_data, '\n');
    i = 0;
    longest = 0;
    ft_validate_full_ones(playground->map_2d[i]);
    while (playground->map_2d[++i]) {
      j = -1;
      while (playground->map_2d[i][++j]) {
        while (playground->map_2d[i][j] == ' ')
          j++;
      }
    }
    ft_validate_full_ones(playground->map_2d[i]);
    printf("*** %s ***\n", playground->map_data);
    return (1);
  }
