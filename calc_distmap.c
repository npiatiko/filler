/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_distmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:16:13 by npiatiko          #+#    #+#             */
/*   Updated: 2019/02/06 18:16:13 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_calc_dist(int x, int y, t_map *map)
{
	int	i;
	int	j;
	int	dist;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if ((dist = ft_pow((i - x), 2) +
						ft_pow((j - y), 2)) < map->distmap[i][j])
				map->distmap[i][j] = map->distmap[i][j] > 0 ?
									dist : map->distmap[i][j];
			j++;
		}
		i++;
	}
}

void	ft_calc_distmap(t_map *map)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (i < map->x)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
		{
			j = -1;
			while (++j < map->y)
				if (line[j + 4] == map->enemy)
				{
					if (map->distmap[i][j] > 0)
						ft_calc_dist(i, j, map);
					map->distmap[i][j] = -10;
				}
				else if (line[j + 4] == map->my)
					map->distmap[i][j] = -20;
			i++;
		}
		free(line);
	}
}
