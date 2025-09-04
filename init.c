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

int	init_data(data *d)
{
	int	i;

	i = -1;
	d->sizeofside = (int **)malloc(sizeof(int *) * d->H);
	if (!d->sizeofside)
		return (0);
	while (++i < d->H)
		d->sizeofside[i] = ft_int_calloc(d->W);
	i = -1;
	d->map = (char **)malloc(sizeof(char *) * d->H);
	if (!d->map)
		return (0);
	while (++i < d->H)
		d->map[i] = ft_char_calloc(d->W, '\0');
	return (1);
}
