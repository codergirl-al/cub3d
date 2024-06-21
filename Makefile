# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/14 23:23:18 by apeposhi          #+#    #+#              #
#    Updated: 2024/05/14 23:30:12 by apeposhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Metadata
AUTHOR    :=	apeposhi
NAME      :=	cub3d

# Sources & Objects
SRC       :=	src/main.c src/parser.c \
				src/validator/arguments.c
OBJS      :=	$(SRC:.cpp=.o)

# Compiler and Flags
CXX       :=	cc
CXXFLAGS  :=	-Wall -Wextra -Werror
EXE_FLAG  :=	-o
EXEC      :=	cub3d

# Suffix Rules
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Targets
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(EXE_FLAG) $(EXEC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(EXEC)

re:	fclean all

# Phony Targets
.PHONY:	all clean fclean re
