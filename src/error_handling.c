/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:31:56 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 01:21:03 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_err(t_data *playground, char *message)
{
	ft_free_data(playground);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	exit (0);
}
