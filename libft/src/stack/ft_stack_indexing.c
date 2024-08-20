/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_indexing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:17:23 by apeposhi          #+#    #+#             */
/*   Updated: 2024/06/10 12:04:52 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_stack_indexing(t_stack **s)
{
	t_stack	*head;
	int		index;

	index = 0;
	while (ft_stack_min(s) != NULL)
	{
		head = ft_stack_min(s);
		head->index = index;
		index++;
	}
}
