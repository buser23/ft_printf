# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bsalgado <bsalgado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 00:45:26 by bsalgado          #+#    #+#              #
#    Updated: 2023/10/15 23:37:38 by bsalgado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = libftprintf.a

# Execute the default C compiler on the system, GNU C Compiler (GCC)
CC = cc

# Specifies the compiler flags that should be used when building the program
CFLAGS = -Wall -Werror -Wextra

# Define the archiver command
# ar rcs is a set of options and arguments that tells the ar command to 
# create a static library (archive) and to perform various operations 
# like replacing or adding object files to the archive.
AR = ar rcs

# Remove files or directories from the file system
# "-f" is used to force the removal of files without prompting for confirmation
RM = rm -f

# Tell the compiler to search the current directory for header files
# "." represents the current directory
HDR = -I.

# Define color codes
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Sources to objects

# List of source file names without the .c extension
SRC_FILES = ft_printf print_chr print_str print_nbr print_hex print_unsigned print_pointer ft_intlen ft_puthex_fd ft_itoapositive

# Generate source file names with .c extension
SRC = $(addsuffix .c, $(SRC_FILES))

# Generate object file names with .o extension
OBJ = $(addsuffix .o, $(SRC_FILES))

# Compile files following above rules 
$(NAME) : $(OBJ)

  # Run make in the libft directory, which indicates that you 
  # are building or compiling a library located in the libft directory
	@ make -C libft
	
  # Print a message to the console with the color code set to green, 
  # indicating that the libft.a library was successfully built. 
  # The DEF_COLOR variable is used to reset the color to the default color
	@ echo "$(GREEN)Made libft.a with sucess$(DEF_COLOR)"

  # Copy the libft.a file from the libft directory to the current directory
	@ cp libft/libft.a .

  # Print a success message in green indicating that the libft.a 
  # file was copied successfully.
	@ echo "$(GREEN)Copied libft.a with sucess$(DEF_COLOR)"

  # Rename the libft.a file to the value of the $(NAME) variable
	@ mv libft.a $(NAME)

  # Print a success message indicating that the library was 
  # renamed as libftprintf.a.
	@ echo "$(GREEN)Renamed libft.a to libftprintf.a$(DEF_COLOR)"

  # Use the $(AR) variable to create or update a library named $(NAME) 
  # with the object files specified in $(OBJ)
	@ $(AR) $(NAME) $(OBJ)

  # Print a message in green indicating that the libftprintf.a 
  # library was successfully updated
	@ echo "$(GREEN)Updated libftprintf.a$(DEF_COLOR)"

  # Print a message in blue indicating that the library 
  # was compiled successfully
	@ echo "$(BLUE)Compiled libftprintf.a with sucess!$(DEF_COLOR)"

# Rule to compile source files into object files
# The % symbol is a wildcard character in a pattern rule and represents 
# a pattern match for any string.
# In this specific rule, it means that for any .c source file (%.c), you can generate 
# a corresponding .o object file (%.o) by applying the specified command
%.o : %.c
  # Print a message to the console indicating that a source file is 
  # being compiled. 
  # The $< variable represents the name of the source file being compiled, 
  # and it's printed in yellow. 
  # The DEF_COLOR variable is used to reset the color to the default color
	@ echo "$(YELLOW)Compiling: $<$(DEF_COLOR)"

  # Run the C compiler ($(CC)) to compile the source file ($<) into an object file ($@). 
  # It includes the specified compiler flags ($(CFLAGS)) and include directories ($(HDR))
	@ $(CC) $(CFLAGS) $(HDR) -c $< -o $@

  # Print a success message in green indicating that the 
  # object file was created successfully
	@ echo "$(GREEN)Object files created with sucess$(DEF_COLOR)"

# Default command to compile
all : $(NAME)

# Clean .o files (Object files)
clean :
  # Use the $(RM) variable to remove the object files specified in $(OBJ). 
  # -r option removes directories and their contents, and the 
  # -f option forces the removal without prompting for confirmation
	@ $(RM) -rf $(OBJ)
	
  # Print a message in red indicating that the printf object files have been removed
	@ echo "$(RED)Removed printf object files$(DEF_COLOR)"

  # Run make clean in the libft directory to clean up object files within the libft library
	@ make clean -C libft

  # Print a message in red indicating that the libft object files have been removed
	@ echo "$(RED)Removed libft object files$(DEF_COLOR)"

