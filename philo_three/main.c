#include "philo_three.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	if (!get_memory_for_struct(&all))
		return (0);
	if (!validation(argc, argv))
	{
		free(all->philo);
		return (0);
	}
	init_params(all->philo, argv);
	if (!get_heap_memory(&all) || !get_start_time(&all))
		return (0);
	semaphore_init(all);
	init_struct_each_philo(all);
	create_threads(all);
    // sem_close(all->fork);
    // sem_close(all->monitor->write);
    // sem_close(all->index);
	free_all(all);
	return (0);
}