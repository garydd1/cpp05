Name = form
CC = g++ -std=c++98
CFLAGS = -Wall -Wextra -Werror
SRCS = main.cpp Bureaucrat.cpp Form.cpp
OBJS = $(SRCS:.cpp=.o)
HEADERS = Bureaucrat.hpp

all: $(Name)

$(Name): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(Name) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re