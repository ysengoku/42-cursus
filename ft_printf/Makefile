# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 16:10:58 by yusengok          #+#    #+#              #
#    Updated: 2023/11/24 11:09:10 by yusengok         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INCLUDES = includes/
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES)
HEADER = ft_print.h
AR = ar rcs
RM	= rm -f

SRCS_FILES_PRINTF = ft_printf \
					ft_print_char \
					ft_print_str \
					ft_print_ptr \
					ft_print_nbr \
					ft_print_unit \
					ft_print_hex
		
SRCS_FILES_LIBFT = ft_atoi \
					ft_strlen \
					
LIBFT_DIR = Libft/

SRCS_PRINTF = $(addsuffix .c, $(SRCS_FILES_PRINTF))
SRCS_LIBFT = $(addprefix $(LIBFT_DIR), $(addsuffix .c, $(SRCS_FILES_PRINTF)))

SRCS = $(SRCS_PRINTF)
SRCS += $(SRCS_LIBFT)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re



#General

NAME            =    printf.a
INCLUDES        =    include
LIBFT_SRC_DIR    =    src/libft/
PRINTF_SRC_DIR    =    src/printf/
OBJ_DIR            =    obj/

CC            =    gcc
CFLAGS        =    -Wall -Wextra -Werror -I$(INCLUDES)

RM            =    rm
AR            =    ar rcs


#Sources

LIBFT_SRC_FILES        =    ft_printf    ft_printf_char    ft_printf_ptr    ft_printf_nbr    ft_printf_hex
PRINTF_SRC_FILES    =    ft_itoa        ft_putchar_fd
SRC_FILES    =    $(LIBFT_SRC)
SRC_FILES    +=    $(PRINTF_SRC)

LIBFT_SRC    =    $(addprefix $(LIBFT_SRC_DIR), $(addsuffix .c, $(LIBFT_SRC_FILES)))
PRINTF_SRC    =    $(addprefix $(PRINTF_SRC_DIR), $(addsuffix .c, $(PRINTF_SRC_FILES)))
LIBFT_OBJ    =    $(addprefix $(OBJ_DIR), $(addsuffix .o, $(LIBFT_SRC_FILES)))
PRINTF_OBJ    =    $(addprefix $(OBJ_DIR), $(addsuffix .o, $(PRINTF_SRC_FILES)))


#Commands

OBJF        =    .cache_exists

all:        $(NAME)

$(NAME):    $(LIBFT_OBJ) $(PRINTF_OBJ)
                $(AR) $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ)

$(OBJ_DIR)%.o: $(LIBFT_SRC_DIR)%.c | $(OBJF)
                $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)%.o: $(PRINTF_SRC_DIR)%.c | $(OBJF)
                $(CC) $(CFLAGS) -c $< -o $@

$(OBJF):
                @mkdir -p $(OBJ_DIR)

clean:
                $(RM) -rf $(OBJ_DIR)

fclean:        clean
                $(RM) -f $(NAME)

re:            fclean all

.PHONY:        all clean fclean re
