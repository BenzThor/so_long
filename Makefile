# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenz <tbenz@student.42vienna.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:17:18 by tbenz             #+#    #+#              #
#    Updated: 2023/11/03 15:26:25 by tbenz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= so_long
NAME_BONUS		= so_long_bonus

GREEN			= \033[0;32m
RED				= \033[0;31m
RESET			= \033[0m

LIBFT 			= ./libraries/libft/libft.a

CC 				= cc

STANDARD_FLAGS 	= -Wall -Werror -Wextra -g
MINILIBX_FLAGS	= -lmlx -lXext -lX11

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes

REMOVE 			= rm -f

SRCS_DIR		= ./sources/
BONUS_SRCS_DIR	= ./bonus_sources/

SRCS 			= $(addprefix $(SRCS_DIR),\
				so_long.c			\
				ft_create_map.c		\
				ft_init.c	\
				ft_map_checker.c	\
				ft_map_to_screen.c	\
				ft_key_hook.c		\
				ft_shortest_path.c \
				bfs_helpers.c \
				ft_close.c \
				utils.c \
				utils2.c)

SRCS_BONUS 		= $(addprefix $(BONUS_SRCS_DIR),\
				so_long_bonus.c			\
				ft_create_map.c		\
				ft_init.c	\
				ft_map_checker.c	\
				ft_map_to_screen.c	\
				ft_key_hook.c		\
				ft_shortest_path.c \
				bfs_helpers.c \
				ft_animation.c \
				ft_close.c \
				utils.c \
				utils2.c)

all:			${LIBFT} ${NAME}

${NAME}:
				${CC} ${SRCS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME}
				@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"
				@echo

bonus:			${LIBFT} ${NAME_BONUS}

${NAME_BONUS}:
				${CC} ${SRCS_BONUS} ${LIBFT} ${STANDARD_FLAGS} ${MINILIBX_FLAGS} -o ${NAME_BONUS}
				@echo "\n$(NAME): $(GREEN)$(NAME) was compiled with Bonus.$(RESET)"
				@echo

${LIBFT}:
				@echo
				make all -C libraries/libft

clean:
				make clean -C libraries/libft
				@echo

fclean:
				${REMOVE} ${NAME} ${NAME_BONUS}
				make fclean -C libraries/libft
				@echo "${NAME}: ${RED}${NAME}, ${NAME_BONUS} and libft.a were deleted${RESET}"
				@echo

re:				fclean all

rebonus:		fclean ${NAME_BONUS}

run:			${NAME}
					${VALGRIND} ./${NAME} ./map/map1.ber

run_bonus:		${NAME_BONUS}
					${VALGRIND} ./${NAME_BONUS} ./map/map2.ber

.PHONY:			all clean fclean re rebonus run run_bonus
