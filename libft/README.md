# Libft

A custom C library created as part of the **1337/42 school curriculum**.  
The `libft` project is designed to build a foundational understanding of C programming by re-implementing a number of standard C library functions and creating new ones. This library serves as a cornerstone for future projects at the school.

[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/license/mit/)
[![Language](https://img.shields.io/badge/Language-C-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)

![Note](https://img.shields.io/badge/Note-This%20project%20is%20part%20of%20the%201337%20school%20curriculum-blueviolet.svg)


---

## 📜 Table of Contents

- [Project Description](#Project-description)
- [Functions](#Functions)
- [Installation](#Installation)
- [Usage](#Usage)
- [Author](#Author)
- [Acknowledgements](#Acknowledgements)

---

## Project Description
This repository contains a personal C library, **Libft**, which includes a collection of functions that are essential for handling strings, memory, and character manipulation.  
The functions are reimplemented from the standard C library as well as a new set of utility functions created for the project.

---

## Functions

### **Part 1: Standard C Library Functions**
- `ft_memset` – Fills memory with a constant byte.  
- `ft_bzero` – Writes n zeroed bytes to the string `s`.  
- `ft_memcpy` – Copies memory area.  
- `ft_memccpy` – Copies memory until a character is found.  
- `ft_memmove` – Copies memory area, safely handling overlapping memory.  
- `ft_memchr` – Searches for the first occurrence of a character in a memory area.  
- `ft_memcmp` – Compares memory areas.  
- `ft_strlen` – Calculates the length of a string.  
- `ft_isalpha` – Checks for an alphabetic character.  
- `ft_isdigit` – Checks for a digit (0–9).  
- `ft_isalnum` – Checks for an alphanumeric character.  
- `ft_isascii` – Checks whether a character is an ASCII character.  
- `ft_isprint` – Checks for a printable character.  
- `ft_toupper` – Converts a lowercase letter to uppercase.  
- `ft_tolower` – Converts an uppercase letter to lowercase.  
- `ft_strchr` – Locates the first occurrence of a character in a string.  
- `ft_strrchr` – Locates the last occurrence of a character in a string.  
- `ft_strncmp` – Compares two strings up to a specified number of characters.  
- `ft_strlcpy` – Copies a string to a buffer with a given size.  
- `ft_strlcat` – Concatenates a string to a buffer with a given size.  
- `ft_strnstr` – Locates a substring in a string, searching up to a given number of characters.  
- `ft_atoi` – Converts a string to an integer.  
- `ft_calloc` – Allocates memory and initializes it to zero.  
- `ft_strdup` – Duplicates a string.  

### **Part 2: Additional Functions**
- `ft_substr` – Extracts a substring from a string.  
- `ft_strjoin` – Joins two strings into a new one.  
- `ft_strtrim` – Removes characters from the beginning and end of a string.  
- `ft_split` – Splits a string by a delimiter into an array of strings.  
- `ft_itoa` – Converts an integer to a string.  
- `ft_strmapi` – Applies a function to each character of a string to create a new string.  
- `ft_striteri` – Applies a function to each character of a string.  
- `ft_putchar_fd` – Writes a character to a file descriptor.  
- `ft_putstr_fd` – Writes a string to a file descriptor.  
- `ft_putendl_fd` – Writes a string to a file descriptor, followed by a newline.  
- `ft_putnbr_fd` – Writes an integer to a file descriptor.  

### **Bonus Part: Linked List Functions**
- `ft_lstnew` – Creates a new list element.  
- `ft_lstadd_front` – Adds a new element at the beginning of a list.  
- `ft_lstsize` – Counts the number of elements in a list.  
- `ft_lstlast` – Returns the last element of a list.  
- `ft_lstadd_back` – Adds a new element at the end of a list.  
- `ft_lstdelone` – Deletes one element.  
- `ft_lstclear` – Deletes and frees all elements from a list.  
- `ft_lstiter` – Applies a function to each element's content.  
- `ft_lstmap` – Applies a function to each element's content to create a new list.  

---

## Installation

To compile and use the **libft** library:

```bash
# Clone the repository
git clone https://github.com/achahid19/1337_projects.git

# Navigate into the libft directory
cd 1337_projects/libft

# Compile the library
make
```

## Usage

To use libft in your own C project, compile your source files and link them with the static library:
```bash
gcc your_program.c -L. -lft -I. -o your_program
```
Flags explained:
- `-L.`: Tells the compiler to look for libraries in the current directory.
- `-lft`: Links against the `libft` library.
- `-I.`: Includes the current directory for header files.

## Author
- **Achahid** - [achahid19](https://github.com/achahid19)

## Acknowledgements
This project is part of the **1337/42 school curriculum**.
 
[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
