# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschweit <bschweit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 16:52:55 by bschweit          #+#    #+#              #
#    Updated: 2022/11/22 15:19:53 by bschweit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
	   ft_isprint.c ft_strlen.c ft_memset.c\
	   ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c\
	   ft_strlcat.c ft_toupper.c ft_tolower.c\
	   ft_strncmp.c ft_strchr.c ft_strrchr.c\
	   ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c\
	   ft_calloc.c ft_strdup.c ft_substr.c\
	   ft_strjoin.c ft_strtrim.c ft_split.c\
	   ft_itoa.c ft_strmapi.c ft_striteri.c\
	   ft_putchar_fd.c ft_putstr_fd.c\
	   ft_putendl_fd.c ft_putnbr_fd.c

B_SRCS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c\
		 ft_lstclear_bonus.c ft_lstdelone_bonus.c\
		 ft_lstiter_bonus.c ft_lstlast_bonus.c\
		 ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstmap_bonus.c


B_OBJS = ${B_SRCS:.c=.o}

OBJS = ${SRCS:.c=.o}

NAME = libft.a

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	ar rcs $(NAME) $(OBJS)

bonus : ${B_OBJS}
	ar rcs ${NAME} ${B_OBJS}

all : ${NAME}

clean: 
	${RM} ${OBJS} ${B_OBJS}

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
