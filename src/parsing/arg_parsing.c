/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaint-p </var/spool/mail/tsaint-p>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 19:01:02 by tsaint-p          #+#    #+#             */
/*   Updated: 2024/03/26 13:17:29 by tsaint-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../include/cub3d.h"

//checks if the map extension is indeed .cub

int	check_map_extension(char *str)
{
	if (!str)
		return (1);
	if (ft_strlen(str) < 4)
		return (1);
	if (ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4))
		return (1);
	return (0);
}

//checks potential errors on arg number or validity of file

int	arg_parsing(int argc, char **argv, t_data *data)
{
	if (argc != 2)
		ft_errornl("Invalid arguments. Usage : ./cub3D [path_to_map]\n");
	else if (argv[1])
	{
		if (check_map_extension(argv[1]))
			return (ft_errornl("Invalid map extension. Expected : *.cub\n"), PARSING_ERROR);
		data->map->fd = open(argv[1], O_RDONLY);
		if (data->map->fd == -1)
			return (ft_errornl(strerror(errno)), PARSING_ERROR);
	}
	return (0);
}
