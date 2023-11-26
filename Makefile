NAME			= minitalk

FLAGS			= -Wall -Wextra -Werror

COMPILE			= cc

COLOR_RESET		= \033[0m
COLOR_CYAN		= \033[36m
COLOR_GREEN		= \033[32m
COLOR_RED		= \033[31m

INCLUDE			= libft/

SRCS_FOLDER		= srcs/
SRCS_B_FOLDER	= srcs_bonus/

CLIENT_FOLDER	= client/
SERVER_FOLDER	= server/
HELPER_FOLDER	= helper/

SRCS_CLIENT		= client.c
SRCS_SERVER		= server.c
SRCS_HELPER		= ft_send_message.c ft_charjoin.c

SRCS_B_CLIENT	= client_bonus.c
SRCS_B_SERVER	= server_bonus.c
SRCS_B_HELPER	= ft_send_message_bonus.c ft_charjoin_bonus.c

OBJS_CLIENT		= $(addprefix $(SRCS_FOLDER),$(addprefix $(CLIENT_FOLDER),$(SRCS_CLIENT:%.c=%.o))) \
				  $(addprefix $(SRCS_FOLDER),$(addprefix $(HELPER_FOLDER),$(SRCS_HELPER:%.c=%.o)))

OBJS_SERVER		= $(addprefix $(SRCS_FOLDER),$(addprefix $(SERVER_FOLDER),$(SRCS_SERVER:%.c=%.o))) \
				  $(addprefix $(SRCS_FOLDER),$(addprefix $(HELPER_FOLDER),$(SRCS_HELPER:%.c=%.o)))

OBJS_B_CLIENT	= $(addprefix $(SRCS_B_FOLDER),$(addprefix $(CLIENT_FOLDER),$(SRCS_B_CLIENT:%.c=%.o))) \
				  $(addprefix $(SRCS_B_FOLDER),$(addprefix $(HELPER_FOLDER),$(SRCS_B_HELPER:%.c=%.o)))

OBJS_B_SERVER	= $(addprefix $(SRCS_B_FOLDER),$(addprefix $(SERVER_FOLDER),$(SRCS_B_SERVER:%.c=%.o))) \
				  $(addprefix $(SRCS_B_FOLDER),$(addprefix $(HELPER_FOLDER),$(SRCS_B_HELPER:%.c=%.o)))

all:			$(NAME)

$(NAME):		client server

client:			$(OBJS_CLIENT)
				@cd $(INCLUDE) && make
				@$(COMPILE) $(FLAGS) -o client $(OBJS_CLIENT) -L$(INCLUDE) -lft
				@echo "$(COLOR_CYAN)Kompilierung abgeschlossen: client$(COLOR_RESET)"

server:			$(OBJS_SERVER)
				@cd $(INCLUDE) && make
				@$(COMPILE) $(FLAGS) -o server $(OBJS_SERVER) -L$(INCLUDE) -lft
				@echo "$(COLOR_CYAN)Kompilierung abgeschlossen: server$(COLOR_RESET)"

client_b:		$(OBJS_B_CLIENT)
				@cd $(INCLUDE) && make
				@$(COMPILE) $(FLAGS) -o client $(OBJS_B_CLIENT) -L$(INCLUDE) -lft
				@echo "$(COLOR_CYAN)Kompilierung abgeschlossen: client$(COLOR_RESET)"

server_b:		$(OBJS_B_SERVER)
				@cd $(INCLUDE) && make
				@$(COMPILE) $(FLAGS) -o server $(OBJS_B_SERVER) -L$(INCLUDE) -lft
				@echo "$(COLOR_CYAN)Kompilierung abgeschlossen: server$(COLOR_RESET)"

clean:
				@echo "$(COLOR_RED)Cleanup $(NAME)$(COLOR_RESET)"
				@rm -rf $(OBJS_CLIENT)
				@rm -rf $(OBJS_SERVER)
				@rm -rf $(OBJS_B_CLIENT)
				@rm -rf $(OBJS_B_SERVER)
				@echo "$(COLOR_RED)Cleanup Libft.$(COLOR_RESET)"
				@cd $(INCLUDE) && make clean
				@echo "$(COLOR_GREEN)Cleanup completed.$(COLOR_RESET)"

fclean:			clean
				@echo "$(COLOR_RED)Removal $(NAME)$(COLOR_RESET)"
				@rm -f client server
				@echo "$(COLOR_RED)Removal Libft.$(COLOR_RESET)"
				@cd $(INCLUDE) && make fclean
				@echo "$(COLOR_GREEN)Removal completed.$(COLOR_RESET)"

bonus:			client_b server_b

re: 			fclean all
