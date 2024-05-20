# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angemart <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/14 13:03:35 by angemart          #+#    #+#              #
#    Updated: 2024/03/18 11:58:39 by cash             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp_test.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \

BNS_SRC = ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstadd_back.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \

OBJS = $(SRC:.c=.o)

BNS_OBJS = $(BNS_SRC:.c=.o)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo "$(NAME) created"

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(BNS_OBJS)
	@ar rc $(NAME) $(BNS_OBJS)
	@echo "Bonus functions incorporated to $(NAME)"

clean:
	@rm -f $(OBJS) $(BNS_OBJS)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "OBJ and $(NAME) deleted"

re: fclean all

.PHONY: all, bonus, clean, fclean, re