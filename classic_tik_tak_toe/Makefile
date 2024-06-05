
TARGET	=	Tic-Tac-Toe

CXX	=	g++

CXXFLAGS = -Wall -Wextra -std=c++11

GRAPHIQUE = -lsfml-graphics -lsfml-window -lsfml-system

SRCS	=	src/main.cpp 		\
			src/init.cpp 		\
			src/game_loop.cpp	\
			src/game_fonction.cpp

OBJS	=	$(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(GRAPHIQUE) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: clean all

.PHONY: all clean fclean re
