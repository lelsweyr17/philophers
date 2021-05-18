#include "philo_two.h"

void	write_function(t_one *one, char *message)
{
	get_time_of_action(one);
	sem_wait(one->write);
	printf(WHITE BOLD_FONT "%ld\t" RESET_BOLD RESET, one->time);
	printf(CYAN "philo " BOLD_FONT "№%d\t" RESET_BOLD RESET, one->i + 1);
	printf("%s", message);
	sem_post(one->write);
}

void	eating(t_one *one)
{
	take_a_fork(one);
	one->nbr_of_eats++;
	one->eating = 1;
	write_function(one, GREEN EAT RESET);
	my_usleep(one->philo->time_to_eat * 1000);
	one->eating = 0;
	put_a_fork(one);
}

void	sleeping(t_one *one)
{
	write_function(one, BLUE SLEEP RESET);
	my_usleep(one->philo->time_to_sleep * 1000);
}

void	thinking(t_one *one)
{
	write_function(one, MAGENTA THINK RESET);
}