# Same as "clean" rule but with an additional step to remove the executable file
fclean : clean

  # Use the $(RM) variable to remove the target file specified in $(NAME), 
  # which is 'libftprintf.a.' 
  # This step effectively removes the final output of your project
	@ $(RM) $(NAME)

  # Print a message in red indicating that 'libftprintf.a' has been removed
	@ echo "$(RED)Removed 'libftprintf.a' with sucess$(DEF_COLOR)"

  # Remove a library file ('libft.a') located in the libft subdirectory. 
  # It's assumed that libft is a separate library or dependency
	@ $(RM) libft/libft.a

  # Print a message in red indicating that 'libft.a' has been removed
	@ echo "$(RED)Removed 'libft.a' with sucess$(DEF_COLOR)"

# Bonus features that depend on the main program
# Build the bonus features and everything that's part of the default build
bonus: all

# Rebuild the project from scratch, removing any old files and ensuring 
# that all dependencies are up-to-date.
# "fclean" rule removes all object files and the final executable file. 
# "all" rule rebuilds the project from scratch, generating new object files and a new executable file
re : fclean all

# Perform tests or run the program to check its behavior. 
# Compile the main.c source file into an object file, linking it with libftprintf.a library, 
# and then running the resulting executable named output
test : all

  # Compile the main.c source file into an object file named main.o. 
  # It uses the C compiler ($(CC)), specified compiler flags ($(CFLAGS)), and any include 
  # directories specified in $(HDR)
	@$(CC) $(CFLAGS) $(HDR) -c main.c -o main.o

  # Link the main.o object file with the libftprintf.a library. It creates an executable named output. 
  # -L. flag: indicates to search for the library in the current directory
  # -lftprintf flag: specifies the library to link against
	@$(CC) $(CFLAGS) -o output main.o -L. -lftprintf

  # Print a message in cyan indicating that the output is going to be displayed
	@echo "$(CYAN)Output:$(DEF_COLOR)"

  # Run the output executable, which is the result of the compilation and linking steps. 
  # It executes your program and prints the output
	@./output

# Cleaning up test-related files and artifacts
tclean : fclean

  # Use the $(RM) variable to remove the output executable and the main.o object file, 
  # which are typically generated during the testing process
	@ $(RM) output main.o

  # Print a message in red to the console, indicating that the output and main.o 
  # files have been successfully removed
	@ echo "$(RED)Removed 'output' and 'main.o' with sucess$(DEF_COLOR)"

# Automate a series of Git commands and operations
git :

  # Clear the terminal screen, waits for 1 second, and then prints a message 
  # in red indicating the start of the cleaning process
	@ clear && sleep 1 && echo "$(RED)\n\n\n\nStart cleanning...\n\n" && sleep 1

  # Invoke the tclean rule, which cleans up test-related files and artifacts
	@ make tclean

  # Print a message in cyan indicating that everything is clean. 
  # It then prints "Git status" in green, followed by resetting the color to the default color
	@ echo "$(CYAN)\n\n\n\nEverything clean\n\n\n$(GREEN)Git status:\n\n$(DEF_COLOR)"

  # Run the git status command to show the Git status of the repository. 
  # It waits for 1 second and then prompts the user to press Enter to confirm the status
	@ git status && sleep 1 && echo "$(RED)Press Enter to confirm" && read enter

  # Reset the color to the default color and prints a message indicating that everything 
  # is about to be added to the Git repository
	@ echo "$(DEF_COLOR)\nGit add everything\n\n"

  # Adds all changes and files to the Git repository using git add ., and then it displays 
  # the Git status to show the changes that have been staged
	@ git add . && git status

  # Set the text color to yellow, prompts the user to enter a commit message and a commit comment, 
  # and then commits the changes to the repository using the provided message and comment
	@ echo "$(YELLOW)" && read -p "Enter commit message: " message && read -p "Enter commit comment: " comment && git commit -m "$message" -m "$comment"

  # Set the text color to gray and runs git push to push the committed changes to the remote repository
	@ echo "$(GRAY)" && git push

  # Set the text color to green and prints a message indicating that the Git push was successful
	@ echo "$(GREEN)\n\nGit push done with sucess\n\n$(DEF_COLOR)"

# Avoid potential conflicts with files that have the same names as the targets
.PHONY:		all clean fclean re