/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:12:14 by apeposhi          #+#    #+#             */
/*   Updated: 2024/06/10 12:05:19 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_stack_size(t_stack *stack)
{
	int	len;

	len = 1;
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
