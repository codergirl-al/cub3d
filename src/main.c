/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:52:21 by apeposhi          #+#    #+#             */
/*   Updated: 2024/05/15 00:48:37 by apeposhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int main(int argc, char **argv)
{
	t_game game;

	// init data structure
	// validate arguments
	if (ft_validate_arguments(argc, argv))
		return (1);
	// read into map
	if (ft_read_map(game, char *map))
		return (1);
	// validate the map
	// initialize game
	// set up hookers nd shit
	//         HOOKS
}