NAME	= libftprintf.a
INCPATH = includes/
SRCSPATH = srcs/
LIBFTPATH = $(SRCSPATH)Libft
FOLDNAME = Printf/

SRCS	=	$(SRCSPATH)$(FOLDNAME)debug.c \
			$(SRCSPATH)$(FOLDNAME)ft_printf.c \
			$(SRCSPATH)$(FOLDNAME)gest_params.c \
			$(SRCSPATH)$(FOLDNAME)gest_flags.c \
			$(SRCSPATH)$(FOLDNAME)gest_flags_disp.c \
			$(SRCSPATH)$(FOLDNAME)treat/per_per.c \
			$(SRCSPATH)$(FOLDNAME)treat/per_c.c \
			$(SRCSPATH)$(FOLDNAME)treat/per_s.c \
			$(SRCSPATH)$(FOLDNAME)treat/per_d.c \
			$(SRCSPATH)$(FOLDNAME)treat/per_u.c \
			$(SRCSPATH)$(FOLDNAME)treat/per_p.c \
			$(SRCSPATH)$(FOLDNAME)treat/per_x.c \

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CLEAR	= clear
RM		= rm -f
OBJS	= ${SRCS:.c=.o}

INCLUDES =	$(INCPATH)/brain.h \
			$(INCPATH)/debug.h \
			$(INCPATH)/printf.h

all:		$(NAME) $(OBJS) $(INCLUDES)

$(NAME): 	$(OBJS) $(INCLUDES)
			$(CLEAR)
			@echo "\033[0;32m––––––––––––––––––––––––\nMaking Libft\n––––––––––––––––––––––––\033[0;33m"
			$(MAKE) -C $(LIBFTPATH)
			cp $(LIBFTPATH)/libft.a $(NAME)
			ar rc $(NAME) $(OBJS)
			@echo "\033[0;m"

comp: 		all
			$(CLEAR)
			$(CC) $(CFLAGS) main.c libftprintf.a

launch :	comp
			./a.out

test:		comp
			sh test-printf/test-printf.sh

$(OBJS):	$(INCLUDES)

clean:		
			${RM} $(OBJS)
			$(MAKE) -C $(LIBFTPATH) clean

fclean:		clean
			${RM} $(NAME)
			$(MAKE) -C $(LIBFTPATH) fclean
			
re:			fclean all

.PHONY: all clean fclean re