# Makefile for server and client compilation with libft

# Executables
SERVER_EXECUTABLE = server
CLIENT_EXECUTABLE = client

# Directories
LIBFT_DIR = Libft
SRC_DIR = src
OBJ_DIR = obj

# Source files
SERVER_SOURCES = $(SRC_DIR)/server.c
CLIENT_SOURCES = $(SRC_DIR)/client.c
LIBFT_SOURCES = $(wildcard $(LIBFT_DIR)/*.c) $(wildcard $(LIBFT_DIR)/bonus/*.c)

# Object files
SERVER_OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SERVER_SOURCES))
CLIENT_OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(CLIENT_SOURCES))
LIBFT_OBJECTS = $(patsubst $(LIBFT_DIR)/%.c,$(OBJ_DIR)/%.o,$(LIBFT_SOURCES))

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR)

# Targets
all: $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

$(SERVER_EXECUTABLE): $(LIBFT_OBJECTS) $(SERVER_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(CLIENT_EXECUTABLE): $(LIBFT_OBJECTS) $(CLIENT_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(LIBFT_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(SERVER_EXECUTABLE) $(CLIENT_EXECUTABLE)

re: fclean all

.PHONY: all clean fclean re
