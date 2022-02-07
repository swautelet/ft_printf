NAME = libftprintf.a
OBJECT = $(FILES:.c=.o)
FILES = ft_printf.c ft_printf_utils.c ft_printf_utils2.c
CC = gcc
CFLAGS = -Werror -Wall -Wextra
AR = ar rcs
HEADER = ft_printf.h 
PROG = tester.c
EXE = tester

all :$(OBJECT)
	$(AR) $(NAME) $?

$(NAME) : all

re : fclean all

clean : 
	rm -f $(OBJECT)

fclean : clean
	rm -f $(NAME)

%.o : %.c 
	$(CC) -c $(CFLAGS) $?

save : 
	git add $(FILES) $(HEADER) Makefile
	git commit -m autosave
	git push git@vogsphere-v2.s19.be:vogsphere/intra-uuid-443fc587-8920-4935-832c-e25e6b57e9a6-3985179-swautele

test :
	$(CC) $(CFLAGS) $(FILES) $(PROG) -o $(EXE)
	./$(EXE)
	rm $(EXE)

.PHONY: all clean fclean save bonus re test