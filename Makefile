NAME		=	./bin/calculator

SRCS		=	$(wildcard sources/*.c)

OBJS		=	$(patsubst sources/%.c, objects/%.o, $(SRCS))

CC		=	gcc

OBJS_DIR	=	objects

BIN_DIR		=	bin

RM		=	rm -f

RMDIR		=	rm -rf

MKDIR		=	mkdir -p

INCLUDES	=	includes

UNAME		:=	$(shell uname -s)

LINKERS		=	
ifeq ($(UNAME), Linux)
	LINKERS = -lm
endif

CFLAGS		=	-Wall -Wextra -Werror -I$(INCLUDES)

objects/%.o:		sources/%.c
			@if [ ! -d $(OBJS_DIR) ]; then $(MKDIR) $(OBJS_DIR); fi
			$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
			@if [ ! -d $(BIN_DIR) ]; then $(MKDIR) $(BIN_DIR); fi
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)

clean:
			$(RMDIR) $(OBJS_DIR)

fclean:			clean
				$(RMDIR) $(BIN_DIR)

re:			fclean all

.DEFAULT_GOAL	:=	 clear_on_fail

clear_on_fail:
			$(MAKE) all || $(MAKE) fclean

.PHONY:			all clean fclean re clear_on_fail
