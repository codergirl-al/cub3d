/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:10:23 by apeposhi          #+#    #+#             */
/*   Updated: 2024/06/10 12:04:38 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_stack_add_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*lista;

	if (lst)
	{
		if (*lst)
		{
			lista = ft_stack_last(*lst);
			lista -> next = new_node;
		}
		else
			*lst = new_node;
	}
}
