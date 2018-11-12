NAME = libft.a
CC = gcc
FLAG = -Wall -Werror -Wextra

AR = ar rc
RLIB = ranlib
RM = rm -f

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_atoll.c \
	  ft_iterative_power.c \
	  ft_lstfind.c \
	  ft_lstlen.c \
	  ft_print_words_tables.c \
	  ft_sort_integer_table.c \
	  ft_sqrt.c \
	  ft_strrev.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "\033[0;32m$(NAME) has been created\033[0m"
	@$(RLIB) $(NAME)
	@echo "\033[0;32m$(NAME) has been indexed\033[0m"

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<
	@echo "\033[0;32m [OK]     \033[0;33m Compiling:\033[0m$<"

clean:
	@$(RM) $(OBJ)
	@echo "\033[0;31mThe objects have been removed\033[0m"

fclean: clean
	@$(RM) $(NAME)
	@echo "\033[0;31m$(NAME) has been removed\033[0m"

re: fclean all
