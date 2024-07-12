# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 23:23:18 by apeposhi          #+#    #+#              #
#    Updated: 2024/07/12 19:00:20 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Metadata
AUTHOR			:=	apeposhi\
					JFikents
NAME			:=	cub3d

all: $(NAME)

# Sources & Objects
_CLEANUP_SRC	:=	cleanup.c
CLEANUP_SRC		:=	$(addprefix cleanup/, $(_CLEANUP_SRC))

_PARSER_SRC		:=	parsing.c
PARSER_SRC		:=	$(addprefix parser/, $(_PARSER_SRC))

_VALIDATOR_SRC	:=	arguments.c
VALIDATOR_SRC	:=	$(addprefix validator/, $(_VALIDATOR_SRC))

_SRC			:=	main.c parser.c \
					$(VALIDATOR_SRC)\
					$(PARSER_SRC)\
					$(CLEANUP_SRC)
SRC				:=	$(addprefix src/, $(_SRC))

OBJS			:=	$(SRC:src/%.c=bin/%.o)

# Compiler and Flags
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror

_INCLUDES		:=	include/ libft/includes/ lib/MLX42/include/MLX42/
INCLUDES		:=	$(addprefix -I, $(_INCLUDES))

# Libraries
LIBMLX42		:=	lib/MLX42/build/libmlx42.a
LIBFT			:=	libft/libft.a
_LIBS			:=	$(LIBFT) $(LIBMLX42)
LIBS			:=	$(addprefix -l, $(_LIBS))

$(LIBMLX42):
	@git submodule update --init --recursive lib/MLX42
	@cmake -B lib/MLX42/build -S lib/MLX42/
	@cmake --build lib/MLX42/build -j4

# Targets

$(NAME): $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(INCLUDES) $(LIBS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

bin/:
	@mkdir -p bin/cleanup bin/parser bin/validator

# Suffix Rules
bin/%.o: src/%.c | bin/
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Phony Targets
.PHONY:	all clean fclean re
