/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:31:56 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/11 21:01:14 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_print_err(char *message, int r_value)
{
	ft_putstr_fd(message, 2);
	exit (r_value);
}

int ft_handle_invalid(t_data *playground)
{
  ft_free_data(playground);
  return (ft_print_err("Error\n", 0));
}
