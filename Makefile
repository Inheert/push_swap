# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 04:39:44 by tclaereb          #+#    #+#              #
#    Updated: 2024/07/08 16:21:24 by tclaereb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

_SRCS_P = exception.c \
			main.c \
			utils.c \
			short_stack.c \
			stack_sorting.c \
			stack_sorting2.c \

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
	cc -o $(NAME) $(SRCO_P) $(SRCO_I) $(LIBFT)

%.o : %.c
	cc $(FLAG) -c $< -o $@ $(INC)

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

.PHONY: all clean fclean re
