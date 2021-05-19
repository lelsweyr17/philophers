CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread
SOURCES = main.c \
	ft_atoi.c \
	ft_strlen.c \
	initialisation.c \
	life_cycle.c \
	forks.c \
	memory.c \
	monitor.c \
	threads.c \
	time.c \
	validation.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = philo_one.h
NAME = philo_one

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

