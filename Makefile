NAME = libftprintf.a
SRCS    =   debug.c \
	        ft_printf.c \
			srcs/percent/per_c.c \
			srcs/percent/per_s.c \
			srcs/percent/per_d.c \
			srcs/percent/per_u.c \
			srcs/percent/per_lu.c \
			srcs/percent/per_ld.c \
			srcs/percent/per_o.c \
			srcs/percent/per_x.c 
RM              = rm -f                                                      

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MAKE	= make
CLEAR	= clear
RM		= rm -f
OBJS	= ${SRCS:.c=.o}
INCPATH = includes/
LIBFTPATH = $(INCPATH)libft/
INCLUDES =	$(INCPATH)libftprintf.h \
			$(INCPATH)debug.h \
			$(INCPATH)brain.h \
			$(LIBFTPATH)libft.h

all:		$(NAME) $(OBJS) $(INCLUDES)

$(NAME):	$(OBJS) $(INCLUDES)
			$(CLEAR)
			@echo "\033[0;32m––––––––––––––––––––––––\nMaking Libft\n––––––––––––––––––––––––\033[0;33m"
			$(MAKE) -C includes/libft bonus
			@echo "\033[0;32m––––––––––––––––––––––––\nMaking Printf\n––––––––––––––––––––––––\033[0;36m"
			cp includes/libft/libft.a $(NAME)
			ar rc $(NAME) $(OBJS)

comp: 	
			$(CLEAR)
			$(CC) $(CFLAGS) main.c libftprintf.a

launch :	all comp
			./a.out

$(OBJS):	$(INCLUDES)

clean:		
	make -C includes/libft clean
	${RM} $(OBJS)
	

fclean:		clean
	make -C includes/libft fclean
	${RM} $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus
