#ifndef FILLER_FILLER_H
# define FILLER_FILLER_H
# include "libft/libft.h"

typedef struct		s_map
{
	int x;
	int y;
	char enemy;
	char my;
	int distmap[100][100];

}					t_map;

typedef struct		s_piece
{
	int		x;
	int		y;
	int 	xcut;
	int 	ycut;
	int 	bestx;
	int		besty;
	int 	sum;
	char	**piece;

}					t_piece;


#endif //FILLER_FILLER_H
