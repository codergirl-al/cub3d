/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_chr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:47:53 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/15 14:58:11 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_cut_chr(char *str, char c)
{
	char	*trimmed;
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	if (!str)
		return (NULL);
	for (i = 0; str[i]; i++)
		if (str[i] != c)
			count++;
	trimmed = (char *)malloc(sizeof(char) * (count + 1));
	if (!trimmed)
		return (NULL);
	for (i = 0; str[i]; i++)
		if (str[i] != c)
			trimmed[j++] = str[i];
	trimmed[j] = '\0';
	free(str);
	return (trimmed);
}
