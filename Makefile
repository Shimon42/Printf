NAME = libftprintf.a
SRCS    =   debug.c \
	        ft_printf.c \
			srcs/gest_params.c \
			srcs/treat/per_c.c \
			srcs/treat/per_s.c \
			srcs/treat/per_d.c \
			srcs/treat/per_u.c \
			srcs/treat/per_p.c \
			srcs/treat/per_x.c \
			#srcs/treat/per_lu.c \
			#srcs/treat/per_ld.c \
			#srcs/treat/per_o.c
RM              = rm -f                                                      

CC		= gcc
CFLAGS	= -g3 -Wall -Wextra -Werror
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
			$(MAKE) -C $(LIBFTPATH) bonus
			@echo "\033[0;32m––––––––––––––––––––––––\nMaking Printf\n––––––––––––––––––––––––\033[0;36m"
			cp $(LIBFTPATH)libft.a $(NAME)
			ar rc $(NAME) $(OBJS)

libft:
			$(MAKE) -C $(LIBFTPATH) bonus

comp: 		all
			$(CLEAR)
			$(CC) $(CFLAGS) main.c libftprintf.a

launch :	comp
			./a.out

$(OBJS):	$(INCLUDES)

clean:		
	make -C includes/libft clean
	${RM} $(OBJS)
	

fclean:		clean
	make -C includes/libft fclean
	${RM} $(NAME)
	$(RM) a.out

re:			fclean all

.PHONY: all clean fclean re bonus
