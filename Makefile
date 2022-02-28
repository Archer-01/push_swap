# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
OBJS_DIR		:= obj
LIBS_DIR		:= lib
LIBFT_DIR		:= $(LIBS_DIR)/libft

# *********************************** Files ************************************
NAME			:= push_swap
BONUS_NAME		:= checker
SRCS			:= ft_apply_move.c \
					ft_atol.c \
					ft_calculate_moves.c \
					ft_check_args.c \
					ft_clear_args.c \
					ft_find_best_move.c \
					ft_get_args.c \
					ft_lis.c \
					ft_lis_lengths.c \
					ft_lis_subsequence.c \
					ft_optimize_move.c \
					ft_parser.c \
					ft_place_smallest_num_first.c \
					ft_push_to_stack_a.c \
					ft_push_to_stack_b.c \
					ft_rotate_stack_a.c \
					ft_run.c \
					ft_sort.c \
					ft_stack_clear.c \
					ft_stack_duplicate.c \
					ft_stack_get_frame_by_index.c \
					ft_stack_get_index_by_value.c \
					ft_stack_get_num_by_index.c \
					ft_stack_get_proper_index.c \
					ft_stack_get_smallest_num_index.c \
					ft_stack_is_sorted.c \
					ft_stack_new.c \
					ft_stack_pop.c \
					ft_stack_push.c \
					ft_utils.c \
					ps_push.c \
					ps_rev_rotate.c \
					ps_rotate.c \
					ps_swap.c
OBJS			:= $(SRCS:.c=.o)
HEADERS			:= ft_parser.h \
					ft_stack.h \
					ft_utils.h \
					push_swap.h \
					push_swap_operations.h
BONUS_SRCS		:= ft_atol.c \
					ft_check_args.c \
					ft_clear_args.c \
					ft_get_args.c \
					ft_parser.c \
					ft_stack_clear.c \
					ft_stack_new.c \
					ft_stack_push.c
BONUS_OBJS		:= $(BONUS_SRCS:.c=.o)
LIBFT			:= libft.a
LIBFT_SRCS		:= ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_doublelst_addback.c \
					ft_doublelst_addfront.c \
					ft_doublelst_clear.c \
					ft_doublelst_delone.c \
					ft_doublelst_iter.c \
					ft_doublelst_last.c \
					ft_doublelst_map.c \
					ft_doublelst_new.c \
					ft_doublelst_size.c \
					ft_isalnum.c \
					ft_isalpha.c \
					ft_isascii.c \
					ft_isdigit.c \
					ft_isprint.c \
					ft_itoa.c \
					ft_lstadd_back.c \
					ft_lstadd_front.c \
					ft_lstclear.c \
					ft_lstdelone.c \
					ft_lstiter.c \
					ft_lstlast.c \
					ft_lstmap.c \
					ft_lstnew.c \
					ft_lstsize.c \
					ft_memchr.c \
					ft_memcmp.c \
					ft_memcpy.c \
					ft_memmove.c \
					ft_memset.c \
					ft_printf.c \
					ft_putaddr_hex.c \
					ft_putchar.c \
					ft_putchar_fd.c \
					ft_putendl_fd.c \
					ft_putnbr.c \
					ft_putnbr_fd.c \
					ft_putnbr_hex.c \
					ft_putnbr_unsigned.c \
					ft_putstr.c \
					ft_putstr_fd.c \
					ft_split.c \
					ft_strchr.c \
					ft_strcmp.c \
					ft_strdup.c \
					ft_striteri.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_strmapi.c \
					ft_strncmp.c \
					ft_strnstr.c \
					ft_strrchr.c \
					ft_strtrim.c \
					ft_substr.c \
					ft_tolower.c \
					ft_toupper.c \
					get_next_line.c
LIBFT_HEADER	:= libft.h
MAIN			:= main.c
BONUS_MAIN		:= checker.c

# ****************************** Compiler options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
INCLUDES	:= -I $(INCLUDES_DIR) -I $(LIBFT_DIR)/include
LIBS		:= -L $(LIBFT_DIR) -lft

# ******************************* Other commands *******************************
RM		:= rm -rf
MKDIR	:= mkdir -p

# ********************************** Targets ***********************************
all:	$(NAME)

$(NAME):	$(addprefix $(OBJS_DIR)/, $(OBJS)) $(LIBFT_DIR)/$(LIBFT) $(MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(addprefix $(OBJS_DIR)/, $(OBJS)) $(LIBS) \
		$(MAIN) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(addprefix $(OBJS_DIR)/, $(BONUS_OBJS)) $(LIBFT_DIR)/$(LIBFT) \
				$(BONUS_MAIN)
	$(CC) $(CFLAGS) $(INCLUDES) $(addprefix $(OBJS_DIR)/, $(BONUS_OBJS)) \
		$(LIBS) $(BONUS_MAIN) -o $(BONUS_NAME)

$(LIBFT_DIR)/$(LIBFT): $(LIBFT_DIR)/include/$(LIBFT_HEADER) \
						$(addprefix $(LIBS_DIR)/libft/src/, $(LIBFT_SRCS))
	make -C $(LIBFT_DIR)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) \
					$(LIBFT_DIR/include/$(LIBFT_HEADER)
		@$(MKDIR) $(OBJS_DIR)
		$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR) $(LIBFT)

fclean:	clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS_NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus