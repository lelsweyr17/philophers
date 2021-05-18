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
	tmp->one[index].last_meal = 0;
	while (tmp->one[index].nbr_of_eats < tmp->philo->nbr_of_eats || \
	tmp->philo->nbr_of_eats == -1)
	{
		eating(&tmp->one[index]);
		if (tmp->one[index].nbr_of_eats == tmp->philo->nbr_of_eats)
		{
			printf("here\n");
			tmp->monitor->full_philo++;
			break ;
		}
		sleeping(&tmp->one[index]);
		thinking(&tmp->one[index]);
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
		if (pthread_create(&all->t[i], NULL, life_cycle, all) != 0)
			return (1);
		pthread_detach(all->t[all->i]);
		i++;
	}
	if (pthread_create(&all->monitor->spy, NULL, philo_spy, all) != 0)
		return (1);
	pthread_join(all->monitor->spy, NULL);
	return (0);
}
