SRC=main.c utils.c
CC= cc
CFLAGS= -Wall -Wextra -Werror
NAME= calculator
RM= rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)
