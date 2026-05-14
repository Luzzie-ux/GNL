NAME=GNL.a
CC=cc
CFLAGS= -Wall -Wextra -Werror -D BUFFER_SIZE=42
SRCS= $(wildcard *.c)
OBJS= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all 
