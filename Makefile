LIB			=	./includes/libft 

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

all:	libft server client

libft:	
		@make -C $(LIB)

server:	server.o error.o includes/minitalk.h
		@make -C $(LIB)
		@$(CC) server.o error.o ./includes/libft/libft.a -o $@

client:	client.o error.o includes/minitalk.h
		@make -C $(LIB)
		@$(CC) client.o error.o ./includes/libft/libft.a -o $@

%.o : %.c 
		@$(CC) $(CFLAGS) $< -c -I includes

clean :
	@make clean -C $(LIB)
	@rm -f *.o

fclean: clean
	@make fclean -C $(LIB)
	@rm -f server client

re: fclean all		
