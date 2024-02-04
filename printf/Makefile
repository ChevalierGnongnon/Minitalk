NAME = libftprintf.a

SRCS = ft_char.c \
	ft_decimal.c \
	ft_hexa.c \
	ft_pointer.c \
	ft_printf.c \
	ft_putchar_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_string.c \
	ft_unsigned.c \
	ft_getsize.c \
	ft_strlen.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

CC = gcc

CFLAGS = -Werror -Wextra -Wall

.c.o :
	$(CC) $(CFLAGS) -c $< -o ${<:.c=.o}

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
