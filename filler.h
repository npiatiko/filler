/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npiatiko <npiatiko@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:16:30 by npiatiko          #+#    #+#             */
/*   Updated: 2019/02/06 18:16:31 by npiatiko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft/libft.h"

typedef struct		s_map
{
	int		x;
	int		y;
	char	enemy;
	char	my;
	int		distmap[100][100];

}					t_map;

typedef struct		s_piece
{
	int		x;
	int		y;
	int		xcut;
	int		ycut;
	int		bestx;
	int		besty;
	int		sum;
	char	**piece;

}					t_piece;

void				ft_calc_distmap(t_map *map);
void				ft_get_piece(t_piece *piece);
int					ft_insert_piece(t_map *map, t_piece *piece);

#endif
