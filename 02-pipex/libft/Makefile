# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/17 13:12:10 by yusengok          #+#    #+#              #
#    Updated: 2024/01/18 10:20:09 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDE = includes
HEADER = includes/libft.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)
AR = ar rcs
RM	= rm -f

FILES = ft_atoi	\
		ft_bzero	\
		ft_calloc	\
		ft_isalnum	\
		ft_isalpha	\
		ft_isascii	\
		ft_isdigit	\
		ft_isprint	\
		ft_memchr	\
		ft_memcmp	\
		ft_memcpy	\
		ft_memmove	\
		ft_memset	\
		ft_strchr	\
		ft_strdup	\
		ft_strlcat	\
		ft_strlcpy	\
		ft_strlen	\
		ft_strncmp	\
		ft_strnstr	\
		ft_strrchr	\
		ft_tolower	\
		ft_toupper	\
		ft_substr	\
		ft_strjoin	\
		ft_strtrim	\
		ft_split	\
		ft_itoa	\
		ft_strmapi	\
		ft_striteri	\
		ft_putchar_fd	\
		ft_putstr_fd	\
		ft_putendl_fd	\
		ft_putnbr_fd	\
		ft_lstnew	\
		ft_lstadd_front	\
		ft_lstsize	\
		ft_lstlast	\
		ft_lstadd_back	\
		ft_lstdelone	\
		ft_lstclear	\
		ft_lstiter	\
		ft_lstmap	\
		ft_strcpy	\
		ft_strcat	\
		ft_strcmp	\
		ft_strstr	\
		ft_printf	\
		ft_printf_char	\
		ft_printf_str	\
		ft_printf_ptr	\
		ft_printf_nbr	\
		ft_printf_uint	\
		ft_printf_hex	\
		get_next_line	\

SRCS_DIR = srcs/
OBJS_DIR = .objs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

all:
	@$(MAKE) $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(HEADER)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP

-include $(OBJS:.o=.d)

clean:
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
