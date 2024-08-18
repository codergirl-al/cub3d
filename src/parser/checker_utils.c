/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:14:11 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/18 16:26:27 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_check_ending(char *filename)
{
	char	*d_pos;

	if (!filename)
		return (0);
	d_pos = ft_strrchr(filename, '.');
	if (d_pos && !ft_strcmp(d_pos, ".cub\0"))
		return (1);
	return (0);
}

size_t	ft_arrlen(char **arr)
{
  size_t it;

  it = -1;
  if (arr)
    while (arr[++it])
      ;
  return (it);
}

void	ft_arrfree(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_is_number(const char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	ft_digit_check(char *color)
{
	int	color;

	if (!ft_is_number(color))
		return (-1);
	color = ft_atoi(color);
	if (color < 0 || color > 255)
		return (-1);
	return (color);
}
