NAME	=	cube_rubik

CC		=	clang++
CFLAGS	=	#-Wall -Werror -Wextra
OPENGL	=	-lGL -lGLU -lglut

HEADER	=	init.hpp \
			Rubik.hpp \
			Cell.hpp \
			Cube.hpp
SRC		=	main.cpp \
			Rubik.cpp \
			Rubik_simple.cpp \
			Rubic_move.cpp \
			Cell.cpp \
			Cube.cpp

OBJ_DIR =	obj/
OBJ		=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

RM_DIR	=	rm -rf
RM_FILE	=	rm -f

#COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[32m"
C_GOOD	=	"\033[32m"

#DEBUG
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all		:	$(NAME)

$(OBJ): 	| $(OBJ_DIR)	

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			
$(OBJ_DIR)%.o	:	%.cpp ${HEADER} Makefile
					$(CC) $(CFLAG) -c $< -o $@

$(NAME)	:	$(OBJ) 
			$(CC) $(CFLAGS)  $(OBJ) $(OPENGL) -o $(NAME) 
			@echo "\tCompiling...\t" [ $(NAME) ] $(SUCCESS)

clean	:
			@$(RM_DIR) $(OBJ_DIR)
			@echo "\tCleaning...\t" [ $(OBJ_DIR) ] $(OK)

fclean	:	clean
			@$(RM_FILE) $(NAME)
			@echo "\tDeleting...\t" [ $(NAME) ] $(OK)

re		:	fclean all

.PHONY	:	all, clean, fclean, re, test
