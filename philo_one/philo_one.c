#include "philo_one.h"

void	*func(void *one)
{
	t_one *one1;

	one1 = one;
	pthread_mutex_lock(one1->fork_minor);
	pthread_mutex_lock(one1->fork_major);
	printf("%d\t",one1->time);
	printf("%d\t", one1->i);
	printf("%s", FORK);
	pthread_mutex_unlock(one1->fork_major);
	pthread_mutex_unlock(one1->fork_minor);
	return (NULL);
}

int	life_cycle(t_all *all)
{
	int	status;
	int i;

	i = 0;
	while (i < all->philo->number_of_philosophers)
	{
		all->one[i].i = i;
		gettimeofday(&all->time->tv2, NULL);
		all->time->finish_time = all->time->tv2.tv_sec * 1000 + all->time->tv2.tv_usec / 1000;
		all->one[i].time = all->time->finish_time - all->time->start_time;
		status = pthread_create(&all->t[i], NULL, func, &all->one[i]);
		if (status != 0)
			return (1);
		pthread_join(all->t[i], NULL);
		pthread_detach(all->t[i]);
		i++;
	}
	return (0);
}

void	philo_one_threads(t_all *all)
{
	int i;
	int j;

	i = -1;
	j = 0;
	all->time = (t_time *)malloc(sizeof(t_time));
	all->fork = (pthread_mutex_t *)malloc(all->philo->number_of_philosophers * sizeof(pthread_mutex_t));
	all->one = (t_one *)malloc(all->philo->number_of_philosophers * sizeof(t_one));
	if(!all->time || !all->fork || !all->one || !all->t)
		return ;
	all->t = (pthread_t *)malloc(all->philo->number_of_philosophers * sizeof(pthread_t));
	gettimeofday(&all->time->tv1, NULL);
	all->time->start_time = all->time->tv1.tv_sec * 1000 + all->time->tv1.tv_usec / 1000;
	while (++i < all->philo->number_of_philosophers)
		pthread_mutex_init(&all->fork[i], NULL);
	i = -1;
	init_struct_each_philo(all);
	if (all->philo->number_of_times_each_philosopher_must_eat == -1)
	{
		while (j != 1)
		{
			j = life_cycle(all);
			// gettimeofday(&all->time->tv2, NULL);
			// all->time->finish_time = all->time->tv2.tv_sec * 1000 + all->time->tv2.tv_usec / 1000;
			// all->one->time = all->time->finish_time - all->time->start_time;
		}
	}
	else
	{
		while (++i < all->philo->number_of_times_each_philosopher_must_eat)
		{
			if (life_cycle(all) == -1)
				break ;
			// gettimeofday(&all->time->tv2, NULL);
			// all->time->finish_time = all->time->tv2.tv_sec * 1000 + all->time->tv2.tv_usec / 1000;
			// all->one->time = all->time->finish_time - all->time->start_time;
		}
		// exit(0);
		// exit from program
	}
}

int	main(int argc, char **argv)
{
	t_all			*all;
	struct timeval	tv1;
	struct timeval	tv2;

	all = (t_all *)malloc(sizeof(t_all));
	all->philo = (t_philo *)malloc(sizeof(t_philo));
	if (!all || !all->philo)
		return (0);
	if (!validation(argc, argv))
	{
		free(all->philo);
		return (0);
	}
	init_params(all->philo, argv);
	// printf("%d\n", philo->number_of_philosophers);
	// printf("%d\n", philo->time_to_die);
	// printf("%d\n", philo->time_to_eat);
	// printf("%d\n", philo->time_to_sleep);
	// printf("%d\n", philo->number_of_times_each_philosopher_must_eat);
	philo_one_threads(all);
	// while (1);
	printf("exit\n");
	return (0);
}
