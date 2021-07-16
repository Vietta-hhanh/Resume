#/bin/bash
#Entrance function int get_next_line(int fd, char **line) must be executed from main.
#Function accepted descriptor of the file and null-equal massive of strings.
#When string was successfully read, returned value is 1, whenever file is done - 0.

gcc main.c ../get_next_line.c ../get_next_line_utils.c && ./a.out
rm ./a.out