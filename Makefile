NAME	= trade

CC	= g++

RM	= rm -f

RMO	= rm *.o

SRCS	= 	./main.cpp 			\
	  		./src/trade.cpp 		\
			./src/fill_candles.cpp	\
			./src/do_mg.cpp			\
			./src/identify_candle.cpp			\
			./src/keltner.cpp

OBJS	= $(SRCS:.cpp=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS) $(RMO)

fclean: clean
	$(RM) $(NAME) $(RM0)

re: fclean all
	$(RMO)

.PHONY: all clean fclean re
