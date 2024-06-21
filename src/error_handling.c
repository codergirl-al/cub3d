/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:31:56 by apeposhi          #+#    #+#             */
/*   Updated: 2024/05/14 23:35:47 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.c"

int	ft_print_err(char *message, int r_value)
{
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(message, 2);
	return (r_value);
}