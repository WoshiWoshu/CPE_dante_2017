# CPE_dante_2017
First year mini project in C which the goal is to generate and solve a maze. A folder with a binary named 'generator' will output a maze into a file.txt. Another folder with a binary named 'solver' will solve the maze while printing its output to the standard ouput. For a single maze, the ‘X’s represent the walls and the ’*’s represent the free spaces. “Start” is in the upper left-handcorner(0;0). “Finish” is in the bottom right-hand corner. The solution path is represented by a 'o' line.
The generator is based on Kruskal's algorithm and the solver on backtracking algorithm.

USING :

1) Make

2) ./generator/generator x y [perfect] > file.txt

or (To print maze generator on standard ouput instead on file ouput)

2) ./generator/generator x y [perfect] 

3) ./solver/solver file.txt

NOTE :

- A perfect maze is a maze that has no loops and no clusters; therefore, following a wall makes us cross the entire maze.

- An imperfect maze must contain clusters.

