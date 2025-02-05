# Langtron-s-ant
 
This program is an implementation of Langtron's ant, two-dimensional universal Turing machine with a very simple set of rules but complex emergent behavior devised by Christopher Langton. The simulation includes a customizable board, ant movement, and optional obstacles.

## Prerequisites
- GCC Compiler

## Compilation
To compile the program, navigate to the directory containing the source code files and run the following command:

```bash
cc main.c ant_simulation.c board.c display.c input.c saving_to_file.c -o ant_simulation -std=c11
```

## Usage
The program can be run with the following command:
```bash
./ant_simulation <rows> <columns> <iterations> <name_prefix> <initial_direction> -o <obstacle_percentage> -f <map_filename>
```
```
Where:
<rows>: The number of rows in the board.
<columns>: The number of columns in the board.
<iterations>: The number of iterations for the ant to move.
<name>: Prefix for files containing generated boards.
<initial_direction>: The initial direction of the ant. It can be 'N' for North, 'S' for South, 'E' for East, and 'W' for West.
<obstacle_percentage>: The percentage of the board to be filled with obstacles. If this argument is not provided, no obstacles will be generated.
<map_filename>: The name of the file from which to load the board. If this argument is not provided, a board will be generated randomly.
```

## Example
```bash
./ant_simulation 10 10 15 file N -o 20
```
This will run a simulation with a 10x10 board for 15 iterations. Generated files will start with "file", the ant starts facing North, 20% of the board is filled with obstacles.

## Result

### Iteration 1
```
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ▲ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
```

### Iterating in the middle of the program running 
```
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ░ ░ ░ ░ ░
░ ░ ░ ░ ░ ◀ ░ █ ░ ░
░ ░ ░ ░ ░ ░ █ ░ █ ░
░ ░ ░ ░ █ ░ ░ ░ █ ░
░ ░ ░ █ ░ ░ ░ █ ░ ░
░ ░ █ ░ ░ █ ░ ░ ░ ░
░ ░ █ ░ ░ █ ░ ░ ░ ░
░ ░ ░ █ ░ ░ █ ░ ░ ░
░ ░ ░ ░ █ █ ░ ░ ░ ░
```

### Iteration 215
```
░ █ █ █ ░ ░ ░ ░ █ ░
░ █ █ █ █ █ █ █ █ ░
░ ░ █ █ ░ █ ░ ░ █ ░
░ ░ █ ░ ░ ░ █ ░ █ █
░ █ ░ ░ █ █ ░ █ █ █
█ ▶ █ ░ ░ ░ ░ ░ █ ░
█ █ ░ ░ █ █ █ █ ░ ░
```
