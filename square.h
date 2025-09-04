#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vec2{int x;int y;}vec2;
typedef struct max{int side; vec2 index;}max;
typedef struct data{
	int	H;
	int	W;
	char	**map;
	int	**sizeofside;
}data;

int	allocate_data(data *d);
void	generate_map(data *d);
void	free_data(data *d);

int	solve_sizeofside(data d, vec2 *crnt);
void	sides_data(data *d, vec2 *crnt);
void	solve_max(max *m, data d);
void	write_sq(data *d);

void	out_data(data d);
void	out_sizeofside(data d);
void	out_map(data d);

int	ft_min(int a, int b);
int	*ft_int_calloc(int en);
char	*ft_char_calloc(int en, char c);
int	ft_strlen(char *s);
int	ft_power(int b, int e);
int	ft_atoi(char *s);
