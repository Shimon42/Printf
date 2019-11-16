NAME = libftprintf.a
SRCS    =       debug.c \
	        ft_printf.c 

RM              = rm -f                                                      
INCLUDES =      debug.h ft_printf.h

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
OBJS	= ${SRCS:.c=.o}
INCLUDES =	libftprintf.h


all:		$(NAME) $(INCLUDES)

$(NAME): 	$(OBJS) $(INCLUDES)
	ar rc $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJSBNS) $(INCLUDES)
	ar rc $(NAME) $(OBJS) $(OBJSBNS)


comp: 	
			clear
			$(CC) $(CFLAGS) main.c $(NAME)

launch :	re comp
			./a.out

$(OBJS):	$(INCLUDES)

$(OBJSBNS):	$(INCLUDES)

clean:		
	${RM} $(OBJS) $(OBJSBNS)

fclean:		clean
	${RM} $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus
