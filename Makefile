NAME = libftprintf.a
OBJECT = $(FILES:.c=.o)
FILES = ft_printf.c
CC = gcc
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs
HEADER = ft_printf.h 
PROG = tester.c

all :$(OBJECT)
	$(AR) %?

re : fclean all

clean : 
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

%.o : %.c 
	$(CC) -c $(CFLAGS) $?

save : 
	git add $(FILES) Makefile
	git commit -m autosave
	git push 

test :
	$(CC) $(CFLAGS) $(FILES) $(PROG) -o tester
	./tester

.PHONY: all clean fclean save bonus re test