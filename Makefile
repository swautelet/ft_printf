NAME = libftprintf.a
OBJECT = $(FILES:.c=.o)
FILES = ft_printf.c ft_printf_utils.c
CC = gcc
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs
HEADER = ft_printf.h 
PROG = tester.c

all :$(OBJECT)
	$(AR) $(NAME) $?

re : fclean all

clean : 
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

%.o : %.c 
	$(CC) -c $(CFLAGS) $?

save : 
	git add $(FILES) $(PROG) $(HEADER) Makefile
	git commit -m autosave
	git push 

test :
	$(CC) $(CFLAGS) $(FILES) $(PROG) -o tester
	./tester

.PHONY: all clean fclean save bonus re test