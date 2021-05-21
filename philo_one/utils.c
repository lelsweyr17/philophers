#include "philo_one.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr(char *s)
{
    write(1, s, ft_strlen(s));
}

void    ft_putnbr(long nb)
{
    if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}