CC = gcc
CFLAGS = -pthread
SOURCES = main.c \
	ft_atoi.c \
	ft_strlen.c \
	initialisation.c \
	life_cycle.c \
	memory.c \
	monitor.c \
	threads.c \
	processes.c \
	time.c \
	validation.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = philo_three.h
NAME = philo_three

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

