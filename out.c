#include "square.h"

void	out_sizeofside(data d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < d.H)
	{
		j = -1;
		while (++j < d.W)
			printf("%d,", d.sizeofside[i][j]);
		printf("\n");
	}
}

void	out_map(data d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < d.H)
	{
		j = -1;
		while (++j < d.W)
			printf("%c ", d.map[i][j]);
		printf("\n");
	}
}

void	out_data(data d)
{
	out_sizeofside(d);
	out_map(d);
}
