# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchantse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 12:38:10 by dchantse          #+#    #+#              #
#    Updated: 2019/01/26 18:56:43 by anerus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -O2

LIBFT = libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES = ft_printf.c \
		  int.c \
		  flags.c \
		  perc.c \
		  work_param.c \
		  ft_itoa_base.c \
		  main2.c \
		  xX.c\
		  o.c\
		  u.c\
		  s.c

SRCS = $(SOURCES)

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@gcc main2.c libftprintf.a -o ft_printf
	@echo ---------------------------
	@./ft_printf

%.o: %.c
	@mkdir -p temporary
	@$(CC) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -rf *.o
	@make -C libft/ clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf ft_printf
	@make -C libft/ fclean

re: fclean all
