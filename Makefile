CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_SRCS = client.c
SERVER_SRCS = server.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_NAME = client
SERVER_NAME = server
LIBFT = libft.a
LIBFTD = libft

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	make -C $(LIBFTD)
	# cp $(LIBFTD)/$(LIBFT) $(CLIENT_NAME)
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(LIBFTD)/$(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	make -C $(LIBFTD)
	# cp $(LIBFTD)/$(LIBFT) $(SERVER_NAME)
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(LIBFTD)/$(LIBFT) -o $(SERVER_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFTD) fclean
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

fclean: clean
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

re: fclean all