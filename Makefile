# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 04:39:44 by tclaereb          #+#    #+#              #
#    Updated: 2024/02/09 13:55:50 by tclaereb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = checker
NAME_P = push_swap


_SRCS_C = main.c

_SRCS_P = push_swap.c \
			main.c

SRCS_C_DIR = check
SRCS_P_DIR = push
SRCS_C = $(addprefix $(SRCS_C_DIR)/, $(_SRCS_C))
SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCO_C = $(SRCS_C:.c=.o)
SRCO_P = $(SRCS_P:.c=.o)

MAKE_LIBFT = $(MAKE) -C ./libft
LIBFT = ./libft/libft.a

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME_C) $(NAME_P)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME_C) : $(SRCO_C) | $(LIBFT)
	gcc -o $(NAME_C) $(SRCO_C) $(LIBFT)

$(NAME_P) : $(SRCO_P) | $(LIBFT)
	gcc -o $(NAME_P) $(SRCO_P) $(LIBFT)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_C)
	/bin/rm -f $(SRCO_P)
	$(MAKE_LIBFT) clean

fclean : clean
	/bin/rm -f $(NAME_C)
	/bin/rm -f $(NAME_P)
	$(MAKE_LIBFT) fclean

re :
	$(MAKE_LIBFT) fclean
	make fclean
	make
