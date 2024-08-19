/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:31:56 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/19 19:45:26 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_print_err(char *message, int r_value)
{
	ft_putstr_fd(message, 2);
	exit (r_value);
}

int	ft_handle_invalid(t_data *playground)
{
	ft_free_data(playground);
	return (ft_print_err("Error\n", 0));
}
