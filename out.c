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
			ft_putnum(d.sizeofside[i][j]);
		ft_putchar('\n');
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
			ft_putchar(d.map[i][j]);
		ft_putchar('\n');
	}
}

void	out_data(data d)
{
	out_sizeofside(d);
	out_map(d);
}
