#include "square.h"

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	*ft_int_calloc(int en)
{
	int	*p;
	int	i;

	p = malloc(sizeof(int) * en);
	if (!p)
		return (NULL);
	i = -1;
	while (++i < en)
		p[i] = 0;
	return (p);
}
char	*ft_char_calloc(int en, char c)
{
	char	*p;
	int	i;

	p = malloc(sizeof(char) * en);
	if (!p)
		return (NULL);
	i = -1;
	while (++i < en)
		p[i] = c;
	return (p);
}

int	ft_strlen(char *s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0');
	return (i);
}

int	ft_power(int b, int e)
{
	if (b < 0 || e < 0)//error
		return (0);
	else if(e == 0)
		return (1);
	else
		return (b * ft_power(b, e - 1));
}
int	ft_atoi(char *s)
{
	int	sum;
	int	len;
	int	exp;
	int	lim;
	int	posi;

	sum = 0;
	len = ft_strlen(s);
	exp = 0;
	lim = 0;
	posi = 1;
	if (s[0] == '-')
	{
		lim++;
		posi = -1;
	}
	while (lim < len)
	{
		sum+= ft_power(10, exp) * (s[len - 1] - '0');
		--len;
		++exp;
	}
	return (sum * posi);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putnum(int n)
{
	long int	ln;

	ln = (long int)n;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar('-');
	}
	if (ln < 10)
		ft_putchar(ln + '0');
	else
	{
		ft_putnum(ln / 10);
		ft_putnum(ln % 10);
	}
}
