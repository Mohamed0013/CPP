NAME = scalar_converter
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:%.cpp=%.o)


all: $(NAME)

$(NAME): $(OBJS)
		 $(CXX) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all