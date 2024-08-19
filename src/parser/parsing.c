/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:25 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/20 01:23:44 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_skip_nls(int fd)
{
	char	*temp;

	temp = get_next_line(fd);
	while (temp && *temp == '\n')
	{
		free(temp);
		temp = get_next_line(fd);
	}
	return (temp);
}

int	ft_read_map(t_data *playground)
{
	char	*temp;

	temp = ft_skip_nls(playground->fd);
	playground->map_data = ft_strdup("");
	while (temp)
	{
		if (temp[0] == '\n')
			return (ft_err(playground, "Problem reading map\n"));
		playground->map_data = ft_strjoin(playground->map_data, temp);
		free(temp);
		temp = get_next_line(playground->fd);
	}
	return (0);
}

int	ft_read_settings(t_data *playground)
{
	int		i;
	char	*temp;

	temp = ft_skip_nls(playground->fd);
	i = -1;
	while (++i < 6 && temp)
	{
		if (temp[0] == '\n')
		{
			free(temp);
			temp = ft_skip_nls(playground->fd);
		}
		playground->raw_data = ft_strjoin(playground->raw_data, temp);
		free(temp);
		temp = get_next_line(playground->fd);
	}
	if (temp)
		free(temp);
	return (0);
}

int	ft_analyze_input_file(t_data *playground)
{
	ft_read_settings(playground);
	if (!playground->raw_data || !ft_handle_raw_data(playground))
		return (0);
	ft_read_map(playground);
	if (!playground->map_data || !ft_handle_map(playground))
		return (0);
	return (1);
}

void	ft_parse(int argc, char **argv, t_data *playground)
{
	if (argc != 2)
	{
		write(1, "Error\nInvalid number of arguments passed.\n", 43);
		exit(0);
	}
	if (!ft_check_ending(argv[1]))
	{
		write(1, "Error\nFilename doesn't comply to the rules.\n", 45);
		exit(0);
	}
	ft_analyze_input_file(playground);
}
