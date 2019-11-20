NAME = libftprintf.a
SRCS    =   debug.c \
	        ft_printf.c \
			srcs/percent/per_s.c
RM              = rm -f                                                      

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
OBJS	= ${SRCS:.c=.o}
INCPATH = includes/
INCLUDES =	$(INCPATH)libftprintf.h \
			$(INCPATH)debug.h \
			$(INCPATH)brain.h

all:		$(NAME) $(INCLUDES)

$(NAME): 	$(OBJS) $(INCLUDES)
	ar rc $(NAME) $(OBJS)

comp: 	
			clear
			$(CC) $(CFLAGS) main.c $(NAME) $(INCLUDES) libft.a

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
