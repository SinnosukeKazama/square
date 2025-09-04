#include "square.h"

void	generate_map(data *d)
{
	int	i;
	int	j;
	const unsigned int	seed = (unsigned int)time(NULL);

	i = -1;
	srand(seed);
	while (++i < d->H)
	{
		j = -1;
		while (++j < d->W)
		{
			if(rand() % 10 == 0)
				d->map[i][j] = 'o';
			else
				d->map[i][j] = '.';
		}
	}
}

int	allocate_data(data *d)
{
	int	i;

	i = -1;
	d->sizeofside = (int **)malloc(sizeof(int *) * d->H);
	d->map = (char **)malloc(sizeof(char *) * d->H);
	if (!d->sizeofside || !d->map)
		return (0);
	while (++i < d->H)
	{
		d->sizeofside[i] = ft_int_calloc(d->W);
		d->map[i] = ft_char_calloc(d->W, '\0');
	}
	return (1);
}

void	free_data(data *d)
{
	int	i;

	i = -1;
	while (++i < d->H)
	{
		free(d->sizeofside[i]);
		free(d->map[i]);
	}
	free(d->sizeofside);
	free(d->map);
}
