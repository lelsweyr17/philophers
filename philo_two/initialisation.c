#include "philo_two.h"

void	semaphore_init(t_all *all)
{
	sem_unlink("forks");
	all->fork = sem_open("forks", O_CREAT, 0666, all->philo->nbr_of_philos);
	sem_unlink("take_2_forks");
	all->take_forks = sem_open("take_2_forks", O_CREAT, 0666, 1);
	sem_unlink("write");
	all->monitor->write = sem_open("write", O_CREAT, 0666, 1);
	sem_unlink("index");
	all->index = sem_open("index", O_CREAT, 0666, 1);
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
		all->one[i].fork = all->fork;
		all->one[i].take_forks = all->take_forks;
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
