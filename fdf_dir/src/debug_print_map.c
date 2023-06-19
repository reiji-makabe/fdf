#include "map.h"

void	print_map(t_map **map)
{
	int	i;
	int	j;

	i = 0;
	printf("----------\n");
	while (map[i])
	{
		j = 0;
		printf("%d:", i);
		while (map[i][j].end != 1)
		{
			printf("%2d ", (int)map[i][j].vx);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("----------\n");
}
