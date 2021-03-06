#include "philo_two.h"

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
	printf(BOLD_FONT "%ld\t" RESET_BOLD, tmp->monitor->current_time);
	printf(CYAN "philo " BOLD_FONT "№%d\t" RESET_BOLD RESET, tmp->one[i].i + 1);
	printf("%s", RED DIED RESET);
	printf(BOLD_FONT RED "END OF SIMULATION\n" RESET RESET_BOLD);
	return ((void *)1);
}

void	*philo_full(t_all *tmp)
{
	sem_wait(tmp->monitor->write);
	printf(BOLD_FONT RED "PHILOS ARE FULL\n" RESET RESET_BOLD);
	return ((void *)1);
}

void	*philo_spy(void *all)
{
	t_all		*tmp;
	int			i;

	tmp = all;
	while (1)
	{
		i = -1;
		gettimeofday(&tmp->time->tv2, NULL);
		tmp->monitor->current_time = tmp->one->get_time->tv2.tv_sec * 1000 \
		+ tmp->one->get_time->tv2.tv_usec / 1000 - tmp->time->start_time;
		while (++i < tmp->philo->nbr_of_philos)
		{
			if (tmp->philo->nbr_of_eats != -1)
			{
				if (tmp->monitor->full_philo == tmp->philo->nbr_of_philos)
					return (philo_full(all));
			}
			else if (!tmp->one[i].eating && (tmp->monitor->current_time - \
			tmp->one[i].last_meal) > tmp->philo->time_to_die)
				return (philo_died(tmp, i));
		}
		my_usleep(1000);
	}
	return (NULL);
}
