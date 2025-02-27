CC = cc
CFLAGS = -Wall -Wextra -Werror
CLIENT_OBJS = client.c
SERVER_OBJS = server.c
CLIENT_NAME = client
SERVER_NAME = server
LIBFT = libft.a
LIBFTD = libft

all: $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_OBJS)
	make -C $(LIBFTD)
	cp $(LIBFTD)/$(LIBFT) $(CLIENT_NAME)
	$(CC) $(CFLAGS) $(LIBFTD)/$(LIBFT) -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_OBJS)
	make -C $(LIBFTD)
	cp $(LIBFTD)/$(LIBFT) $(SERVER_NAME)
	$(CC) $(CFLAGS) $(LIBFTD)/$(LIBFT) -o $(SERVER_NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFTD) fclean
	rm -f $(CLIENT_OBJS) $(SERVER_OBJS)

flcean: clean
	make -C (LIBFTD)
	rm -f client server

re: fclean all