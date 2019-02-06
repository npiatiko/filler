#include "filler.h"
//#include <stdio.h>

void ft_initmap(t_map *map)
{
	int i = 0;
	int j = 0;

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

void ft_calc_dist(int x, int y, t_map *map)
{
	int i = 0;
	int j = 0;
	int dist;

	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if ((dist = ft_pow((i - x), 2) + ft_pow((j - y), 2)) < map->distmap[i][j])
				map->distmap[i][j] = map->distmap[i][j] > 0 ? dist : map->distmap[i][j];
			j++;
		}
		i++;
	}
}

void ft_calc_distmap(t_map *map)
{
	char *line;
	int i = 0;
	int j = 0;

	while (i < map->x)
	{
		get_next_line(0, &line);
		if (ft_isdigit(line[0]))
		{
			j = 0;
			while (j < map->y)
			{
				if (line [j + 4] == map->enemy)
				{
					if (map->distmap[i][j] > 0)
						ft_calc_dist(i, j, map);
					map->distmap[i][j] = -10;
				}
				else if (line [j + 4] == map->my)
					map->distmap[i][j] = -20;
				j++;
			}
			i++;
		}
		free(line);
	}
}
void ft_initgame(t_map *map)
{
	char *line;

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
//	ft_calc_distmap(map);

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

void ft_get_piece(t_piece *piece)
{
	char *line;
	int i;

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
}

int ft_check_pos(int istart, int jstart, t_map *map, t_piece *piece)
{
//	int imax;
//	int jmax;
	int i;
	int j;
	int count;

	count = 0;
//	imax = istart + piece->x;
//	jmax = jstart + piece->y;
	i = 0;
	while(i < piece->x)
	{
		j = 0;
		while (j < piece->y)
		{
			if (piece->piece[i][j] == '*' && map->distmap[i + istart][j + jstart] == -10)
				return 0;
			if (piece->piece[i][j] == '*' && map->distmap[i + istart][j + jstart] == -20)
				count++;
			j++;
		}
		i++;
	}
	return count == 1 ? 1 : 0;
}

void ft_insert_piece(t_map *map, t_piece *piece)
{
	int i = 0;
	int j;
//	int  fd;

	while(i < map->x - piece->x)
	{
		j = 0;
		while (j < map->y - piece->y)
		{
			if (ft_check_pos(i, j, map, piece))
			{
//				fd = open("test", O_RDWR | O_TRUNC);
//				ft_putnbr_fd(i, fd);
//				ft_putstr_fd("  ", fd);
//				ft_putnbr_fd(j, fd);
//				ft_putendl_fd("", fd);
//				close(fd);
				ft_printf("%d %d\n", i, j);
				return;
			}
			j++;
		}
		i++;
	}
	ft_printf("%d %d\n", 0, 0);
}
int main(void)
{
	t_map map;
	t_piece piece;

//	ft_putnbr_fd(123, fd);
	ft_initgame(&map);
	while (1)
	{
		ft_calc_distmap(&map);
		ft_get_piece(&piece);
		ft_insert_piece(&map, &piece);
	}
//	ft_print_map(&map, &piece);
	return (0);
}