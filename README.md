# GET_NEXT_LINE_FD

📘 Get Next Line (GNL)

📝 Description

The Get Next Line (GNL) project is a function that reads a line from a file descriptor and returns it. This project is part of the curriculum of the 42 School and aims to strengthen understanding of low-level file operations, memory allocation, and buffer management in C.

This function is useful for reading files line-by-line, making it a core utility in many applications such as log readers, parsers, and shell implementations.

🚀 Features

Line-by-line reading from files, standard input (stdin), or other file descriptors.

Handles multiple file descriptors simultaneously.

Manages dynamic memory allocation and guarantees no memory leaks.

Customizable buffer size for optimal performance.

📂 Project Structure

📁 gnl_project
├── 📄 get_next_line.c     // Main GNL function logic
├── 📄 get_next_line.h     // Header file (function prototypes and includes)
├── 📄 get_next_line_utils.c // Utility functions (memory management, string handling, etc.)
├── 📄 main.c             // Optional test file for debugging (not part of the final submission)
└── 📄 Makefile          // Compilation script

⚙️ How It Works

Reads a line from a given file descriptor (fd) using a buffer of predefined size (BUFFER_SIZE).

Stores the read content in static memory so it can persist between function calls.

Returns a full line once the newline character (\n) is encountered or EOF (end-of-file) is reached.

💻 Usage

Compilation

To compile the files and generate an executable, use the Makefile:

make

This will generate the object files (.o) and the necessary binary for testing.

To clean up object files and other temporary files, use:

make clean

To clean up all files (object files and executable), use:

make fclean

To recompile from scratch, use:

make re

Function Prototype

char *get_next_line(int fd);

Example Usage

Here is an example of how you might use get_next_line in a simple program:

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void) {
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return (1);
    }
    
    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}

🛠️ Functions Overview

get_next_line.c

get_next_line(int fd): The main function that reads a line from the file descriptor.

get_next_line_utils.c

ft_strjoin(): Joins two strings into one.

ft_strdup(): Duplicates a string.

ft_strchr(): Locates a character in a string.

ft_strlen(): Computes the length of a string.

📚 Requirements

The code must compile with gcc using the following flags:

gcc -Wall -Werror -Wextra -D BUFFER_SIZE=42

BUFFER_SIZE can be set to any positive number and determines how many bytes are read at a time.

The project should not use standard library functions (like malloc, free, read, write) except the allowed functions.

✅ Evaluation Criteria

Memory leaks: No leaks allowed (use tools like valgrind to check for memory leaks).

Multiple file descriptors: Must handle reading from multiple files simultaneously.

Code readability: Follow the norminette style guide (if part of the 42 curriculum).

📦 Tests

To test the GNL function, you can create files with multiple lines and use the following approach:

1. Test with a file input

./your_program_name test.txt

2. Test with standard input (stdin)

./your_program_name
hello
world
<Ctrl+D> # To simulate EOF

3. Use valgrind to check for memory leaks

valgrind --leak-check=full ./your_program_name test.txt

🤝 Contributing

If you'd like to contribute to this project, feel free to submit a pull request. Please ensure your code follows the 42 norminette and has no memory leaks.

📜 License

This project is open-source and available under the MIT License. Feel free to use, modify, and distribute it.
