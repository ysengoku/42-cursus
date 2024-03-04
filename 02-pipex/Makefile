# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 08:04:13 by yusengok          #+#    #+#              #
#    Updated: 2024/02/12 13:36:49 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
INCLUDE = includes
HEADER = $(INCLUDE)/pipex.h
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDE)
RM = rm -f

FILES =	pipex	\
		parse_argv	\
		error_handling	\
		utils_execute	\
		utils_parsing	\
		utils_pipe	\
		utils_split	

vpath %c srcs

SRCS = $(addsuffix .c, $(FILES))
OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
LIBFT = libft/libft.a

all: lib
	@$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJS_DIR)%.o: %.c $(HEADER) $(LIBFT)
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -MMD -MP

-include $(OBJS:.o=.d)

lib:
	@$(MAKE) -C ./libft

clean:
	$(MAKE) -C ./libft clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C ./libft fclean
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re lib
