#include "philo_two.h"

void	write_function(t_one *one, char *message)
{
	get_time_of_action(one);
	sem_wait(one->write);
	ft_putnbr(one->time);
	ft_putchar('\t');
	ft_putnbr(one->i + 1);
	ft_putchar('\t');
	ft_putstr(message);
	sem_post(one->write);
}

void	eating(t_one *one)
{
	take_a_fork(one);
	one->nbr_of_eats++;
	one->eating = 1;
	write_function(one, EAT);
	my_usleep(one->philo->time_to_eat * 1000);
	one->eating = 0;
	put_a_fork(one);
}

void	sleeping(t_one *one)
{
	write_function(one, SLEEP);
	my_usleep(one->philo->time_to_sleep * 1000);
}

void	thinking(t_one *one)
{
	write_function(one, THINK);
}
