/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:16:50 by npiatiko          #+#    #+#             */
/*   Updated: 2019/02/06 18:16:50 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_cutpiece(t_piece *piece)
{
	int	i;
	int	j;

	piece->bestx = 0;
	piece->besty = 0;
	piece->sum = 2000000;
	piece->xcut = 0;
	piece->ycut = 0;
	i = 0;
	while (i < piece->x)
	{
		j = 0;
		while (j < piece->y)
		{
			if (piece->piece[i][j] == '*')
			{
				piece->xcut = i > piece->xcut ? i : piece->xcut;
				piece->ycut = j > piece->ycut ? j : piece->ycut;
			}
			j++;
		}
		i++;
	}
}

void	ft_get_piece(t_piece *piece)
{
	char	*line;
	int		i;

	get_next_line(0, &line);
	if (ft_strstr(line, "Piece"))
	{
		piece->x = ft_atoi(line + 6);
		piece->y = ft_atoi(line + 6 + ft_nbrlen(piece->x) + 1);
	}
	free(line);
	piece->piece = (char**)malloc(piece->x * sizeof(char*));
	i = 0;
	while (i < piece->x)
	{
		get_next_line(0, &line);
		piece->piece[i] = line;
		i++;
	}
	ft_cutpiece(piece);
}
