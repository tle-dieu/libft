NAME := libft.a
CC := gcc
FLAG := -Wall -Werror -Wextra

AR := ar rc
RLIB := ranlib
RM := rm -rf

SOURCES_FOLDER := sources/
OBJECTS_FOLDER := objects/
INCLUDES_FOLDER := includes/

vpath %.c $(SOURCES_FOLDER)

STRING := string/
NUMERIC := numeric/
FT_PRINTF := ft_printf/
UTILS := utils/
LIST := list/
MEMORY := memory/

SOURCES := $(FT_PRINTF)buff.c \
		  $(FT_PRINTF)colors.c \
		  $(FT_PRINTF)conv_cs.c \
		  $(FT_PRINTF)conv_di.c \
		  $(FT_PRINTF)conv_f.c \
		  $(FT_PRINTF)conv_lcls.c \
		  $(FT_PRINTF)conv_oux.c \
		  $(FT_PRINTF)conv_p.c \
		  $(FT_PRINTF)flags.c \
		  $(FT_PRINTF)ft_printf.c \
		  $(FT_PRINTF)ftoa_binary.c \
		  $(FT_PRINTF)ftoa_bint.c \
		  $(FT_PRINTF)ftoa_calc.c \
		  $(FT_PRINTF)ftoa_list.c \
		  $(FT_PRINTF)utils.c \
		  $(STRING)ft_count_words.c \
		  $(STRING)ft_isalnum.c \
		  $(STRING)ft_isalpha.c \
		  $(STRING)ft_isascii.c \
		  $(STRING)ft_isdigit.c \
		  $(STRING)ft_isprint.c \
		  $(STRING)ft_putstr.c \
		  $(STRING)ft_putstr_fd.c \
		  $(STRING)ft_strcat.c \
		  $(STRING)ft_strcdup.c \
		  $(STRING)ft_strchr.c \
		  $(STRING)ft_strclen.c \
		  $(STRING)ft_strclr.c \
		  $(STRING)ft_strcmp.c \
		  $(STRING)ft_strcpy.c \
		  $(STRING)ft_strdel.c \
		  $(STRING)ft_strdup.c \
		  $(STRING)ft_strequ.c \
		  $(STRING)ft_striter.c \
		  $(STRING)ft_striteri.c \
		  $(STRING)ft_strjoin.c \
		  $(STRING)ft_strlcat.c \
		  $(STRING)ft_strlen.c \
		  $(STRING)ft_strmap.c \
		  $(STRING)ft_strmapi.c \
		  $(STRING)ft_strncat.c \
		  $(STRING)ft_strncmp.c \
		  $(STRING)ft_strncpy.c \
		  $(STRING)ft_strndup.c \
		  $(STRING)ft_strnequ.c \
		  $(STRING)ft_strnew.c \
		  $(STRING)ft_strnstr.c \
		  $(STRING)ft_strrchr.c \
		  $(STRING)ft_strrev.c \
		  $(STRING)ft_strsplit.c \
		  $(STRING)ft_strstr.c \
		  $(STRING)ft_strsub.c \
		  $(STRING)ft_strtrim.c \
		  $(STRING)ft_strupper.c \
		  $(STRING)ft_tolower.c \
		  $(STRING)ft_toupper.c \
		  $(NUMERIC)ft_atoi.c \
		  $(NUMERIC)ft_atoll.c \
		  $(NUMERIC)ft_iterative_power.c \
		  $(NUMERIC)ft_itoa.c \
		  $(NUMERIC)ft_sort_integer_table.c \
		  $(NUMERIC)ft_sqrt.c \
		  $(MEMORY)ft_bzero.c \
		  $(MEMORY)ft_memalloc.c \
		  $(MEMORY)ft_memccpy.c \
		  $(MEMORY)ft_memchr.c \
		  $(MEMORY)ft_memcmp.c \
		  $(MEMORY)ft_memcpy.c \
		  $(MEMORY)ft_memdel.c \
		  $(MEMORY)ft_memmove.c \
		  $(MEMORY)ft_memset.c \
		  $(LIST)ft_lstadd.c \
		  $(LIST)ft_lstdel.c \
		  $(LIST)ft_lstdelone.c \
		  $(LIST)ft_lstfind.c \
		  $(LIST)ft_lstiter.c \
		  $(LIST)ft_lstlen.c \
		  $(LIST)ft_lstmap.c \
		  $(LIST)ft_lstnew.c \
		  $(UTILS)ft_print_words_tables.c \
		  $(UTILS)ft_putchar.c \
		  $(UTILS)ft_putchar_fd.c \
		  $(UTILS)ft_putendl.c \
		  $(UTILS)ft_putendl_fd.c \
		  $(UTILS)ft_putnbr.c \
		  $(UTILS)ft_putnbr_fd.c \
		  $(UTILS)get_next_line.c

OBJECTS := $(addprefix $(OBJECTS_FOLDER), $(SOURCES:.c=.o))

RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
NC := \033[0m

all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $^
	@echo "$(GREEN)$(NAME) has been created$(NC)"
	@$(RLIB) $(NAME)
	@echo "$(GREEN)$(NAME) has been indexed$(NC)"

objects/%.o: %.c $(INCLUDE_FOLDER)
	@mkdir -p $(dir $@) 
	@$(CC) $(FLAG) -I $(INCLUDES_FOLDER) -o $@ -c $<
	@echo "$(GREEN) [\xE2\x9C\x93]     $(YELLOW) Compiling:$(NC) $(basename $(notdir $<))"

.PHONY: clean

clean:
	@$(RM) $(OBJECTS_FOLDER)
	@echo "$(RED)The libft objects have been removed$(NC)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) has been removed$(NC)"

re: fclean all
