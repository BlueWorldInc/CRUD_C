CC	=	gcc
NAME	=	mycrd
TILES   =   *~
RM	=	rm -f
RMD	=	rm	-R -f
SRC		=	my_crd.c
OBJ     =   $(SRC:%.c=%.o)
CFLAGS  =   -L./libmy	-Wall	-Wextra	-Werror	-std=gnu99
LDFLAGS =   -lmy
$(NAME) :
			cd	libmy/	&& make && cd	..	&&	$(CC)	-o	$(NAME)	$(SRC)	$(CFLAGS)	$(LDFLAGS) && mkdir -p Release && mv mycrd Release/

.PHONY:	all clean fclean re tiles

all	:	$(NAME)

clean	:
			$(RM)	$(OBJ)

fclean	:	clean
			$(RM)	$(NAME)	&&	$(RMD)	Release/	&&	cd libmy/	&& make	fclean	&&	cd	..
re	:	fclean	all

tiles	:
			$(RM)   $(TILES)
