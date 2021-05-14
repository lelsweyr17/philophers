#include "philo_one.h"

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
	mutex_init(all);
	init_struct_each_philo(all);
	threads(all);
	free_all(all);
	return (0);
}
