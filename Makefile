NAME = result

CC = cc

FLAG = -Wall -Wextra -Werror -D BUFFER_SIZE=1024

FILE = get_next_line.c get_next_line_utils.c get_next_line.h main.c

FILE_BONUS = get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line.h main.c

$(NAME) :
	$(CC) $(FLAG) $(FILE) -o $@

bonus :
	$(CC) $(FLAG) $(FILE_BONUS)

fclean :
	rm -rf *.gch *.out

.PHONY: fclean bonus