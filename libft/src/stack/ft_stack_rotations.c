/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:44:16 by apeposhi          #+#    #+#             */
/*   Updated: 2024/06/20 12:48:47 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_stack_rotations(t_stack *stack, int index)
{
	int	counter;

	counter = 0;
	while (stack && stack->index != index)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}
