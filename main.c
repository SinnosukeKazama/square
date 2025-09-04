#include "square.h"

int main(int ac, char **av)
{
	vec2 crnt;
	data d;

	crnt.x = 0;
	crnt.y = 0;
	d.H = ft_atoi(av[1]);
	d.W = ft_atoi(av[2]);
	if (!init_data(&d))
		return (0);
	generate_map(&d);
	sides_data(&d, &crnt);
	write_sq(&d);
	out_data(d);

	return(0);
}
