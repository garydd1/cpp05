Name = aform
CC = g++ -std=c++98
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
HEADERS = $(wildcard *.hpp)

all: $(Name)

$(Name): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $(Name) $(OBJS)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) *.txt

fclean: clean
	rm -f $(Name)

re: fclean all

.PHONY: all clean fclean re