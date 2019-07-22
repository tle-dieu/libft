#!/bin/bash

#Libftest
mkdir -p tmp_lib
cat << EOF > tmp_lib/Makefile
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
	  ft_strrev.c \
	  ft_strndup.c \
	  ft_count_words.c \
	  ft_strcdup.c

OBJ = \$(SRC:.c=.o)
INCLUDE = libft.h

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

all: \$(NAME)

\$(NAME): \$(OBJ)
	@\$(AR) \$(NAME) \$(OBJ)
	@echo "\$(GREEN)\$(NAME) has been created\$(NC)"
	@\$(RLIB) \$(NAME)
	@echo "\$(GREEN)\$(NAME) has been indexed\$(NC)"

%.o: %.c \$(INCLUDE)
	@\$(CC) \$(FLAG) -o \$@ -c $<
	@echo "\$(GREEN) [OK]     \$(YELLOW) Compiling:\$(NC)$<"

.PHONY: clean

clean:
	@\$(RM) \$(OBJ)
	@echo "\$(RED)The objects have been removed\$(NC)"

fclean: clean
	@\$(RM) \$(NAME)
	@echo "\$(RED)\$(NAME) has been removed\$(NC)"

re: fclean all
EOF
cp -f sources/*/* tmp_lib
cp -f includes/* tmp_lib
cp -f auteur tmp_lib
bash Libftest/grademe.sh
echo "PATH_LIBFT=../tmp_lib" >> Libftest/my_config.sh
bash Libftest/grademe.sh
if [[ -n $(cat Libftest/deepthought | grep -v Werror | grep -E error\|KO) ]]; then
error=0
	error=1
	printf "\033[31mLibftest: KO\033[0m\n"
else
	printf "\033[32mLibftest: OK\033[0m\n"
fi

#libft_unit_test
make so
awk '/LIBFTDIR/{gsub(/LIBFTDIR\t=\t..\/libft/, "LIBFTDIR = ../")};{print}' libft-unit-test/Makefile > makefile.tmp
mv makefile.tmp libft-unit-test/Makefile
if [[ "$TRAVIS_OS_NAME" == "linux" || "$OSTYPE" == "linux-gnu" ]]; then
	awk '$1 != "{\"ft_tolower\",";'  libft-unit-test/src/init.c > tmp.c && mv tmp.c libft-unit-test/src/init.c
	awk '$1 != "{\"ft_toupper\",";'  libft-unit-test/src/init.c > tmp.c && mv tmp.c libft-unit-test/src/init.c
	awk '$1 != "{\"ft_isalnum\",";'  libft-unit-test/src/init.c > tmp.c && mv tmp.c libft-unit-test/src/init.c
fi

(cd libft-unit-test/ && make && ./run_test)
if [[ -n $(cat libft-unit-test/result.log | grep FAILED) ]]; then
	error=1
	printf "\033[31mlibft-unit-test: KO\033[0m\n"
else
	printf "\033[32mlibft-unit-test: OK\033[0m\n"
fi
rm -rf tmp_lib
exit $error


#moulitest
