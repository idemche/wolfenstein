# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idemchen <idemchen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/13 23:24:53 by idemche           #+#    #+#              #
#    Updated: 2017/07/31 18:28:14 by idemchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

#
#	MAIN SOURCE
#

SRC = wolf3d.c wolf_auxiliary_functions.c wolf_parse_map.c \
		wolf_dda_draw.c wolf_keys.c wolf_map_storage.c wolf_parse_textures.c \
		wolf_ray_casting.c
FLAGS = -O3
OBJECTS = $(patsubst %.c, %.o, $(SRC))
TEMP_OBJS = $(addprefix $(TMPDIR), $(OBJECTS))
TMP_DIR	= $(TMPDIR)

#
#	MLX
#

MLX_PATH = ./miniLibX
MLX_INC = -I $(MLX_PATH)
MLX_FLAGS = -L $(MLX_PATH) -l mlx -framework OpenGL -framework AppKit

#
#	LIBFT
#

LIB_PATH = ./libft
LIB_DYNAMIC = $(LIB_PATH)/libft.a

#
#	DEBUG
#

DEBUG_EXE = lldb
DEBUG_EXT = .dSYM

all: create

create:	libcreate $(TEMP_OBJS) $(NAME)

libcreate:
	@make -C $(LIB_PATH)

$(NAME):
	@echo "\t\t\t\t\033[0;34m\n\033[0m"
	@echo "\t\033[0;34m|  Welcome to Wolf3D	|\033[0m"
	@echo "\t\033[0;34m|  	Author: idemchen 	|\033[0m"
	@echo "\t\033[0;34m---------------------------------\033[0m"
	@echo "\t\033[0;34m---------------------------------\033[0m"
	@echo "\t\033[0;34m---------------------------------\033[0m"
	@echo "\t\033[0;34mFor makefile help use: [make help]\033[0m"
	@echo "\t\033[0;34m-------------Enjoy!---------------\033[0m"
	@echo "\033[0;34mwolf3d\t\033[1;33mCompilation\t\033[0;32m	[In Progress]\033[0m"
	@clang $(FLAGS) -o $@ $(SRC) $(MLX_INC) $(MLX_FLAGS) $(LIB_DYNAMIC)
	@echo "\033[0;34mwolf3d\t\033[1;33mCompilation\t\033[0;32m	[Done]\033[0m"

$(TEMP_OBJS): $(SRC)
	@clang $(FLAGS) $(MLX_INC) -o $@ -c $<

remake:
	@echo "\033[0;34mwolf3d\t\033[1;33mRemake\t\033[0;32m		[In Progress]\033[0m"

clean:
	@rm -f $(OBJECTS)
	@echo "\033[0;34mwolf3d\t\033[1;33mCleaning obj\t\033[0;32m	[Done]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[0;34mwolf3d\t\033[1;33mCleaning executives\t\033[0;32m[Done]\033[0m"

libclean: fclean
	@make fclean -C $(LIB_PATH)
	@echo "\033[0;34mwolf3d\t\033[1;33mCleaning libft\t\033[0;32m	[Done]\033[0m"

re: remake fclean all

norme:
	@echo "\033[1;34mwolf3d\t\033[1;33mNorminette\t\033[0;32m[In process]\033[0m"
	@norminette $(LEM_SRC)
	@echo "\033[1;34mwolf3d\t\033[1;33mNorminette\t\033[0;32m[Completed]\033[0m"

debug:
	@echo "\033[1;34mwolf3d\t\033[1;33mDebug\t\033[0;32m		[Start]\033[0m"
	@clang -g -o $(NAME) $(SRC) $(LIB_DYNAMIC) $(MLX_INC) $(MLX_FLAGS)
	@echo "\033[1;34mwolf3d\t\033[1;33mDebug\t\033[0;32m		[In process]\033[0m"
	@$(DEBUG_EXE) $(NAME)
	@echo "\033[1;34mwolf3d\t\033[1;33mDebug\t\033[0;32m		[End]\033[0m"
	@rm -r $(NAME) $(NAME)$(DEBUG_EXT)

help:
	@echo "\033[0;33m[make clean] - cleans all object files           		 "
	@echo "\033[0;33m[make fclean] - cleans all object files and executable	 "
	@echo "\033[0;33m[make libclean] - makes complete cleanse including Lib_ft objects and library"
	@echo "\033[0;33m[make norme] - executes './norminette command'	and checks code according Norme"
	@echo "\033[0;33m[make debug] - Enters dubugging mode through lldb. On quit it removes lldb executables"
