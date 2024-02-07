NAME = libftprintf.a

CC = cc

CFLAGS = -Werror -Wextra -Wall

SRCS = $(wildcard *.c)

OBJECTS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) :	$(OBJECTS)
		ar -rcs $(NAME) $(OBJECTS)
clean : 
		rm -f $(OBJECTS)

fclean :	clean
			rm -f $(NAME)

re :	fclean all

.PHONY : all clean fclean re
