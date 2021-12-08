#include"ft_printf.h"

ssize_t	ft_strlen(char *str)
{
	ssize_t	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

void	ft_pt(long int pin, char *tab, t_tracker *count)
{
	int	index[9];
	int	i;

	ft_write('0', count);
	ft_write('x', count);
	i = 0;
	while (i < 9)
	{
		index[i] = pin % 16;
		pin = pin / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_write(tab[index[i]], count);
	}
	count->pos++;
}

int	ft_len(size_t n, size_t b)
{
	int	l;

	l = 1;
	while (n >= b)
	{
		l++;
		n = n / b;
	}
	return (l);
}

void	witoa(ssize_t n, char *str, size_t b, t_tracker *count)
{
	int	i;
	int	*tab;

	i = 0;
	if (n < 0)
	{
		n = -n;
		ft_write('-', count);
	}
	tab = malloc(sizeof(int) * ft_len(n, b));
	if (n == 0)
		ft_write (*str, count);
	while (n > 0)
	{
		tab[i] = n % b;
		n = n / b;
		i++;
	}
	while (--i >= 0)
	{
		ft_write(str[tab[i]], count);
	}
	free (tab);
	count->pos++;
}

void	ft_write(char c, t_tracker *count)
{
	write (1, &c, 1);
	count->count++;
}

void	ft_write_string(char *c, t_tracker *count)
{
	int	len;

	len = ft_strlen(c);
	write(1, c, len);
	count->count += len;
	count->pos++;
}
