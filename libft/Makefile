# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 23:18:10 by ahallali          #+#    #+#              #
#    Updated: 2023/02/04 15:49:57 by ahallali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libft.a
CFLAGS = -Wall -Wextra -Werror -g
AR = ar rcs
RM = rm -f
OBJS = $(SRCS:=.o)
B_OBJS = $(BONUS:=.o)

SRCS = ft_memset \
		ft_bzero \
		ft_memcpy \
		ft_memcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_calloc \
		ft_strdup \
		ft_substr\
		ft_strjoin\
		ft_strtrim\
		ft_split\
		ft_itoa\
		ft_putchar_fd\
		ft_putstr_fd\
		ft_putendl_fd\
		ft_putnbr_fd\
		ft_striteri\
		ft_strmapi

BONUS = 	ft_lstnew \
	  		ft_lstadd_front \
	  		ft_lstsize \
	  		ft_lstlast \
	  		ft_lstadd_back\
	  		ft_lstdelone \
	  		ft_lstclear \
	  		ft_lstiter \
	  		ft_lstmap

all : ${NAME}

${NAME} : ${OBJS}
	${AR} ${NAME} $^

%.o : %.c libft.h
	${CC} ${CFLAGS} -c $< -o  $@

bonus : ${NAME} ${B_OBJS}
	${AR} ${NAME} ${B_OBJS}

clean :
	${RM} ${OBJS} ${B_OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all bonus

.PHONY : bonus fclean clean re