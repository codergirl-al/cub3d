# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 23:23:18 by apeposhi          #+#    #+#              #
#    Updated: 2024/08/08 14:16:57 by apeposhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHORS         :=  apeposhi && JFikents
NAME            :=  cub3d

all: $(NAME)

# Sources & Objects
_CLEANUP_SRC    :=  cleanup.c
CLEANUP_SRC     :=  $(addprefix cleanup/, $(_CLEANUP_SRC))

_PARSER_SRC     :=  parsing.c checker_utils.c f_c_handler.c map_handler.c texture_handler.c raw_data_handler.c
PARSER_SRC      :=  $(addprefix parser/, $(_PARSER_SRC))

_VALIDATOR_SRC  :=  map.c
VALIDATOR_SRC   :=  $(addprefix validator/, $(_VALIDATOR_SRC))

_SRC            :=  main.c error_handling.c \
                    $(VALIDATOR_SRC) \
                    $(PARSER_SRC) \
                    $(CLEANUP_SRC)
SRC             :=  $(addprefix src/, $(_SRC))

OBJS            :=  $(SRC:src/%.c=bin/%.o)

# Compiler and Flags
CC              :=  cc
CFLAGS          :=  -Wall -Wextra -Werror -g3

INCLUDES        :=  -Iinclude -Ilibft/includes

# Libraries
LIBS            :=  -Llibft -lft

# Targets

$(NAME): $(OBJS) libft/libft.a
	$(CC) -o $@ $(OBJS) $(CFLAGS)  $(INCLUDES) $(LIBS)

libft/libft.a: 
	$(MAKE) -C libft

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

bin/:
	@mkdir -p bin/cleanup bin/parser bin/validator

# Suffix Rules
bin/%.o: src/%.c | bin/
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Phony Targets
.PHONY: all clean fclean re
