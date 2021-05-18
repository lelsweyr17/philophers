#include "philo_one.h"

void	mutex_init(t_all *all)
{
	int	i;

	i = -1;
	while (++i < all->philo->nbr_of_philos)
		pthread_mutex_init(&all->fork[i], NULL);
	pthread_mutex_init(all->monitor->write, NULL);
	pthread_mutex_init(&all->index, NULL);
}

void	init_struct_each_philo(t_all *all)
{
	int	i;

	i = -1;
	all->monitor->dead = 0;
	all->monitor->full_philo = 0;
	while (++i < all->philo->nbr_of_philos)
	{
		all->one[i].i = i;
		if (i < (all->philo->nbr_of_philos - 1))
		{
			all->one[i].fork_right = &all->fork[i];
			all->one[i].fork_left = &all->fork[i + 1];
		}
		else
		{
			all->one[i].fork_right = &all->fork[all->philo->nbr_of_philos - 1];
			all->one[i].fork_left = &all->fork[0];
		}
		all->one[i].t = &all->t[i];
		all->one[i].get_time = all->time;
		all->one[i].philo = all->philo;
		all->one[i].write = all->monitor->write;
		all->one[i].nbr_of_eats = 0;
		all->one[i].eating = 0;
	}
}

void	init_params(t_philo *philo, char **argv)
{
	philo->nbr_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->nbr_of_eats = ft_atoi(argv[5]);
	else
		philo->nbr_of_eats = -1;
}
