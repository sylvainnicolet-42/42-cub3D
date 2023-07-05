#
#

NOM		= libmlx.a
SRC		= mlx_shaders.c \
		  mlx_new_window.m \
		  mlx_init_loop.m \
		  mlx_new_image.m \
		  mlx_xpm.c \
		  mlx_int_str_to_wordtab.c

SRC+	= mlx_png.c mlx_mouse.m

OBJ1	=$(SRC:.c=.o)
OBJ		=$(OBJ1:.m=.o)
CFLAGS+	=-O2
CC		= gcc

# add to match string put with X11 in size and position
CFLAGS+= -DSTRINGPUTX11


NL_TXT			= echo ""
CHARG_LINE_TXT	= echo "$(GREEN)█$(RESET)\c"
GREEN			= \033[1;32m
RESET			= \033[0m

all: $(NOM)

$(NOM):	$(OBJ)
		@ar -r $(NOM) $(OBJ) > /dev/null 2>&1
		@ranlib $(NOM) > /dev/null 2>&1
		@$(NL_TXT)

.c.o:
		@${CC} -c $< -o ${<:.c=.o} > /dev/null 2>&1
		@$(CHARG_LINE_TXT)

clean:
	rm -f $(NOM) $(OBJ) *~
	rm -f mlx_app

re: clean all
