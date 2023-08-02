
# COMPILATION
CC			= gcc -Ofast
FLAG_DEBUG	= -fsanitize=address -g
FLAGS		= -Wall -Werror -Wextra

#	Os Form MLX

LINUX_MLX	= -L$(MLX_LINUX) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz
MAC_MLX		= -L$(MLX) -lmlx -framework OpenGL -framework AppKit

# EXECUTABLE
NAME		= cub3D

# PATH
SRCS_PATH	= srcs
OBJS_PATH	= objs
INCS_PATH	= -Iincl
MLX			= libs/libmlx
MLX_LINUX	= libs/linux_mlx
LIBFT		= libs/libft
GNL			= libs/gnl

# LIBS
LIBS		= -lft -lgnl
LIBS_PATH	= -L$(LIBFT) -L$(GNL) 

	### SOURCES FILES ###
MAIN_FILE	= main.c

ACTION_FILE	= collision.c \
			  moves.c \
			  move_vision.c \

CLOSE_FILE	= close.c \
			  free.c \
			  print.c \

DEBUG_FILE	= debug.c \

MLX_FILE	= init_mlx.c \
			  handle_event.c \
			  key_hook.c \

PARSE_FILE	= check_arguments.c \
			  check_double.c \
			  find_max_value.c \
			  find_player.c \
			  init_cube.c \
			  is_map_valid.c \
			  list_map.c \
			  map_utils.c \
			  set_map.c \
			  set_rgb_textures.c \
			  set_textures.c \
			  set_wall.c \

RAY_FILE	= draw_ray.c \
			  print_ray.c \

RENDER_FILE	= floor_and_ceiling.c \
			  minimap.c \
			  print_player.c \
			  render_next_frame.c \
			  wall.c \

			  # OBJECT FILES
MAIN_FILE	:= $(addprefix $(OBJS_PATH)/, $(MAIN_FILE:.c=.o))
ACTION_FILE	:= $(addprefix $(OBJS_PATH)/actions/, $(ACTION_FILE:.c=.o))
CLOSE_FILE	:= $(addprefix $(OBJS_PATH)/close/, $(CLOSE_FILE:.c=.o))
DEBUG_FILE	:= $(addprefix $(OBJS_PATH)/debug/, $(DEBUG_FILE:.c=.o))
MLX_FILE	:= $(addprefix $(OBJS_PATH)/mlx/, $(MLX_FILE:.c=.o))
PARSE_FILE	:= $(addprefix $(OBJS_PATH)/parsing/, $(PARSE_FILE:.c=.o))
RAY_FILE	:= $(addprefix $(OBJS_PATH)/ray/, $(RAY_FILE:.c=.o))
RENDER_FILE	:= $(addprefix $(OBJS_PATH)/render/, $(RENDER_FILE:.c=.o))

OBJS		:= $(MAIN_FILE) \
			   $(ACTION_FILE) \
			   $(CLOSE_FILE) \
			   $(DEBUG_FILE) \
			   $(MLX_FILE) \
			   $(PARSE_FILE) \
			   $(RAY_FILE) \
			   $(RENDER_FILE) \

# COLORS
RED			= \033[1;31m
GREEN		= \033[1;32m
CYAN		= \033[1;36m
RESET		= \033[0m

# TEXTES
MLX_TXT			= echo "$(CYAN)=== Compiling MLX ===$(RESET)"
LIBFT_TXT		= echo "$(CYAN)=== Compiling LIBFT ===$(RESET)"
GNL_TXT			= echo "$(CYAN)=== Compiling GNL ===$(RESET)"
PRINTF_TXT		= echo "$(CYAN)=== Compiling FT_PRINTF ===$(RESET)"
MLX_END_TXT		= echo "$(GREEN)=== MLX Compilated ===$(RESET)"
LIBFT_END_TXT	= echo "$(GREEN)=== LIBFT Compilated ===$(RESET)"
GNL_END_TXT		= echo "$(GREEN)=== GNL Compilated ===$(RESET)"
PRINTF_END_TXT	= echo "$(GREEN)=== FT_PRINTF Compilated ===$(RESET)"
START_TXT		= echo "$(CYAN)=== Compiling Project ===$(RESET)"
END_TXT			= echo "$(GREEN)=== Project Compilated ===$(RESET)"
CHARG_LINE_TXT	= echo "$(GREEN)█$(RESET)\c"
CLEAN_TXT		= echo "$(RED) Deleting all files$(RESET)"
CLEAN_O_TXT		= echo "$(RED) Deleting Object files of cub3d$(RESET)"
FCLEAN_TXT		= echo "$(RED) Deleting $(NAME)$(RESET)"
NL_TXT			= echo ""

# RULES
all:		libs tmp $(NAME)

art:
			@tput setaf 2; cat .ascii_art/projet; tput setaf default
			@tput setaf 2; cat .ascii_art/name; tput setaf default

$(NAME):	$(OBJS)
ifeq ($(shell uname), Linux)
			$(CC) $(FLAGS) -o $@ $(OBJS) $(LINUX_MLX) $(LIBS_PATH) $(LIBS)
else
			$(CC) $(FLAGS) -o $@ $(OBJS) $(MAC_MLX) $(LIBS_PATH) $(LIBS)
endif
			@$(NL_TXT)
			@$(END_TXT)

debug:		clean_o libs tmp $(OBJS)
			$(CC) $(FLAG_DEBUG) $(FLAGS) $(FRAMEWORK) -o $(NAME) $(OBJS) $(LIBS_PATH) $(LIBS)
			@$(NL_TXT)
			@$(END_TXT)


tmp:
			@mkdir -p objs

libs:		mlx libft gnl
			@$(START_TXT)

mlx:
			@$(MLX_TXT)
ifeq ($(shell uname), Linux)
			make -C $(MLX_LINUX)
else
			@make -C $(MLX)
endif 
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
ifeq ($(shell uname), Linux)
			make clean -C $(MLX_LINUX)
else
			@make clean -C $(MLX)
endif
			@make fclean -C $(LIBFT)
			@make fclean -C $(GNL)

fclean:		clean
			@$(FCLEAN_TXT)
			@rm -f libmlx.dylib
			@rm -rf $(NAME)
			@$(NL_TXT)

re:			fclean all

rre:		clean_o all

clean_o:		
			$(CLEAN_O_TXT)
			@tput setaf 1; cat .ascii_art/trash; tput setaf default
			@rm -rf $(OBJS_PATH)
			@rm -rf $(NAME)
			@$(NL_TXT)

norm:
			norminette incl srcs | grep -v "Missing or invalid 42 header" | grep -v "Empty line at start of file"

.PHONY:		clean clean_o fclean re tmp libs all libft norm
