#include "filler.h"
//#include <stdio.h>
void ft_initdistmap(t_map *map)
{
	char *line;

	ft_bzero(map->distmap, 80000);
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		map->x = ft_atoi(line + 8);
		map->y = ft_atoi(line + 8 + ft_nbrlen(map->x) + 1);
	}

int main(void)
{
	char *line;
	int fd;
	int ret =0;

	t_map map;

	fd = open("test", O_RDWR | O_TRUNC);
	ret = get_next_line(0, &line);
	ft_putendl_fd(line, fd);
	if (line[10] == '2')
		ft_putendl_fd("2!!!!!", fd);
	else
		ft_putendl_fd("1!!!!!", fd);
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			map.x = ft_atoi(line + 8);
			map.y = ft_atoi(line + 8 + ft_nbrlen(map.x) + 1);
			dstmap = (int **)malloc(map.x * sizeof(int *));

			ft_putendl_fd(ft_itoa(map.x), fd);
			ft_putendl_fd(ft_itoa(map.y), fd);
		}

	}
//	while ((ret = get_next_line(0, &line)))
//	{
//		ft_putendl_fd(line, fd);
//		if (ret >= 19)
//		{
//			ft_printf("12 14\n");
//			ret = 0;
//		}
//
//	}

	close(fd);
	return (0);
}