CC := cc

CFLAGS := -Wall -Wextra -Werror

AR := ar rcs

RM := rm -f

NAME := libftprintf.a

NAME_LIBFT := libft.a

DIR_LIBFT := ./libft/

INC := -I ./includes

SRCS := ./printf/ft_printf.c \
./printf/all_print.c \
./printf/convert_hexadecimal.c \
./printf/diu_putnbr.c \

OBJS := $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
		$(MAKE) bonus -C $(DIR_LIBFT)
		cp $(DIR_LIBFT)/$(NAME_LIBFT) $(NAME)
		$(AR) $@ $?

all: $(NAME)

clean:
		$(RM) $(OBJS)
		cd $(DIR_LIBFT) && $(MAKE) clean

fclean:
		make clean
		$(RM) $(NAME)
		cd $(DIR_LIBFT) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re