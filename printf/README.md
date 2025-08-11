# ft_printf

A project for the 1337/42 school curriculum, this repository contains a custom re-implementation of the standard C library's printf function. The goal is to build a function capable of handling a variable number of arguments and printing formatted output to the console.

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
The **ft_printf** project involves creating a function that replicates the behavior of the **printf** function from the standard C library. This includes correctly parsing a format string and printing corresponding arguments based on specified format specifiers. This project is a key step in understanding variadic functions and memory management in C.

---

## Functions

My ft_printf function supports the following format specifiers:

- **%c**: Prints a single character.

- **%s**: Prints a string.

- **%p**: Prints a pointer address in hexadecimal format.
- **%d**: Prints a signed decimal integer.

- **%i**: Prints a signed integer (same as %d).

- **%u**: Prints an unsigned decimal integer.

- **%x**: Prints a hexadecimal integer in lowercase.

- **%X**: Prints a hexadecimal integer in uppercase.

- **%%**: Prints a literal percent sign.
---

## Installation

To use the **ft_printf** library, clone the repository and compile the source files to create a static library:

```bash
git clone

cd 1337_projects/ft_printf

make
```

This will create **libftprintf.a**, a static library file.

## Usage

To use the **ft_printf** function in your C programs, include the header file and link against the static library:

```c
#include "ft_printf.h"

int main() {
	ft_printf("Hello, %s! Your score is %d.\n", "World", 42);
	return 0;
}
```
Make sure to link against the library when compiling your program:

```bash
gcc -o my_program my_program.c -L. -I. -lftprintf
```
options explained:
- `-L.`: Tells the compiler to look for libraries in the current directory.
- `-lftprintf`: Links against the **libftprintf.a** library.
- `-I.`: Tells the compiler to look for header files in the current directory.

## Author
**© Anas Chahid ksabi **@KsDev**** - [achahid19](https://github.com/achahid19)

## Acknowledgements
This project is part of the **1337/42 school curriculum**.

[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
