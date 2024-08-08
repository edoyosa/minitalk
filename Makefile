CC = gcc
FLAGS = -Wall -Werror -Wextra
CLIENT_SRC = ft_client.c
SERVER_SRC = ft_server.c
CLIENT_SRC_BONUS = ft_client_bonus.c
SERVER_SRC_BONUS = ft_server_bonus.c
LIBFT = libft
LIBFT_ARCHIVE = $(LIBFT)/libftprintf.a
CLIENT_NAME = client
SERVER_NAME = server
INC =  -I$(LIBFT) -L$(LIBFT) -lftprintf

all : $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME) $(SERVER_NAME): $(CLIENT_SRC) $(SERVER_SRC) $(LIBFT_ARCHIVE)
	$(CC) $(FLAGS) -o ${CLIENT_NAME} $(CLIENT_SRC) $(INC)
	$(CC) $(FLAGS) -o ${SERVER_NAME} $(SERVER_SRC) $(INC)

$(LIBFT_ARCHIVE):
	$(MAKE) -C $(LIBFT)
bonus: $(CLIENT_SRC_BONUS) $(SERVER_SRC_BONUS) $(LIBFT_ARCHIVE)
	$(CC) $(FLAGS) -o ${CLIENT_NAME} $(CLIENT_SRC_BONUS) $(INC)
	$(CC) $(FLAGS) -o ${SERVER_NAME} $(SERVER_SRC_BONUS) $(INC)
clean:
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(MAKE) -C $(LIBFT) fclean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
