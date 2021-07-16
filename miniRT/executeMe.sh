#/bin/bash
make fclean
make
rm ./a.out
gcc -Lmlx -lmlx -framework OpenGL -framework AppKit main.c miniRT.a -o miniRT
make fclean
ECHO "HOW TO USE MY PROJECT? There is a executable file miniRT. It has only two different ways to be executed:\
in screenshot mode or in normal mode. ANYWAY FIRST ARGUMENT MUST BE ALWAYS EXISTING CONFIGURATION .RT FILE. Second \
argument might be represented only in that way '--save', either no how at all. Second argument determines mode, which will be activated.
Set of .RT files is stored in directory, named 'rt'."
ECHO "./miniRT [.RT file] [--save / or nothing], GOOD LUCK!"