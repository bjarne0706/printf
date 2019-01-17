# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchantse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/04 18:00:24 by dchantse          #+#    #+#              #
#    Updated: 2019/01/04 18:00:27 by dchantse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@clang -I libft/ -o main.o -c main.c -g
	@clang -I libft/ -o ft_itoa_base.o -c ft_itoa_base.c -g
	@clang -I libft/ -o ft_printf.o -c ft_printf.c -g
	@clang -I libft/ -o help_func.o -c help_func.c -g
	@clang -I libft/ -o flags.o -c flags.c -g
	@clang -I libft/ -o int.o -c int.c -g
	@clang -o ft_printf main.o int.o ft_itoa_base.o ft_printf.o flags.o help_func.o -I libft/ -L libft/ -lft -g
clean:
	@rm -rf *.o
	@make -C libft/ clean
fclean: clean
	@rm -rf ft_printf
	@make -C libft/ fclean
re: fclean all
