# pipex

A project from the **1337/42 school curriculum**.  
This program is a recreation of the shell's piping mechanism, which allows two commands to be executed sequentially, where the output of the first command becomes the input of the second.


[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/license/mit/)
[![Language](https://img.shields.io/badge/Language-C-orange.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
![Status](https://img.shields.io/badge/Status-Completed-brightgreen.svg)


## 📜 Table of Contents

- [Project Description](#Project-description)
- [Features](#Features)
- [Installation](#Installation)
- [Usage](#Usage)
- [Author](#Author)
- [Acknowledgements](#Acknowledgements)

---

## Project Description
The **pipex** project is designed to help students understand the concepts of **inter-process communication (IPC)** and **process management** in C.  

The program:
- Takes an input file, two commands, and an output file as arguments.
- Creates two child processes.
- Uses a pipe to connect them.
- Executes the commands so that:
  - The standard input of the first command is redirected from the input file.
  - The standard output of the second command is redirected to the output file.

This project requires a strong understanding of:
- `fork()`: to create child processes.
- `execve()`: to execute commands.
- `pipe()`: to create a unidirectional data channel between processes.
- `dup2()`: to redirect standard input and output.
- `waitpid()`: to wait for child processes to finish execution.

---

## Features
The **pipex** program implements the following features:
- **Command Execution** → Executes two commands in sequence, similar to how a shell would handle piping.
- **Input/Output Redirection** → Redirects input from a file and output to a file, allowing for flexible command execution.
- **Piping** → Connects the standard output of the first command to the standard input of the second.  
- **Process Management** → Creates and manages child processes for executing the commands.  
- **Error Handling** → Provides basic error handling for invalid arguments, file access issues, and command execution failures.  

---

## Installation

To compile and use the **pipex** program:

```bash
# Clone the repository
git clone https://github.com/achahid19/1337_projects.git

# Navigate into the pipex directory
cd 1337_projects/pipex

# Compile the executable
make
```
This will create an executable file named `pipex`.

## Usage

Syntax for running the program:

```bash
./pipex <infile> <cmd1> <cmd2> <outfile>
```
This equivalent to shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

Example:
To list files in the current directory and count the number of lines, redirecting the output to output.txt:

```bash
./pipex /dev/null "ls -l" "wc -l" output.txt
```
Equivalent to:

```bash
ls -l | wc -l > output.txt
```


## Author
**© Anas Chahid ksabi **@KsDev**** - [achahid19](https://github.com/achahid19)

## Acknowledgements
This project is part of the **1337/42 school curriculum**.

[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
