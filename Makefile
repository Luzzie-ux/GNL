NAME=GNL.a
CC=cc
CFLAGS= -Wall -Wextra -Werror -g -D BUFFER_SIZE=42
SRCS= get_next_line.c get_next_line_utils.c \
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
