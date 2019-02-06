/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_place.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:17:02 by npiatiko          #+#    #+#             */
/*   Updated: 2019/02/06 18:17:02 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_check_pos(int istart, int jstart, t_map *map, t_piece *piece)
{
	int	i;
	int	j;
	int	count;
	int	sum;

	sum = 0;
	count = 0;
	i = -1;
	while ((j = -1) > -10 && ++i < piece->xcut + 1)
		while (++j < piece->ycut + 1)
			if (piece->piece[i][j] == '*')
			{
				if (map->distmap[i + istart][j + jstart] == -10)
					return ;
				if (map->distmap[i + istart][j + jstart] == -20)
					if (++count > 1)
						return ;
				if (map->distmap[i + istart][j + jstart] > 0)
					sum += map->distmap[i + istart][j + jstart];
			}
	if (count == 1 && sum < piece->sum && (piece->sum = sum))
	{
		piece->bestx = istart;
		piece->besty = jstart;
	}
}

void	ft_del_piece(t_piece *piece)
{
	while (piece->x--)
		free(piece->piece[piece->x]);
	free(piece->piece);
}

int		ft_insert_piece(t_map *map, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->x - piece->xcut)
	{
		j = 0;
		while (j < map->y - piece->ycut)
		{
			ft_check_pos(i, j, map, piece);
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", piece->bestx, piece->besty);
	ft_del_piece(piece);
	return (piece->sum == 2000000 ? 1 : 0);
}
