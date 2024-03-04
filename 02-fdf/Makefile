# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/12 15:05:35 by yusengok          #+#    #+#              #
#    Updated: 2024/03/01 08:42:47 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BOLD = \033[1m
RESET = \033[0m
LIGHT_GREEN = \033[32m
MAGENTA = \033[95m

NAME = fdf
HEADER = fdf.h

FILES = main	\
		map_check	\
		map_reader	\
		map_coordinates	\
		map_datainit	\
		img_rendering	\
		img_draw	\
		img_projection	\
		handle_events	\
		error_handling	\
		utils_free	\
		utils_map	\
		utils_events

vpath %c srcs
SRCS = $(addsuffix .c, $(FILES))
OBJS_DIR = .objs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))

LIB_DIR = ./lib
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX_DIR = $(LIB_DIR)/minilibx-linux
LIBMLX = $(LIBMLX_DIR)/libmlx.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I .
INCLUDE = -I . -I$(LIBFT_DIR) -I$(LIBMLX_DIR)
MLXFLAGS = -lmlx -lXext -lX11 -lm
RM = rm -f

all: lib
	@$(MAKE) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	@printf "$(MAGENTA)$(BOLD)Building FdF...\n$(RESET)"
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@ -L $(LIBFT_DIR) -L $(LIBMLX_DIR)
	@printf "$(LIGHT_GREEN)$(BOLD)FdF is ready to launch\n$(RESET)"

$(OBJS_DIR)%.o: %.c $(HEADER) $(LIBFT)
	@mkdir -p $(OBJS_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

lib: $(FORCE)
	@printf "$(MAGENTA)$(BOLD)Compiling Libft...\n$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@printf "$(MAGENTA)$(BOLD)Compiling Minilibx...\n$(RESET)"
	@$(MAKE) -s -C $(LIBMLX_DIR)

clean:
	@printf "$(MAGENTA)$(BOLD)Cleaning Libft...\n$(RESET)"
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@printf "$(MAGENTA)$(BOLD)Cleaning Minilibx...\n$(RESET)"
	@$(MAKE) -s -C $(LIBMLX_DIR) clean
	@printf "$(MAGENTA)$(BOLD)Cleaning FdF...\n$(RESET)"
	@$(RM) -r $(OBJS_DIR)

fclean: clean
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE) all

FORCE:

.PHONY: all clean fclean re lib
