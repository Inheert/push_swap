# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 04:39:44 by tclaereb          #+#    #+#              #
#    Updated: 2024/07/05 16:17:59 by tclaereb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

_SRCS_P = exception.c \
			main.c \
			stack_sorting.c \
			index_setter.c \
			short_stack.c \
			sorting.c \

_SRCS_I = sa_sb_ss.c \
			pa_pb.c \
			ra_rb_rr.c \
			rra_rrb_rrr.c

SRCS_P_DIR = push
SRCS_I_DIR = $(SRCS_P_DIR)/instructions

SRCS_P = $(addprefix $(SRCS_P_DIR)/, $(_SRCS_P))
SRCS_I = $(addprefix $(SRCS_I_DIR)/, $(_SRCS_I))

SRCO_P = $(SRCS_P:.c=.o)
SRCO_I = $(SRCS_I:.c=.o)

MAKE_LIBFT = $(MAKE) -C ./libft
LIBFT = ./libft/libft.a

FLAG = -g -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME) : $(SRCO_P) $(SRCO_I) | $(LIBFT)
	gcc -o $(NAME) $(SRCO_P) $(SRCO_I) $(LIBFT)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	rm -f $(SRCO_P)
	rm -f $(SRCO_I)
	$(MAKE_LIBFT) clean

fclean : clean
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean

re :
	$(MAKE_LIBFT) fclean
	make fclean
	make
