# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclaereb <tclaereb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/25 04:39:44 by tclaereb          #+#    #+#              #
#    Updated: 2024/03/21 09:17:15 by tclaereb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_P = push_swap

_SRCS_P = exception.c \
			main.c \
			stack_sorting.c \
			index_setter.c \
			short_stack.c

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

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME_C) $(NAME_P)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME_P) : $(SRCO_P) $(SRCO_I) | $(LIBFT)
	gcc -o $(NAME_P) $(SRCO_P) $(SRCO_I) $(LIBFT)

%.o : %.c
	gcc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO_P)
	/bin/rm -f $(SRCO_I)
	$(MAKE_LIBFT) clean

fclean : clean
	/bin/rm -f $(NAME_P)
	$(MAKE_LIBFT) fclean

re :
	$(MAKE_LIBFT) fclean
	make fclean
	make
