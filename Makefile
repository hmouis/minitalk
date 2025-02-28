NAME = client
srv = server
BNAME = client_bonus
bsrv = server_bonus

MCSRC = client.c
MSSRC = server.c
BCSRC = client_bonus.c
BSSRC =  server_bonus.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g 

MCOBJS = $(MCSRC:.c=.o)
MSOBJS = $(MSSRC:.c=.o)
BCOBJS = $(BCSRC:.c=.o)
BSOBJS = $(BSSRC:.c=.o)

all: $(NAME) $(srv)

bonus: $(BNAME) $(bsrv)

$(NAME): $(MCOBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(srv): $(MSOBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(BNAME): $(BCOBJS)
	$(CC) $(CFLAGS) $^ -o $@

$(bsrv): $(BSOBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MCOBJS) $(BCOBJS) $(BSOBJS) $(MSOBJS)

fclean: clean
	rm -f $(NAME) $(srv) $(BNAME) $(bsrv)

re: fclean all
