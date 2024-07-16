/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:11:06 by apeposhi          #+#    #+#             */
/*   Updated: 2024/06/04 15:11:52 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_stack	*ft_stack_last(t_stack *str)
{
	while (str)
	{
		if (!str->next)
			return (str);
		str = str->next;
	}
	return (str);
}
