#include "philo_one.h"

void	*life_cycle(void *all)
{
	t_all	*tmp;
	int		index;

	tmp = all;
	pthread_mutex_lock(&tmp->index);
	index = tmp->i;
	tmp->i++;
	pthread_mutex_unlock(&tmp->index);	
	tmp->one[index].last_eat = 0;
	while (1)
	{
		eating(&tmp->one[index]);
		sleeping(&tmp->one[index]);
		thinking(&tmp->one[index]);
	}
	return (NULL);
}

void	*philo_spy(void *all)
{
	t_all		*tmp;
	int			i;

	tmp = all;
	while (1)
	{
		i = -1;
		while (++i < tmp->philo->nbr_of_philos)
		{
			tmp->monitor->last_eat[i] = tmp->one[i].last_eat;
			gettimeofday(&tmp->time->tv2, NULL);
			tmp->monitor->current_time = tmp->one->get_time->tv2.tv_sec * 1000 \
			+ tmp->one->get_time->tv2.tv_usec / 1000 - tmp->time->start_time;
			if ((tmp->monitor->current_time - tmp->monitor->last_eat[i]) > \
			tmp->philo->time_to_die && !tmp->one[i].eating)
			{
				write_function(&tmp->one[i], DIED);
				printf("End of simulation\n");
				pthread_mutex_lock(tmp->monitor->write);
				tmp->monitor->dead = 1;
				return (NULL);
			}
		}
	}
	return (NULL);
}

int	create_threads(t_all *all)
{
	int i = 0;
	all->i = 0;
	while (i < all->philo->nbr_of_philos)
	{
		if (pthread_create(&all->t[i], NULL, life_cycle, all) != 0)
			return (1);
		i++;
		pthread_detach(all->t[all->i]);
		if (all->i == all->philo->nbr_of_philos - 1)
		{
			if (pthread_create(&all->monitor->spy, NULL, philo_spy, all) != 0)
				return (1);
			pthread_detach(all->monitor->spy);
		}
	}
	while (1)
	{
		if (all->monitor->dead)
			return (0);
	}
	return (0);
}

void	threads(t_all *all)
{
	int	i;

	i = -1;
	if (all->philo->nbr_of_eats == -1)
	{
		create_threads(all);
		return ;
	}
	// else
	// {
	// 	while (++i < all->philo->nbr_of_eats)
	// 	{
	// 		if (life_cycle(all) == -1)
	// 			break ;
	// 	}
	// 	// exit(0);
	// 	// exit from program
	// }
}
