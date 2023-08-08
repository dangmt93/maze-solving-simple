# Maze solving using depth-first and breadth-first search

Given an input to construct a maze, the program will produce the solved maze using either depth-first or breadth-first search, based on your selection.

-   To modify this setting, go to line 19 in the "assig_three220.h" file and set the "DEPTH_FIRST" to either true or false accordingly.

## 1. Input

To construct the maze, the following format is used:

```dotnetcli
# Maze data
#
# Horizonal Dimension
x
# Vertical Dimension
y
# Goal Square
99
# Square values (in rows)
# -1 represents walls, 0 is start location
# positive numbers represent open space
-1
-1
-1
...
```

- where "x" is the horizontal dimension, and "y" is the vertical dimension of the maze
- Now write the maze data line by line using the following key:
  - -1 represents walls (obstacles)
  - 0 represents the **start** location
  - 99 (or your specified value) represents the **goal** location
  - Any other positive integer values represent normal squares or pathways
    - Note that they don't have to be all different (i.e. you can just use "1" for open pathways, just make sure it is different from the specified value for goal square)


**Make sure to close the outer border with walls!!!**

For example, "maze.txt" file will produce the following maze:

![Maze example](./images/Output%20-%20Starting%20Maze%20example.PNG)


## 2. Output
Depending on your selected search, the program will produce the corresponding solved mazed, with the list of moves. 

**Sample outputs**:

Breath-first solution      |  Depth-first solution
:-------------------------:|:-------------------------:
![Breath-first solution](./images/Output%20-%20Breadth-first%20search.PNG)  |  ![Depth-first solution](./images/Output%20-%20Depth-first%20search.PNG)
