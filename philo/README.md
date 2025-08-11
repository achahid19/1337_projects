# philosophers

A project from the **1337/42 school curriculum**.  
The goal is to simulate the classic **"Dining Philosophers"** problem using threads and mutexes to understand **concurrency**, **resource management**, and **deadlock prevention**.


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
The **Dining Philosophers** problem is a classic synchronization problem in computer science.  
It involves a number of philosophers sitting around a table, with a single fork placed between each pair of philosophers.  
To eat, a philosopher must pick up **both** the left and right forks.  

**Challenges:**
- Avoiding **deadlock** (where no philosopher can eat).  
- Avoiding **starvation** (where one philosopher never gets to eat).  

This program:
- Uses a **multi-threaded approach** to represent each philosopher.  
- Employs **mutexes** to protect access to shared forks, ensuring only one philosopher can hold a fork at a time.  


---

## Features
- **Multi-threading** → Each philosopher is represented by a separate thread.  
- **Mutexes** → Uses `pthread_mutex_t` to control access to forks and prevent race conditions.  
- **Deadlock Prevention** → Implements strategies like:
  - Asymmetric fork-picking order.
  - Timeout-based approaches.  
- **Simulation Logging** → Logs state changes: eating, sleeping, thinking, taking a fork, dying.  
- **Dynamic Arguments** → Easily configure simulations via command-line arguments. 

---

## Installation

To compile and use the **philo** program:

```bash
# Clone the repository
git clone https://github.com/achahid19/1337_projects.git

# Navigate into the philo directory
cd 1337_projects/philo

# Compile the executable
make
```
This will create an executable file named `philo`.

## Usage

Syntax for running the program:

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```
Arguments:
- `number_of_philosophers`: Total number of philosophers (and forks).
- `time_to_die`: Time in milliseconds before a philosopher dies if they haven't eaten.
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds a philosopher sleeps after eating.
- `number_of_times_each_philosopher_must_eat` (optional): If provided, each philosopher will attempt to eat this many times before the simulation ends.

Example command to run the simulation with 5 philosophers:

```bash
./philo 5 800 200 200
```
This runs the simulation with 5 philosophers, where each philosopher has:
- 800 milliseconds to die if they don't eat,
- 200 milliseconds to eat,
- 200 milliseconds to sleep.

## Author
**© Anas Chahid ksabi **@KsDev**** - [achahid19](https://github.com/achahid19)

## Acknowledgements
This project is part of the **1337/42 school curriculum**.

[![School](https://img.shields.io/badge/Notice-1337%20School-blue.svg)](https://1337.ma/en/)
[![School](https://img.shields.io/badge/Notice-42%20School-blue.svg)](https://42.fr/en/homepage/)
