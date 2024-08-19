/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:32 by apeposhi          #+#    #+#             */
/*   Updated: 2024/06/10 12:05:16 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_stack	*ft_stack_new(int value)
{
	t_stack	*new_node;

	new_node = NULL;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (new_node)
	{
		new_node -> value = value;
		new_node -> index = -1;
		new_node -> next = NULL;
	}
	return (new_node);
}
