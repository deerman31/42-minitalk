# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykusano <ykusano@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/05 03:17:34 by ykusano           #+#    #+#              #
#    Updated: 2023/04/11 19:26:47 by ykusano          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT := client
SERVER := server
B_CLIENT := client_bonus
B_SERVER := server_bonus
CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
INC := -I ./includes
PRINTF_DIR := ./ft_printf
PRINTF := libftprintf.a

CLIENT_SRCS := client.c
SERVER_SRCS := server.c
B_CLIENT_SRCS := client_bonus.c
B_SERVER_SRCS := server_bonus.c

CLIENT_OBJS := $(CLIENT_SRCS:%.c=%.o)
SERVER_OBJS := $(SERVER_SRCS:%.c=%.o)
B_CLIENT_OBJS := $(B_CLIENT_SRCS:%.c=%.o)
B_SERVER_OBJS := $(B_SERVER_SRCS:%.c=%.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

all : $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENT_OBJS)
	$(MAKE) -C $(PRINTF_DIR) re
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(PRINTF_DIR)/$(PRINTF) -o $(CLIENT)

$(SERVER): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(PRINTF_DIR)/$(PRINTF) -o $(SERVER)

bonus : $(B_CLIENT) $(B_SERVER)

$(B_CLIENT): $(B_CLIENT_OBJS)
	$(MAKE) -C $(PRINTF_DIR) re
	$(CC) $(CFLAGS) $(B_CLIENT_OBJS) $(PRINTF_DIR)/$(PRINTF) -o $(B_CLIENT)

$(B_SERVER): $(B_SERVER_OBJS)
	$(CC) $(CFLAGS) $(B_SERVER_OBJS) $(PRINTF_DIR)/$(PRINTF) -o $(B_SERVER)

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) $(CLIENT_OBJS) $(SERVER_OBJS) $(B_CLIENT_OBJS) $(B_SERVER_OBJS)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(CLIENT) $(SERVER) $(B_CLIENT) $(B_SERVER)

re: fclean all

.PHONY: all bonus clean fclean re
