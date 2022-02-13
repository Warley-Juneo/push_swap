# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:50:56 by wjuneo-f          #+#    #+#              #
#    Updated: 2022/02/13 16:11:58 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE			= normalize.c operations.c operations1.c operations2.c frees.c
SOURCE			+= push_swap.c utils_libft.c utils_lstlinked.c check_arguments.c
SOURCE			+= raddix.c init_end.c

OBJECTS			= $(SOURCE:.c=.o)

HEADER			= push_swap.h
NAME			= push_swap

CC				= clang
RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror -g3

NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

all:		$(NAME)

$(NAME):	$(OBJECTS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJECTS) -lm -o $(NAME)
			echo "$(BLUE)Project successfully compiled"

clean:
			echo "$(VIOLET)Supressing libraries files$(CYAN)"
			$(RM) $(OBJECTS)

fclean:		clean
			echo "$(VIOLET)Supressing libraries files$(CYAN)"
			$(RM) $(NAME)

re: 		clean fclean all

n:
			norminette *c

.PHONY:		all clean fclean re
