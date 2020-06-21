CC		=	gcc
AR		=	ar	r
NAME	=	libmy.a
SRC		=	crd.c\
			linked.c\
			math.c\
			str.c
OBJ		=	$(SRC:%.c=%.o)
TILES	=	*~
CFLAGS	=	-Wall   -Wextra -Werror -std=gnu99
RM	=	rm	-f

$(NAME)	:
			$(CC)	-c	$(SRC)	$(CFLAGS)	&&	$(AR)	$(NAME)	$(OBJ)	&&	ranlib	$(NAME)

.PHONY:	all clean fclean re tiles

all	:	$(NAME)

clean	:
			$(RM)	$(OBJ)

fclean	:	clean
			$(RM)	$(NAME)

re	: fclean	all

tiles	:
			$(RM)	$(TILES)
