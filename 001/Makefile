NAME	=	chief_list

SRCS	=	main.cpp

OBJ		=	$(SRCS:.cpp=.o)
DEP		=	$(SRCS:.cpp=.d)

CPPFLAGS	=	c++ -Wall -Wextra -Werror -MMD

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CPPFLAGS) -o $(NAME) $(OBJ)
-include $(DEP)

%.o:%.cpp
	$(CPPFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ) $(DEP)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean
