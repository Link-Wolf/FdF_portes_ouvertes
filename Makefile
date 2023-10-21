# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:33:35 by xxxxxxx           #+#    #+#              #
#    Updated: 2022/03/16 16:15:29 by xxxxxxx          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= fdf

INCLUDE			= ./includes/
LIBFT			= ./libft/
SRC_DIR			= ./src/

SRC_FILES		= fdf.c  fdf_utils.c draw_tab.c mult.c tab_vector_size.c hook.c

SRCS			= $(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS			= $(SRCS:.c=.o)

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) -Llibft -lft $(OBJS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
