/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:16:01 by npiatiko          #+#    #+#             */
/*   Updated: 2019/02/06 18:16:02 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initmap(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			map->distmap[i][j] = 20000;
			j++;
		}
		i++;
	}
}

void	ft_initgame(t_map *map)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strstr(line, "$$$ exec p"))
	{
		map->my = (char)(line[10] == '1' ? 'O' : 'X');
		map->enemy = (char)(line[10] == '1' ? 'X' : 'O');
	}
	free(line);
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		map->x = ft_atoi(line + 8);
		map->y = ft_atoi(line + 8 + ft_nbrlen(map->x) + 1);
	}
	free(line);
	ft_initmap(map);
}

void ft_print_map(t_map *map, t_piece *piece)
{
	int fd;
	int i = 0, j = 0;

	fd = open("test", O_RDWR | O_TRUNC);
	ft_putnbr_fd(map->x, fd);
	ft_putnbr_fd(map->y, fd);
	ft_putchar_fd(map->my, fd);
	ft_putchar_fd(map->enemy, fd);
	ft_putendl_fd("", fd);

	while (i <= map->x)
	{
		j = 0;
		while (j <= map->y)
		{
			ft_putnbr_fd(map->distmap[i][j], fd);
			ft_putstr_fd("\t", fd);
			j++;
		}
		ft_putendl_fd("", fd);
		i++;
	}
	ft_putendl_fd("", fd);
	ft_putnbr_fd(piece->x, fd);
	ft_putstr_fd("  ", fd);
	ft_putnbr_fd(piece->y, fd);
	ft_putendl_fd("", fd);
	ft_putnbr_fd(piece->xcut, fd);
	ft_putstr_fd("  ", fd);
	ft_putnbr_fd(piece->ycut, fd);
	ft_putendl_fd("", fd);


	i = 0;
	while (i < piece->x)
	{
		j = 0;
		while (j < piece->y)
		{
			ft_putchar_fd(piece->piece[i][j], fd);
			j++;
		}
		ft_putendl_fd("", fd);
		i++;
	}

	close(fd);
}

int		main(void)
{
	t_map	map;
	t_piece	piece;

	ft_initgame(&map);
	while (1)
	{
		ft_calc_distmap(&map);
		ft_get_piece(&piece);
//		ft_print_map(&map, &piece);
		if (ft_insert_piece(&map, &piece))
			break ;
	}
	system("leaks -q npiatiko.filler > leaks");
	return (0);
}