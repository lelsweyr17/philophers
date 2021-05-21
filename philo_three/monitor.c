#include "philo_three.h"

void	my_usleep(long int time_in_usec)
{
	long int		start;
	long int		end;
	struct timeval	t1;
	struct timeval	t2;

	gettimeofday(&t1, NULL);
	start = t1.tv_sec * 1000 + t1.tv_usec / 1000;
	gettimeofday(&t2, NULL);
	end = t2.tv_sec * 1000 + t2.tv_usec / 1000;
	while (end - start < (time_in_usec / 1000))
	{
		usleep(50);
		gettimeofday(&t2, NULL);
		end = t2.tv_sec * 1000 + t2.tv_usec / 1000;
	}
}

void	*philo_died(t_all *tmp, int i)
{
	sem_wait(tmp->monitor->write);
	tmp->monitor->dead = 1;
	ft_putnbr(tmp->monitor->current_time);
	ft_putchar('\t');
	ft_putnbr(tmp->one[i].i + 1);
	ft_putchar('\t');
	ft_putstr(DIED);
	ft_putstr("END OF SIMULATION: ONE PHILO IS DIED\n");
	exit(STATUS_DEAD);
	return (0);
}

void	*philo_spy(void *all)
{
	t_all		*tmp;

	tmp = all;
	while (1)
	{
		gettimeofday(&tmp->time->tv2, NULL);
		tmp->monitor->current_time = tmp->one->get_time->tv2.tv_sec * 1000 \
		+ tmp->one->get_time->tv2.tv_usec / 1000 - tmp->time->start_time;
		if (!tmp->one[tmp->i].eating && (tmp->monitor->current_time - \
		tmp->one[tmp->i].last_meal) > tmp->philo->time_to_die)
			philo_died(tmp, tmp->i);
		my_usleep(1000);
	}
	return (NULL);
}
