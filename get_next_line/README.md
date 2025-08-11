# get_next_line

A foundational project from the **1337/42 school curriculum**.  
This repository contains a custom C function, **`get_next_line`**, designed to read a line from a file descriptor, regardless of the buffer size.

[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/license/mit/)
[![Language](https://img.shields.io/badge/Language-C-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)


## 📜 Table of Contents

- [Project Description](#Project-description)
- [Functions](#Functions)
- [Installation](#Installation)
- [Usage](#Usage)
- [Author](#Author)
- [Acknowledgements](#Acknowledgements)

---

## Project Description
The **get_next_line** project challenges students to write a function that can read a single line from a file.  
The function must be able to handle a variety of situations, including:

- Reading from any valid file descriptor.  
- Handling files that do not end with a newline character.  
- Managing large files efficiently by handling reads of different sizes.  
- Correctly using static variables to remember the remaining data from previous calls.  

This project is crucial for developing a strong understanding of file I/O operations, memory allocation, and the management of static variables in C.

---

## Functions

The `get_next_line` function in this library:

- Reads a single line from a file, ending with a newline (`\n`) or the end of the file (EOF).  
- Returns the read line. The caller is responsible for freeing the memory.  
- Returns `NULL` on an error or at the end of the file.  
- Can handle multiple file descriptors simultaneously without losing its state.  

---

## Installation

To compile and use the **get_next_line** library:

```bash
# Clone the repository
git clone https://github.com/achahid19/1337_projects.git

# Navigate into the get_next_line directory
cd 1337_projects/get_next_line

```

## Usage

To use `get_next_line` in your own C project, compile your source files and link them with the static library:

```bash
gcc your_program.c get_next_line.c -o your_program -I/path/to get_next_line/includes
```
You can call the `get_next_line` function in your code as follows:

```c
#include "get_next_line.h"
#include <stdio.h>

int main() {
	int fd = open("example.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL) {
		printf("%s", line);
		free(line); // Free the memory allocated for the line
	}

	close(fd);
	return 0;
}
```

## Author
**© Anas Chahid ksabi **@KsDev**** - [achahid19](https://github.com/achahid19)

## Acknowledgements
This project is part of the **1337/42 school curriculum**.

[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
