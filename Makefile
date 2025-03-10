CC = cc
CFLAGS = -Wall -Wextra -Werror -g
libft = utils.c
libft_bonus = utils_bonus.c
CLIENT_SRCS = client.c $(libft)
SERVER_SRCS = server.c $(libft)
CLIENT_SRCS_BONUS = client_bonus.c $(libft_bonus)
SERVER_SRCS_BONUS = server_bonus.c $(libft_bonus)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

all: $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

$(CLIENT_NAME): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o $(SERVER_NAME)

$(CLIENT_NAME_BONUS): $(CLIENT_OBJS_BONUS)
	$(CC) $(CFLAGS) $(CLIENT_SRCS_BONUS) -o $(CLIENT_NAME_BONUS)

$(SERVER_NAME_BONUS): $(SERVER_OBJS_BONUS)
	$(CC) $(CFLAGS) $(SERVER_SRCS_BONUS) -o $(SERVER_NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS) $(CLIENT_OBJS_BONUS) $(SERVER_OBJS_BONUS)

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME) $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

re: fclean all
