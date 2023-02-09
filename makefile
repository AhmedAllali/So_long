# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:43:09 by ahallali          #+#    #+#              #
#    Updated: 2023/02/08 18:24:45 by ahallali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long
NAME_B = so_long_bonus
libft = libft/libft.a

CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

SRCS = mandatory/so_long.c \
		mandatory/so_long_utils.c\
		mandatory/so_long_utils2.c\
		mandatory/so_long_utils3.c\
		mandatory/so_long_utils4.c\
		mandatory/so_long_utils5.c\
		mandatory/GET_NEXT_LINE/get_next_line.c\
		mandatory/GET_NEXT_LINE/get_next_line_utils.c
		
SRCS_B =  bonus/so_long.c \
		bonus/so_long_utils.c\
		bonus/so_long_utils2.c\
		bonus/so_long_utils3.c\
		bonus/so_long_utils4.c\
		bonus/so_long_utils5.c\
		bonus/so_long_utils6.c\
		bonus/so_long_utils7.c\
		bonus/GET_NEXT_LINE/get_next_line.c\
		bonus/GET_NEXT_LINE/get_next_line_utils.c	
		
		
all : ${NAME}

${NAME} : $(libft) ${OBJS}
	 cc $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^
 ${NAME_B} : $(libft) ${OBJS_B}
	 cc $(CFLAGS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME_B) $^

mandatory/%.o: mandatory/%.c  mandatory/so_long.h mandatory/GET_NEXT_LINE/get_next_line.h
	${CC} ${CFLAGS} -c $< -o $@
bonus/%.o: bonus/%.c  bonus/so_long.h bonus/GET_NEXT_LINE/get_next_line.h
	${CC} ${CFLAGS} -c $< -o $@
$(libft): 
	make -C libft && make clean

bonus : ${NAME_B}

clean :
	${RM} ${OBJS} $(OBJS_B)
	make clean -C libft

fclean : clean
	${RM} ${NAME} $(NAME_B)
	make fclean -C libft

re : fclean all 

.PHONY : fclean clean re all