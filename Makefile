NAME = client
srv = server

CSRC = client.c
SSRC =  server.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

COBJS = $(CSRC:.c=.o)
SOBJS = $(SSRC:.c=.o)

all: $(NAME) $(srv)

$(NAME): $(COBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(srv): $(SOBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(COBJS) $(SOBJS)

fclean: clean
	rm -f $(NAME) $(srv)

re: fclean all
