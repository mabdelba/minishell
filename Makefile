# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelabid <aelabid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/18 00:21:19 by aelabid           #+#    #+#              #
#    Updated: 2022/06/05 21:56:58 by aelabid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# SRCS = ./parsing/main.c ./parsing/collect_data.c ./parsing/ft_split.c ./parsing/ft_strjoin.c ./parsing/ft_substr.c ./parsing/print.c \
# 		./parsing/ft_lstnew.c ./parsing/ft_lstsize.c ./parsing/ft_lstlast.c ./parsing/ft_lstadd_back.c ./parsing/ft_strtrim.c \
# 		./parsing/ft_strchr.c ./parsing/ft_splitp.c ./parsing/ft_strdup.c ./parsing/redirections.c ./parsing/openfiles.c \
# 		./parsing/heredoc.c ./parsing/error.c ./parsing/strchr2.c ./parsing/ft_strjoinc.c ./parsing/ft_itoa.c ./parsing/ft_parsing.c \
# 		./Execution/checkfiles.c ./Execution/execbash.c ./Execution/execv.c \
# 		./Execution/get_path.c ./Execution/getfile.c ./Execution/heredoc.c \
# 		./Execution/strjoin.c ./Execution/utile.c ./Execution/rehdoc.c \
# 		./main/main2.c ./main/getoutfiles.c  ./main/utilmain.c ./main/getfiles.c \
# 		./main/isint.c \
# 		./builtins/echo.c ./builtins/cd.c ./builtins/env.c ./builtins/export.c \
# 		./builtins/pwd.c ./builtins/unset.c ./builtins/cpyenv.c
# OBJS = $(SRCS:.c=.o)

# CC = gcc
# FLAGS = 

# NAME = minishell

# %.o : %.c minishell.h
# 	$(CC) $(FLAGS)-c $<

# all : $(NAME)

# $(NAME) : $(OBJS)
# 	$(CC) $(FLAGS) -lreadline $(OBJS) -o $(NAME)
# clean :
# 	rm -f $(OBJS)

# fclean : clean
# 	rm -f $(NAME)

# re : fclean all 



NAME = minishell
RM = rm -rf
CC = gcc

FILES = ./parsing/main.c ./parsing/collect_data.c ./parsing/ft_split.c ./parsing/ft_strjoin.c ./parsing/ft_substr.c ./parsing/print.c \
		./parsing/ft_lstnew.c ./parsing/ft_lstsize.c ./parsing/ft_lstlast.c ./parsing/ft_lstadd_back.c ./parsing/ft_strtrim.c \
		./parsing/ft_strchr.c ./parsing/ft_splitp.c ./parsing/ft_strdup.c ./parsing/redirections.c ./parsing/openfiles.c \
		./parsing/heredoc.c ./parsing/error.c ./parsing/strchr2.c ./parsing/ft_strjoinc.c ./parsing/ft_itoa.c ./parsing/ft_parsing.c \
		./parsing/col_data_utils.c ./parsing/col_data_utils1.c ./parsing/finale_cmd.c ./parsing/variables.c  ./parsing/ft_splp_utils.c\
		./Execution/checkfiles.c ./Execution/normexecbash.c ./Execution/execv.c \
		./Execution/get_path.c ./Execution/getfile.c ./Execution/heredoc.c \
		./Execution/strjoin.c ./Execution/utile.c ./Execution/execbash.c \
		./main/main2.c  ./main/utilmain.c  \
		./main/isint.c \
		./builtins/echo.c ./builtins/cd.c ./builtins/env.c ./builtins/export.c \
		./builtins/pwd.c ./builtins/unset.c ./builtins/cpyenv.c
		
OBJS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -L$(shell brew --prefix readline)/lib -lreadline -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I$(shell brew --prefix readline)/include -c $< -o $@

update:
	$(shell cd ~/goinfre && brew update)

install:
	$(shell cd ~/goinfre && brew install readline)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all