#include "philo_one.h"

void	*life_cycle(void *one1)
{
	t_one	*one;

	one = one1;
	one->last_meal = 0;
	while (1)
	{
		eating(one);
		if (one->nbr_of_eats == one->philo->nbr_of_eats)
			break ;
		sleeping(one);
		thinking(one);
	}
	return (NULL);
}

int	create_threads(t_all *all)
{
	int	i;

	i = 0;
	all->i = 0;
	while (i < all->philo->nbr_of_philos)
	{
		all->one[i].i = i;
		if (pthread_create(&all->t[i], NULL, life_cycle, &all->one[i]) != 0)
			return (1);
		pthread_detach(all->t[i]);
		i++;
	}
	if (pthread_create(&all->monitor->spy, NULL, philo_spy, all) != 0)
		return (1);
	pthread_join(all->monitor->spy, NULL);
	return (0);
}
