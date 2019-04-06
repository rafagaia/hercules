# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    birds.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 22:22:28 by rgaia             #+#    #+#              #
#    Updated: 2019/04/05 23:38:55 by rgaia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
""" Sudo-Script:

-	create ".gitignore" file
        -	write to ".gitignore" file: (one) thing to ignore
-	create "Makefile" file
-	take in Language of Choice as Parameter (C)
        -	write to "Makefile" a template format for General Makefiles in a
                standard (C) Project"""
import  os
import  sys

def createSrc(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
    except OSError:
        print ('Error: Creating directory. ' +  directory)

argv = sys.argv
len_argv = len(argv)
if (len_argv < 2 or len_argv > 3):
    with open("USAGE_HELP.txt", "r") as file:
        print (file.read())
    sys.exit()

if (argv[1] != "C"):
    with open("USAGE_HELP.txt", "r") as file:
        print (file.read())
    sys.exit()

if (len_argv == 3):
    if ((argv[2] != "y" and argv[2] != "yes" and argv[2] != "no")):
        with open("USAGE_HELP.txt", "r") as file:
            print (file.read())
        sys.exit()
    if (argv[2] == "y" or argv[2] == "yes"):
        createSrc('./src/')
        file_src_lib = open("./src/lib", "a+")
        
file_Makefile = open("Makefile", "a+")
file_gitignore = open(".gitignore", "a+")
format_Makefile = """NAME = [name].a

SRC =   [src/*]

OFILES = $(SRC:.c=.o)

FLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(SRC)
		@ar -rcs $(NAME) $(OFILES)

clean:
		@rm -rf $(OFILES)

fclean: clean
		@rm -rf $(NAME)

re: fclean
	        @make
"""

if (os.stat("Makefile").st_size == 0):
    file_Makefile.write(format_Makefile)
