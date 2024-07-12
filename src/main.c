/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:52:21 by apeposhi          #+#    #+#             */
/*   Updated: 2024/07/12 19:18:46 by JFikents         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_reader(int argc, char **argv, mlx_t *window)
{
	int		fd;
	char	*line;

	if (argc != 2)
		return (ft_print_err("Invalid number of arguments\n", 1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_print_err("Invalid file\n", 1));
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		free(line);
	}
	free(line);
	close(fd);
	window = mlx_init(100, 100, "Cub3D", true);
	return (0);
}


int	main(int argc, char **argv)
{
	mlx_t	window;

	map_reader(argc, argv, &window);
}
