/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 23:03:00 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/12 14:32:05 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_validate_args(int argc, char **argv)
{
	char	*location;
	int		fd;

	if (argc != 2)
	{
		if (argc == 1)
			write(2, "Error: No map entered.\n", 23);
		else
			write(2, "Error: Too many arguments.\n", 27);
		return (1);
	}
	location = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (location == NULL || location[4] != '\0')
		return (ft_print_err("File type is required to be a .cub", 1));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_print_err("Unable to open map.\n", 1));
	close (fd);
	return (0);
}

