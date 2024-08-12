/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:04:05 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/12 04:53:50 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	playground;

	ft_bzero(&playground, sizeof(t_data));
	playground.fd = open(argv[1], O_RDONLY);
	if (playground.fd < 0)
		return (ft_print_err("Error\n", 0));
	ft_parse(argc, argv, &playground);
	ft_free_data(&playground);
	close(playground.fd);
	return (0);
}
