CC = gcc
FLAGS = -Wall -Werror -Wextra
CLIENT_SRC = ft_client.c
SERVER_SRC = ft_server.c
LIBFT = libft
LIBFT_ARCHIVE = $(LIBFT)/libftprintf.a
CLIENT_NAME = client
SERVER_NAME = server
INC =  -I$(LIBFT) -L$(LIBFT) -lftprintf

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT_ARCHIVE)
	$(CC) $(FLAGS) -o $@ $(CLIENT_SRC) $(INC)

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT_ARCHIVE)
	$(CC) $(FLAGS) -o $@ $(SERVER_SRC) $(INC)

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT)

clean:
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re
