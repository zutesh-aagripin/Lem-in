NAME = lem-in

LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a

INCLUDES = ./include
HEADER = $(INCLUDES)/lem_in.h

# dirs
DIR_S = srcs
DIR_O = objs

# files
C_FILES = lem_in.c\
		t_edges.c\
		t_graph.c\
		t_input.c\
		t_verts.c\
		t_path.c\
		names.c\
		matrix.c\
		read_input.c\
		output.c\
		validation.c\
		algorithm.c\
		ford.c\
		reverse_ford.c\

SRCS = $(addprefix $(DIR_S)/,$(C_FILES))
OBJS = $(addprefix $(DIR_O)/,$(C_FILES:.c=.o))

# flags
CC = gcc
FLAGS = -Wall -Werror -Wextra
INC_LIBS = -L $(LIB_DIR) -lft
INC_HEADERS = -I $(INCLUDES)

.PHONY: all clean fclean re

all: tmp $(NAME)

$(NAME): $(OBJS) 
	make -C $(LIB_DIR)
	$(CC) $(FLAGS) $(INC_HEADERS) $(INC_LIBS) -o $@ $(OBJS)

tmp:
	mkdir -p objs

$(DIR_O)/%.o: $(DIR_S)/%.c $(HEADER)
	$(CC) $(FLAGS) -I $(INCLUDES) -I $(LIB_DIR) -c ./$< -o $@

clean:
	rm -rf $(DIR_O)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
