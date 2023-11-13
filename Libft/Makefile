TARGET = libft.a
SRCS = 
OBJS = $(addprefix $(SRCS:.c=.o))
INCLUDES = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(TARGET): $(OBJS)
	ar rc $(TARGET) $(OBJS)

all: $(TARGET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
