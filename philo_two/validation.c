#include "philo_two.h"

int	arg_is_positive_number(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			i++;
		else
		{
			write(1, "Error: argument is invalid\n", 27);
			return (0);
		}
	}
	return (1);
}

int	validation(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		write(1, "Error: incorrect number of arguments\n", 37);
		return (0);
	}
	while (i < argc)
	{
		if (!arg_is_positive_number(argv[i++]))
			return (0);
	}
	return (1);
}
