


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

CC=cc

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)

NAME=libmlx.dylib

NL_TXT			= echo ""
CHARG_LINE_TXT	= echo "$(GREEN)█$(RESET)\c"
GREEN			= \033[1;32m
RESET			= \033[0m

INC=-I.

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	@swiftc $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz > /dev/null 2>&1
	@$(NL_TXT)

.c.o:
	@${CC} -c $< -o ${<:.c=.o}
	@$(CHARG_LINE_TXT)

%.o: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@ > /dev/null 2>&1
	@$(CHARG_LINE_TXT)

%.swiftmodule: %.swift
	@swiftc $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<) > /dev/null 2>&1
	@$(CHARG_LINE_TXT)

clean:
	@rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~ > /dev/null 2>&1

