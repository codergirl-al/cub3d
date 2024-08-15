# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeposhi <apeposhi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:25:17 by apeposhi          #+#    #+#              #
#    Updated: 2024/08/15 15:04:48 by apeposhi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT #
NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
RM		= @rm -f
FILE	= $(shell ls -lR src/ | grep -F .c | wc -l)
CMP		= 1

SRC		= ./src/memory/ft_bzero.c\
	      ./src/check/ft_isalpha.c\
	      ./src/check/ft_isprint.c\
	      ./src/memory/ft_memcpy.c\
		  ./src/string/ft_cut_chr.c\
	      ./src/string/ft_strchr.c\
	      ./src/string/ft_strlcpy.c\
	      ./src/string/ft_strrchr.c\
	      ./src/memory/ft_calloc.c\
	      ./src/check/ft_isascii.c\
	      ./src/memory/ft_memchr.c\
	      ./src/memory/ft_memmove.c\
	      ./src/string/ft_strdup.c\
	      ./src/string/ft_strlen.c\
	      ./src/string/ft_tolower.c\
	      ./src/string/ft_atoi.c\
	      ./src/check/ft_isalnum.c\
	      ./src/check/ft_isdigit.c\
	      ./src/memory/ft_memcmp.c\
	      ./src/memory/ft_memset.c\
	      ./src/string/ft_strlcat.c\
	      ./src/string/ft_strnstr.c\
	      ./src/string/ft_toupper.c\
		  ./src/string/ft_strcmp.c\
	      ./src/string/ft_strncmp.c\
	      ./src/string/ft_substr.c\
	      ./src/string/ft_strjoin.c\
	      ./src/string/ft_strtrim.c\
	      ./src/string/ft_split.c\
	      ./src/string/ft_itoa.c\
	      ./src/string/ft_strmapi.c\
	      ./src/string/ft_striteri.c\
	      ./src/print/ft_putchar_fd.c\
	      ./src/print/ft_putstr_fd.c\
	      ./src/print/ft_putendl_fd.c\
	      ./src/print/ft_putnbr_fd.c\
		  ./src/print/ft_putchar.c\
		  ./src/print/ft_putstr.c\
		  ./src/print/ft_puthexa.c\
		  ./src/print/ft_putnbr.c\
		  ./src/print/ft_putunsigned.c\
		  ./src/print/ft_putptr.c\
		  ./src/list/ft_lstnew.c\
		  ./src/list/ft_lstadd_front.c\
		  ./src/list/ft_lstsize.c\
		  ./src/list/ft_lstlast.c\
		  ./src/list/ft_lstadd_back.c\
		  ./src/list/ft_lstdelone.c\
		  ./src/list/ft_lstclear.c\
		  ./src/list/ft_lstiter.c\
		  ./src/list/ft_lstmap.c\
		  ./src/stack/ft_stack_add_back.c\
		  ./src/stack/ft_stack_indexing.c\
		  ./src/stack/ft_stack_last.c\
		  ./src/stack/ft_stack_min.c\
		  ./src/stack/ft_stack_new.c\
		  ./src/stack/ft_stack_size.c\
		  ./src/stack/ft_stack_sorted.c\
		  ./src/stack/ft_sqrt.c\
		  ./src/stack/ft_stack_rotations.c\
		  ./src/get_next_line.c\

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.SILENT:
	all

.PHONY: 
	all clean fclean re