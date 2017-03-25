NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES_FLD_1 = src

INCLUDES_FLD_1 = include

OBJECTS_FLD = obj

PRINTF = printf/libftprintf.a

PRINTF_FLD = printf

OBJECTS_1 =\
	$(OBJECTS_FLD)/ft_list.o\
	$(OBJECTS_FLD)/ft_list_2.o\
	$(OBJECTS_FLD)/ft_errors.o\
	$(OBJECTS_FLD)/ft_read.o\
	$(OBJECTS_FLD)/fork.o\
	$(OBJECTS_FLD)/ft_echo.o\
	$(OBJECTS_FLD)/ft_cd.o\
	$(OBJECTS_FLD)/ft_work_with_command_line.o\
	$(OBJECTS_FLD)/ft_push_back.o\
	$(OBJECTS_FLD)/ft_handle_commands.o\
	$(OBJECTS_FLD)/ft_double_array.o\
	$(OBJECTS_FLD)/main.o


INCLUDES_1 =\
	$(INCLUDES_FLD_1)/minishell.h


all : $(NAME)

$(NAME) : $(PRINTF) $(OBJECTS_1) $(INCLUDES_1)
	$(CC) -I $(INCLUDES_FLD_1) $(PRINTF) $(CFLAGS) $(OBJECTS_1) -o $(NAME)

debug :
	$(CC) -I $(INCLUDES_FLD_1) -I $(PRINTF_FLD)/include $(CFLAGS) -g $(SOURCES_FLD_1)/*.c $(PRINTF_FLD)/src/*.c $(PRINTF_FLD)/src_print/*.c -o $(NAME)_deb

clean :
	rm -r $(OBJECTS_FLD)

fclean : clean
	rm -f $(NAME)
	make fclean -C $(PRINTF_FLD)

re : fclean all

dclean :
	rm -rf $(NAME)_deb*

dre : dclean debug

$(OBJECTS_FLD)/ft_list.o : $(SOURCES_FLD_1)/ft_list.c $(HEADERS_1)
	@mkdir -p $(OBJECTS_FLD)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_list.c -o $(OBJECTS_FLD)/ft_list.o

$(OBJECTS_FLD)/ft_list_2.o : $(SOURCES_FLD_1)/ft_list_2.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_list_2.c -o $(OBJECTS_FLD)/ft_list_2.o

$(OBJECTS_FLD)/main.o : $(SOURCES_FLD_1)/main.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/main.c -o $(OBJECTS_FLD)/main.o

$(OBJECTS_FLD)/ft_errors.o : $(SOURCES_FLD_1)/ft_errors.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_errors.c -o $(OBJECTS_FLD)/ft_errors.o

$(OBJECTS_FLD)/ft_read.o : $(SOURCES_FLD_1)/ft_read.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_read.c -o $(OBJECTS_FLD)/ft_read.o

$(OBJECTS_FLD)/fork.o : $(SOURCES_FLD_1)/fork.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/fork.c -o $(OBJECTS_FLD)/fork.o

$(OBJECTS_FLD)/ft_echo.o : $(SOURCES_FLD_1)/ft_echo.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_echo.c -o $(OBJECTS_FLD)/ft_echo.o

$(OBJECTS_FLD)/ft_cd.o : $(SOURCES_FLD_1)/ft_cd.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_cd.c -o $(OBJECTS_FLD)/ft_cd.o

$(OBJECTS_FLD)/ft_push_back.o : $(SOURCES_FLD_1)/ft_push_back.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_push_back.c -o $(OBJECTS_FLD)/ft_push_back.o

$(OBJECTS_FLD)/ft_work_with_command_line.o : $(SOURCES_FLD_1)/ft_work_with_command_line.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_work_with_command_line.c -o $(OBJECTS_FLD)/ft_work_with_command_line.o

$(OBJECTS_FLD)/ft_handle_commands.o : $(SOURCES_FLD_1)/ft_handle_commands.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_handle_commands.c -o $(OBJECTS_FLD)/ft_handle_commands.o

$(OBJECTS_FLD)/ft_double_array.o : $(SOURCES_FLD_1)/ft_double_array.c $(HEADERS_1)
	$(CC) -I $(INCLUDES_FLD_1) $(CFLAGS) -c $(SOURCES_FLD_1)/ft_double_array.c -o $(OBJECTS_FLD)/ft_double_array.o

$(PRINTF) :
	make -C $(PRINTF_FLD)
