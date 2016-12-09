CC	=	gcc

NAME	=	bswireframe

SRC	=						altmain.c			\
							fml.c				\
							init_gen.c			\
							my_put_pixel.c			\
							my_draw_line.c			\
							dotgen.c			\
							colorgen.c			\
							my_put_3d.c			\
							my_put_4d.c			\
							coordgen.c			\
							vertex_gen.c		\
							draw_vertex.c	\
							filetotab.c		\
							filetotab2.c	\
							filetotab3.c	\
							slinstr.c			\
							my_strlen.c		\
							my_get_nbr.c

OBJ	=	$(SRC:.c=.o)

INCLUDE	= -lm -lc_graph_prog

CFLAGS	+=	$(INCLUDE) -g

LDFLAGS	+=

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) -W -Wall -Wextra -Werror -pedantic -ansi

all:	$(NAME)	

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all clean

run:	fclean all
	./bswireframe bonus/maps/pylone.map

.PHONY:	all clean fclean re run
