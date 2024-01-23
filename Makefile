# Variable Names
CLIENT_EXECUTABLE = client
SERVER_EXECUTABLE = server
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
INCLUDE_DIRS = -I include/ -I ft_libft/include/

# Object Files
CLIENT_OBJ = src/client.o
SERVER_OBJ = src/server.o

# Library
FT_LIBFT = ft_libft/libft.a

# Targets
all: $(CLIENT_EXECUTABLE) $(SERVER_EXECUTABLE) $(FT_LIBFT)

$(CLIENT_EXECUTABLE): $(CLIENT_OBJ) $(FT_LIBFT) include/minitalk.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(CLIENT_OBJ) $(FT_LIBFT) -o $(CLIENT_EXECUTABLE)

$(SERVER_EXECUTABLE): $(SERVER_OBJ) $(FT_LIBFT) include/minitalk.h
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) $(SERVER_OBJ) $(FT_LIBFT) -o $(SERVER_EXECUTABLE)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -c $< -o $@

ft_libft/libft.a: FORCE
	@make -C ft_libft

# Clean Targets
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
	make clean -C ft_libft

# Force Rebuild
FORCE:

# Full Clean
fclean: clean
	rm -f $(CLIENT_EXECUTABLE) $(SERVER_EXECUTABLE)
	make fclean -C ft_libft

# Rebuild
re: fclean all

# Phony Targets
.PHONY: all clean fclean re FORCE
