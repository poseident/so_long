CC = gcc
CFLAGS = -g -framework OpenGL -framework AppKit -L./mlx -lmlx
RM = @rm -rf

B = "\033[34m"
R = "\033[31m"
DEBEUG = -g -fsanitize=address 

all:
	@echo $(B)[--Compilation...]$(B)
	$(CC) -o so_long libft/libft.a printf/libftprintf.a ./src/*.c  $(CFLAGS)
	@echo $(B)[--Compilation done...]$(B)

fclean:
	$(RM) so_long so_long.dSYM
	$(RM) ./src/*.o
	$(RM) ./mlx/*.o
	@echo $(R)[Removed all..]$(R)

%.o: %.c
	$(CC) ${DEBEUG} -Wall -Wextra -Werror -Imlx -c $< -o $@ 
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) ${DEBEUG}

norm:
	@echo $(B)[--NORMINETTE SUCCES...]$(B)
	norminette $(shell find ./src/ -name "*.c")
.PHONY: re norm fclean all
