SRCS = main.cpp			\
       OutputHandler.cpp	\
       ThreadManager.cpp	\
       Tucson.cpp		\

SRDIR = src/
NAME = tucsonProject
DSRC = $(addprefix $(SRDIR), $(SRCS))
ALLC = $(DSRC)
OBJS = $(DSRC:.cpp=.o)
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -Iinc
RM = rm -rf

all: $(NAME)

##$(OBJS) : $(ALLC)
##	$(CC) $(CFLAGS) -c $< -o $@
$(NAME) : $(OBJS)
	$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
