# Program name
NAME = libft.a

# Libc source files
LIBC_PART1 = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
				ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_strnstr.c ft_memcmp.c ft_atoi.c ft_calloc.c ft_strdup.c

# Additional source files
ADDITIONAL_PART2 = 	ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
					ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c 

# Bonus source files
BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c ft_lstmap.c

# Assign the sources of Part1 with the sources of Part2
SRC = ${LIBC_PART1} ${ADDITIONAL_PART2}

# Use same files from sources, but change .c to .o
OBJECTS = ${SRC:.c=.o}

# Use same files from bonus, but change .c to .o
BONUS_OBJECTS = ${BONUS:.c=.o}

# Specify the name of the header file needed by the program
HEADER = libft.h

# Tell the compiler to search the current directory for header files
# "." represents the current directory
INCLUDE = -I .

# Execute the default C compiler on the system, GNU C Compiler (GCC)
CC = cc

# Remove files or directories from the file system
# "-f" is used to force the removal of files without prompting for confirmation
# "@" supress commands to show in terminal
RM = @rm -f

# Specifies the compiler flags that should be used when building the program
CFLAGS = -Wall -Wextra -Werror

# Default command to compile
all: $(NAME)

# Compile files following above rules 
# "@ar rcs ${NAME} ${OBJECTS}" creates an archive (a static library) named "${NAME}" 
# by concatenating the object files specified by "${OBJECTS}" using the "ar" command
# The "r" flag tells "ar" to replace any existing file with the same name, 
# the "c" flag tells it to create the archive if it doesn't already exist, and 
# the "s" flag tells it to write an index to the archive
# "@echo .." print a message to the console when a rule is executed
$(NAME): ${OBJECTS} 
		@ar rcs ${NAME} ${OBJECTS}
		@echo "\n${NAME} created"

# Compile bonus following above rules 
bonus: ${OBJECTS} ${BONUS_OBJECTS}
		@ar rcs ${NAME} ${OBJECTS} ${BONUS_OBJECTS}
		@echo "\n$@ created"

# "-c $< -o" compiles the C source file specified by "$<" 
# into an object file with the same name, but with a .o extension
# "${<:.c=.o}" is to replaces the ".c" extension of the input file with ".o", 
# in order to generate the name of the output file
%.o: %.c   
	@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o} 
	@echo "\n$@ created"

# Clean .o files (Object files)
clean:
	@$(RM) $(OBJECTS) ${BONUS_OBJECTS}
	@echo "\nObjects deleted"

# Same as "clean" rule but with an additional step to remove the executable file, 
# referred to as $(NAME)
fclean: clean
	@$(RM) $(NAME)
	@echo "\n${NAME} deleted"

# Rebuild the project from scratch, removing any old files and ensuring 
# that all dependencies are up-to-date.
# "fclean" rule removes all object files and the final executable file. 
# "all" rule rebuilds the project from scratch, generating new object files and a new executable file.
re: fclean all

# Avoid potential conflicts with files that have the same names as the targets
.PHONY: all clean fclean re