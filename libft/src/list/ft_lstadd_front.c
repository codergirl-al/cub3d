/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:05:27 by apeposhi          #+#    #+#             */
/*   Updated: 2023/04/30 12:38:08 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
** @brief Add a node to the start of linked list.
** Equivalence to the 'cons' function in Lisp.
**
** @param lst:   the memory address of the pointer pointing
** to the start of linked list.
** @param front: the node to be added
*/
void	ft_lstadd_front(t_list **lst, t_list *list)
{
	if (lst)
	{
		if (*lst)
			list->next = *lst;
		*lst = list;
	}
}
