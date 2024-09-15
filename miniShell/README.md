# Mini-Shell (Bash-like implementation)
This project allows you to explore how a shell operates, providing an opportunity to implement a shell with behavior similar to the Bash program (without delving into its lowest-level implementation details, but replicating its behavior).

## Getting Started
These instructions will guide you through obtaining a copy of the project for development and testing on your local machine.

## About the project
Before proceeding with installation, here’s a global overview of how the project was implemented. The following scheme outlines all the steps taken (Click for redirection).
<br/>
<a href="https://whimsical.com/minishell-architecture-big-picture-7b9N8PL3qHrddbs977mQ2J" style="font-size: 40px" target="_blank">
  <img src="imgs/Screenshot 2024-09-15 at 16.07.59.png" style="width: 500px; height: 500px; display: block; margin: auto auto" />
</a>

The data structures and algorithms used in this implementation are not the most efficient, and there is certainly room for improvement. However, the main focus was on collaboration with my peer to find a solution that worked for both of us. Importantly, the behavior remains consistent with that of a typical Bash implementation. (Note: this implementation is not exhaustive, and there are still many features to handle).

## Installing
First, clone the repository using the following command:
``` bash
git clone https://github.com/achahid19/1337_projects.git
```
Move into the minishell directory:
``` bash
cd miniShell
```
Compile the project using the provided Makefile:
``` bash
make
```
After compilation, you can run the program with:
``` bash
./minishell
```

Now that the program is ready, enjoy exploring the mini-shell! 

### P.S: This program has been tested on both Linux and macOS. It is expected to run smoothly on both platforms.
