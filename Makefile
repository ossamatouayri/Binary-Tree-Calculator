SRC=main.c utils.c
CC= cc
CFLAGS= -Wall -Wextra -Werror -fsanitize=address -g3
NAME= calculator
ADD=git add .
COMMIT=git commit -m"new changes"
PUSH=git push
RM= rm -f

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	$(RM) $(NAME)

push:
	$(ADD)
	$(COMMIT)
	$(PUSH)
