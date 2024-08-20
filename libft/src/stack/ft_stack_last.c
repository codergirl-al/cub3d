/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:11:06 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/19 18:06:14 by JFikents         ###   ########.fr       */
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
