NAME =		philo

CPATH =		./

SRCS =		ft_actions.c \
			ft_display_extend.c \
			ft_display_normal.c \
			ft_graphic.c \
			ft_itoa.c \
			ft_ncurses.c \
			ft_tool.c \
			main.c \

OBJS =		$(SRCS:.c=.o)

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "\n\r\033[38;5;11m⌛  MAKE $(NAME) plz wait...\033[0m\033[K 💰"
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lncurses
			@echo -en "\r\033[38;5;22m✅  MAKE $(NAME)\033[0m\033[K 👍"
			@echo "🖕 🔞 💻"

%.o:		$(CPATH)%.c
			@$(CC) $(CFLAGS) -c $< 

clean:
			@$(RM) $(OBJS)
			@echo -en "\r\033[38;5;124m❌  CLEAN $(NAME) \033[0m\033[K 💣"

fclean:		clean
			@$(RM) $(NAME)
			@echo -en "\r\033[38;5;124m❌  FCLEAN $(NAME) \033[0m\033[K ⛔"

re:			fclean all
