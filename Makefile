# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: JFikents <Jfikents@student.42Heilbronn.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 23:23:18 by apeposhi          #+#    #+#              #
#    Updated: 2024/08/20 21:03:44 by JFikents         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AUTHORS         :=  apeposhi && JFikents
NAME            :=  cub3d

# Metadata
AUTHOR			:=	apeposhi\
					JFikents
NAME			:=	cub3d

ifeq ($(DEBUG), 1)
re: fclean all
endif

all: $(NAME)

# Sources & Objects
_DEPENDENCIES	:=	cub3d.h exec.h
DEPENDENCIES	:=	$(addprefix include/, $(_DEPENDENCIES))

_EXEC_SRC		:=	cast_rays.c\
					draw_fov.c\
					draw_utils.c\
					exec.c\
					horizontal_rays.c\
					keyhook.c\
					math.c\
					minimap_player_floor_and_ceiling.c\
					movement.c\
					vertical_rays.c
EXEC_SRC		:=	$(addprefix execution/, $(_EXEC_SRC))

_PARSER_SRC		:=	parsing.c\
					checker_utils.c\
					f_c_handler.c\
					map_handler.c\
					map_utils.c\
					texture_handler.c\
					raw_data_handler.c\
					utils.c\
					validate_map_layout.c
PARSER_SRC		:=	$(addprefix parser/, $(_PARSER_SRC))

_SRC			:=	main.c\
					$(PARSER_SRC)\
					$(CLEANUP_SRC)\
					$(EXEC_SRC)
SRC				:=	$(addprefix src/, $(_SRC))

OBJS			:=	$(SRC:src/%.c=bin/%.o)

# Compiler and Flags
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror -Wunreachable-code
ifeq ($(DEBUG), 1)
CFLAGS	+= -g3
endif

_INCLUDES		:=	include/ libft/includes/ lib/MLX42/include/MLX42/
INCLUDES		:=	$(addprefix -I, $(_INCLUDES))

# Libraries
_LIB_PATH		:=	lib/MLX42/build/ lib/libft/ libft/
LIB_PATH		:=	$(addprefix -L, $(_LIB_PATH))
LIBMLX42		:=	lib/MLX42/build/libmlx42.a
LIBFT			:=	libft/libft_local.a lib/libft/libft.a
_LIBS			:=	mlx42 ft glfw m ft_local
LIBS			:=	$(addprefix -l, $(_LIBS))
LIB_FLAGS		:=	$(LIB_PATH) $(LIBS)

$(LIBMLX42):
	@git submodule update --init --recursive lib/MLX42
	@cmake -B lib/MLX42/build -S lib/MLX42/
	@cmake --build lib/MLX42/build -j4

$(LIBFT):
	@git submodule update --init --recursive lib/libft
	@make -C libft
	@make -C lib/libft

# Targets

$(NAME): $(LIBFT) $(LIBMLX42) $(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAGS) $(INCLUDES) $(LIB_FLAGS)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

bin/:
	@mkdir -p bin/parser bin/execution

# Suffix Rules
bin/%.o: src/%.c $(DEPENDENCIES) | bin/
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

# Phony Targets
.PHONY: all clean fclean re
