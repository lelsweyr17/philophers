#include "philo_three.h"

void	waitpid_processes(pid_t *pid, t_all *all)
{
	int		status;
	int		i;

	i = 0;
	waitpid(0, &status, WUNTRACED);
	if ((status >> 8) == STATUS_DEAD)
	{
		while (i < all->philo->nbr_of_philos)
			kill(pid[i++], 1);
	}
	else if (!status)
	{
		all->i++;
		if (all->i == all->philo->nbr_of_philos)
			printf(BOLD_FONT RED "PHILOS ARE FULL\n" RESET RESET_BOLD);
		else
			waitpid_processes(pid, all);
	}
}

void	create_processes(t_all *all)
{
	pid_t	*pid;

	all->i = 0;
	pid = (pid_t *)malloc(all->philo->nbr_of_philos * sizeof(pid_t));
	while (all->i < all->philo->nbr_of_philos)
	{
		pid[all->i] = fork();
		if (pid[all->i] == 0)
			create_threads(all);
		all->i++;
	}
	all->i = 0;
	waitpid_processes(pid, all);
	free(pid);
}
