CC = cc
CFLAGS = -Wall -Werror -Wextra -I. -g3

LIBFT_PATH = ./Libft
PRINTF_PATH = ./ft_printf

LIBFT = $(LIBFT_PATH)/libft.a
PRINTF = $(PRINTF_PATH)/libftprintf.a

OBJ_DIR = obj/
SRC_DIR = src/

SERVER_SRCS = $(SRC_DIR)server.c $(SRC_DIR)utils.c
CLIENT_SRCS = $(SRC_DIR)client.c $(SRC_DIR)utils.c

SERVER_OBJS = $(SERVER_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
CLIENT_OBJS = $(CLIENT_SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

LDFLAGS = -L$(LIBFT_PATH) -lft -L$(PRINTF_PATH) -lftprintf

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

all: libft printf server client

libft:
	@echo "Compiling libft..."
	@$(MAKE) -C $(LIBFT_PATH)

printf:
	@echo "Compiling ft_printf..."
	@$(MAKE) -C $(PRINTF_PATH)

server: $(SERVER_OBJS) $(LIBFT) $(PRINTF)
	@echo "Compiling server..."
	@$(CC) $(SERVER_OBJS) $(LDFLAGS) -o server
	@echo "Server created!"

client: $(CLIENT_OBJS) $(LIBFT) $(PRINTF)
	@echo "Compiling client..."
	@$(CC) $(CLIENT_OBJS) $(LDFLAGS) -o client
	@echo "Client created!"

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@$(MAKE) clean -C $(PRINTF_PATH)
	@echo "Cleaning objects for Minitalk..."
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@$(MAKE) fclean -C $(PRINTF_PATH)
	@echo "Removing executables..."
	@rm -f server client

re: fclean all

.PHONY: all libft printf server client clean fclean re
