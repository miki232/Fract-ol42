# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/09 12:28:21 by mtoia             #+#    #+#              #
#    Updated: 2022/05/02 12:21:59 by mtoia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang -O3
FLAGS = -Wall -Wextra -Werror
INC = libft.h

T_BLK = \033[5m
T_NRM = \033[25m
T_CLR = \033[K
C_YLW = \033[33m
C_GRN = \033[32m
C_LYLW = \033[93m
C_LGRN = \033[92m
C_LMGN = \033[95m
C_END = \033[0m

FILES			=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isprint.c ft_memcmp.c \
					ft_calloc.c	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_memchr.c \
					ft_memcpy.c ft_memmove.c ft_strchr.c ft_strdup.c \
					ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
					ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_memset.c \
					ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_split.c ft_strmapi.c \
					ft_striteri.c ft_putchar_fd.c ft_putendl_fd.c ft_putstr_fd.c ft_putnbr_fd.c \

					
BONUS			=	 ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstclear.c

BONUS_OBJS		= $(BONUS:.c=.o)

OBJ := $(FILES:%.c=%.o)

NB = $(words $(FILES))
IND = 0
PER = 0

all: $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC)
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(BONUS_OBJS): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC)
	@$(eval IND=$(shell echo $$(($(IND) + 1))))
	@$(eval PER=$(shell echo $$((($(IND) * 100) / $(NB)))))
	@printf "$(T_CLR)$(C_LYLW)➜ ➜ progress: %3d %% $(C_END)\n\033[1A$(C_END)" $(PER);

$(NAME):
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling objects ... $(C_END)"
	@make $(OBJ)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Objects have been compiled successfully ! $(C_END)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been Compiled Successfully !$(C_END)"

clean:
	@rm -f $(OBJ) $(OBONUS) $(BONUS_OBJS)
	@echo "$(C_LMGN)➜ [$(NAME)] Objects have been cleaned Successfully !$(C_END)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(C_LMGN)➜ [$(NAME)] Library has been deleted Successfully !$(C_END)"

re: fclean all
	@echo "$(C_LGRN)➜ [$(NAME)] Library has been re-builded\
	 Successfully !$(C_END)"

bonus:			
	@echo "$(C_LYLW)➜ [$(NAME)] Compiling Bonus objects ... $(C_END)"
	@make $(BONUS_OBJS) $(NAME)
	@echo "\033[1A$(T_CLR)$(C_LGRN)➜ [$(NAME)] Bonus objects have been compiled successfully ! $(C_END)"
	@ar rcs $(NAME) $(OBJ) $(BONUS_OBJS)
	@ranlib $(NAME)
	@echo "$(C_LGRN)➜ [$(NAME)] Library with Bonus has been Compiled Successfully !$(C_END)"
	
norm:
	@norminette $(FILES) $(BONUS) $(INC)
	@echo "[$(C_LGRN)➜ [$(NAME)] Files analized $(C_END)]"

.PHONY: clean fclean re all bonus
