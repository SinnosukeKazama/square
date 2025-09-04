#include "square.h"

int	solve_sizeofside(data d, vec2 *crnt)
{
	int	side;
	int	j;//number of index
	int	k;//nubber of index

	side = 0;
	while (side <= ft_min(d.H - crnt->y, d.W - crnt->x))
	{
		j = 0;
		while (j < side)
		{
			k  = 0;
			while (k < side)
			{
				if (d.map[crnt->y + j][crnt->x + k] == 'o')
					return (side - 1);//辺長 －１
				++k;
			}
			++j;
		}
		++side;
	}
	return (side - 1);
}

void	sides_data(data *d, vec2 *crnt)
{
	crnt->y = 0;
	while (crnt->y < d->H)
	{
		crnt->x = 0;
		while (crnt->x < d->W)
		{
			d->sizeofside[crnt->y][crnt->x] = solve_sizeofside(*d, crnt);
			++crnt->x;
		}
		++crnt->y;
	}
}

//一番大きい値を探す。d.sizeofsideの中から
void	solve_max(max *m, data d)
{
	int	i;
	int	j;

	i = -1;
	while (++i < d.H)
	{
		j = -1;
		while (++j < d.W)
		{
			if (m->side < d.sizeofside[i][j])
			{
				m->side = d.sizeofside[i][j];
				m->index.y = i;
				m->index.x = j;
			}
		}
	}
}

void	write_sq(data *d)
{
	max m;
	int	i;
	int	j;

	m.index.y = 0;
	m.index.x = 0;
	m.side = 0;
	solve_max(&m, *d);
	i = -1;
	while (++i < m.side)
	{
		j = -1;
		while (++j < m.side)
			d->map[m.index.y + i][m.index.x + j] = 'x';
	}
}
