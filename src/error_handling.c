/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:31:56 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/12 14:34:27 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_print_err(char *message, int r_value)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	return (r_value);
}
