/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:46:25 by apeposhi          #+#    #+#             */
/*   Updated: 2024/08/12 04:56:41 by apeposhi         ###   ########.fr       */
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
			return (ft_handle_invalid(playground));
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
			temp = ft_skip_nls(playground->fd);
		playground->raw_data = ft_strjoin(playground->raw_data, temp);
		free(temp);
		temp = get_next_line(playground->fd);
	}
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
	if (argc != 2 || !ft_check_ending(argv[1]))
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	ft_analyze_input_file(playground);
}
