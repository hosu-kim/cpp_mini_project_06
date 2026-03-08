CXX := c++
CXXFLAGS := -Wall -Werror -Wextra -std=c++98

NAME := Serializer
SRCS := main.cpp Base.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re