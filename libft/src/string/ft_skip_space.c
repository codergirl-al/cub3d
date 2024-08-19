/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:31:01 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/18 13:35:52 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_skip_space(char **temp, int x)
{
	int	i;

	i = 0;
	while (temp[x][i] == ' ')
		i++;
	return (i);
}

int ft_skip_spaces(char *temp)
{
	int	i;

	i = 0;
	while (temp[i] == ' ')
		i++;
	return (i);
}
