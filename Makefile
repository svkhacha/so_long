# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/11 15:40:41 by svkhacha          #+#    #+#              #
#    Updated: 2022/08/12 19:39:56 by svkhacha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	So_long
NAME_BONUS	=	So_long_bonus
SRCS		=	$(wildcard ./srcs_for_game/*.c)
OBJS		=	$(patsubst ./srcs_for_game/%.c, ./srcs_for_game/%.o, $(SRCS))
SRCS_BONUS	=	$(wildcard ./bonus/*.c)
OBJS_BONUS	=	$(patsubst ./bonus/%.c, ./bonus/%.o, $(SRCS_BONUS))
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDE		=	-I./header_files
LINKER		=	-L./libft -lft
RM			=	rm -f

%.o : %.c
	@$(CC) $(CFLAGS) $(INCLUDE) -Imlx -c $< -o $@

all : $(NAME) $(NAME_BONUS)

LIB :
	@$(MAKE) -C ./libft

$(NAME) : LIB $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKER) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)$(NAME) created !$(END)"

$(NAME_BONUS) : LIB $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(INCLUDE) $(LINKER) $(OBJS_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)
	@echo "$(BLUE)$(NAME_BONUS) created !$(END)"

clean :
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJS) $(OBJS_BONUS)
	@echo "$(YELLOW)Object files deleted !$(END)"

fclean : clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(RED)All deleted !$(END)"

re : fclean all

.PHONY : all clean fclean re

#Makefile_Colors
GREEN = \033[1;32m
BLUE = \033[0;34m
YELLOW = \033[1;33m
RED=\033[0;31m
END = \033[0m
