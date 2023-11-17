NAME = libft.a

SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

# SRCS_BONUS = ft_lstnew.c \
# 	ft_lstadd_front.c \
# 	ft_lstsize.c

OBJS = $(SRCS:.c=.o)
# OBJS_BONUS = $(SRCS_BONUS:%.c=%_bonus.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM	= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# bonus: $(OBJS_BONUS) $(OBJS)
# 	$(AR) $(NAME) $(OBJS_BONUS) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

#$(OBJS_BONUS)
clean:
	$(RM) $(OBJS) 

fclean: clean
	$(RM) $(NAME)

re: clean $(NAME)

.PHONY: all clean fclean re
