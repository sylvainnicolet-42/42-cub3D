
	### COMPILATION ###

CC			= gcc -g #-fsanitize=address
FLAGS		= -Wall -Werror -Wextra
FRAMEWORK	= -framework OpenGL -framework AppKit

	### EXECUTABLE ###

NAME		= cub3D

	### PATH ###

SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl
MLX			= libs/libmlx
LIBFT		= libs/libft
GNL			= libs/gnl

	###	LIBS ###

LIBS		= -lmlx -lft -lgnl
LIBS_PATH	= -L$(MLX) -L$(LIBFT) -L$(GNL)

	### SOURCES FILES ###

	# MAIN

MAIN_FILE	= main.c

	# PARSING

PARSE_FILE	= check_arguments.c \

	### OBJECT FILES ###

MAIN_FILE	:= $(addprefix $(OBJS_PATH)/, $(MAIN_FILE:.c=.o))
PARSE_FILE	:= $(addprefix $(OBJS_PATH)/parsing/, $(PARSE_FILE:.c=.o))

OBJS		:= $(MAIN_FILE) \
			   $(PARSE_FILE)

	### COLORS ###

RED			= \033[1;31m
GREEN		= \033[1;32m
CYAN		= \033[1;36m
RESET		= \033[0m

	### TEXTES ###

MLX_TXT			= echo "$(CYAN)=== Compiling MLX ===$(RESET)"
LIBFT_TXT		= echo "$(CYAN)=== Compiling LIBFT ===$(RESET)"
GNL_TXT			= echo "$(CYAN)=== Compiling GNL ===$(RESET)"
MLX_END_TXT		= echo "$(GREEN)=== MLX Compilated ===$(RESET)"
LIBFT_END_TXT	= echo "$(GREEN)=== LIBFT Compilated ===$(RESET)"
GNL_END_TXT		= echo "$(GREEN)=== GNL Compilated ===$(RESET)"
START_TXT		= echo "$(CYAN)=== Compiling Project ===$(RESET)"
END_TXT			= echo "$(GREEN)=== Project Compilated ===$(RESET)"
CHARG_LINE_TXT	= echo "$(GREEN)█$(RESET)\c"
CLEAN_TXT		= echo "$(RED) Deleting all files$(RESET)"
FCLEAN_TXT		= echo "$(RED) Deleting $(NAME)$(RESET)"
NL_TXT			= echo ""

	### RULES ###

all:		libs tmp $(NAME)

art:
			@tput setaf 2; cat .ascii_art/projet; tput setaf default
			@tput setaf 2; cat .ascii_art/name; tput setaf default

$(NAME):	$(OBJS)
			$(CC) $(FLAGS) $(FRAMEWORK) -o $@ $(OBJS) $(LIBS_PATH) $(LIBS)
			@$(NL_TXT)
			@$(END_TXT)

tmp:
			@mkdir -p objs

libs:		mlx libft gnl
			@$(START_TXT)

mlx:
			@$(MLX_TXT)
			@make -C $(MLX)
			@cp $(MLX)/libmlx.dylib .
			@$(MLX_END_TXT)
			@$(NL_TXT)

libft:
			@$(LIBFT_TXT)
			@make -C $(LIBFT)
			@$(LIBFT_END_TXT)
			@$(NL_TXT)

gnl:
			@$(GNL_TXT)
			@make -C $(GNL)
			@$(GNL_END_TXT)
			@$(NL_TXT)



$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
					@mkdir -p $(@D)
					$(CC) $(FLAGS) $(INCS_PATH) -c $< -o $@

clean:
			@$(CLEAN_TXT)
			@tput setaf 1; cat .ascii_art/trash; tput setaf default
			@rm -rf $(OBJS_PATH)
			@make clean -C $(MLX)
			@make fclean -C $(LIBFT)
			@make fclean -C $(GNL)

fclean:		clean
			@$(FCLEAN_TXT)
			@rm -f libmlx.dylib
			@rm -rf $(NAME)
			@$(NL_TXT)

re:			fclean all

.PHONY:		clean fclean re tmp libs all libft