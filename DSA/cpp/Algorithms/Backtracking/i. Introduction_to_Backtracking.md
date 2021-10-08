# Backtracking with C++

## Topics Covered
- [Introduction](#introduction)
- [Backtracking - The Exact Working ?](#backtracking---the-exact-working-)
- [Maze Traversal Algorithm Using Backtracking](#maze-traversal-algorithm-using-backtracking)
- [Graph Coloring Algorithm Using Backtracking](#graph-coloring-algorithm-using-backtracking)
    - [Problem](#what-is-a-graph-coloring-problem)
    - [Analysis](#analysis)
            - [Input](#input)
            - [Output](#output)
    - [Solution](#solution)

# Introduction
> Backtracking is an algorithmic technique that considers searching in every possible combination for solving a computational problem.

-   It is known for solving problems recursively one step at a time and removing those solutions that do not satisfy the problem constraints at any point in time.
-   It is a refined brute force approach that tries out all the possible solutions and chooses the best possible ones out of them.
-   The backtracking approach is generally used in cases where there are possibilities of multiple solutions.

The term backtracking implies - if the current solution is not suitable, then eliminate that and backtrack (go back) and check for other solutions.
<br>

## Backtracking - The Exact Working ?

In any backtracking problems, the algorithm tries to find a path to the feasible solution which has some intermediary checkpoints. In case they don't lead to a 
feasible solution, the problem can backtrack from the checkpoints and take another path in search of the solution. Consider the below example:
![Backtracking](https://user-images.githubusercontent.com/72455881/135705712-17aca29d-2019-4672-9ce5-ab98a0d93c87.png)
<br>

-   Here S is the starting point of the problem. We start from S, we go to find solution S1 via the intermediate point I1. But we find that the solution S1 is not a 
    feasible solution to our problem. Hence, we backtrack (go back) from S1, go back to I1, go back to S, and then check for the feasible solution S2. 
    This process happens till we arrive at a feasible solution.
-   Here, S1 and S2 are not feasible solutions. Only S3 is a feasible solution as per our example. When we look at this example, we can see that we traverse through 
    all possible combinations, till we arrive at the feasible solution. This is why we say that backtracking is a brute-force algorithmic technique.
-   The above tree representation of a problem is called as a `space state tree`. It represents all possible states (solution or non-solution) of that given problem.
-   The final algorithm can be summarised as:
   > Step 1 - if the current point is a feasible solution, return success <br>
   > Step 2 - else if all paths are exhausted (i.e current point is an endpoint), return failure since we have no feasible solution. <br>
   > Step 3 - else if the current point is not an endpoint, backtrack and explore other points and repeat the above steps. <br>
<br>

## Maze Traversal Algorithm Using Backtracking
Backtracking is trying out all possibilities using recursion, exactly like brute force.
Suppose you have to make a series of decisions, among various choices, where :

  * You don't have enough information to know what to choose
  * Each decision leads to a new set of choices
  * Some sequence of choices (possibly more than one) may be a solution to your problem

- Backtracking is a methodical way of trying out various sequences of decisions until you find one that "works".
  Let's look at an example to explain this further.

Given a maze, find if a path from start to finish
At each intersection, you have to decide between three or fewer choices:

> * Go straight
> * Go left
> * Go right

You don't have enough information to choose correctly. Each choice leads to another set of choices. One or more sequences of choices may (or may not) lead to a solution.
So, you explore each option thoroughly and once you cannot find a solution using the option selected, you come back and try one of the remaining options.

  Backtracking Pseudocode

  Pseudocode for the above question would be :
  ```cpp
  boolean pathFound(Position p) {
              if (p is finish) return true;

              foreach option O from p {
                  boolean isThereAPath = pathFound(O);
                  if (isThereAPath) return true; 
              }
              // We have tried all options from this position and none of the options lead to finish.
              // Hence there is no solution possible to finish
               return false;
          }
  ```
  
  In general, the usual pseudocode for any backtracking solution is :
  ```cpp
  boolean solve(Node n) {
              if n is a goal node, return true

              foreach option O possible from n {
                  if solve(O) succeeds, return true
              }
              return false
          }
  ```
 <br>
 
## Graph Coloring Algorithm Using Backtracking
  ### What is a graph coloring problem?
  Graph coloring problem involves assigning colors to certain elements of a graph subject to certain restrictions and constraints. This has found applications in numerous fields in computer science. For example:

  -   `Sudoku:` This game is a variation of the Graph coloring problem where every cell denotes a node (or vertex) and there exists an edge between two nodes if the nodes are in the same row or same column or same block.
  -   `Geographical maps:` There can be cases when no two adjacent cities/states can be assigned the same color in the maps of countries or states. In this case, only four colors would be sufficient to color any map.

  `Vertex coloring` is the most commonly encountered graph coloring problem. The problem states that given `m` colors, determine a way of coloring the vertices of a graph such that no two adjacent vertices are assigned the same color.

  Note: The smallest number of colors needed to color a graph G is called its `chromatic number.`
  For example, the following undirected graph can be colored using minimum of 2 colors.
  Hence the chromatic number of the graph is 2.

   ![Graph Coloring](https://user-images.githubusercontent.com/72455881/135705837-f755a1a7-e2cc-48af-811d-434c69b61f20.png)
  ### Analysis

  ### Input:
  -   A graph represented in a 2D array format of size `V * V` where V is the number of vertices in the graph and the 2D array is the adjacency matrix representation and value `graph[i][j]` is 1 if there is a direct edge from i to j, otherwise, the value is 0.
  -   An integer `m` that denotes the maximum number of colors which can be used in graph coloring.
  -   Consider the input as shown in the image below:

![Graph-1](https://user-images.githubusercontent.com/72455881/135705924-4c4e8829-b7d6-4b49-bb48-46fceb9457b6.png)

  -   The above graph can be represented as follows:

  ![Representation](https://user-images.githubusercontent.com/72455881/135705933-651155a4-a00e-4c47-bba3-f1e8ab94243c.png)

  -   Consider `m = 3`

  ### Output:
  -   Return array color of the size `V` that has numbers from 1 to m. Note that `color[i]` represents the color assigned to the ith vertex.
  -   Return `false` if the graph cannot be colored with `m` colors.

### Solution:

#### Naive Approach:

-   The brute force approach would be to generate all possible combinations (or configurations) of colors.
-   After generating a configuration, check if the adjacent vertices have the same color or not. If the conditions are met, add the combination to the result and break the loop.
-   Since each node can be colored by using any of the `m` colors, the total number of possible color configurations are mV. The complexity is exponential which is very huge.

### Pseudo Code:

![Pseudo-1](https://user-images.githubusercontent.com/72455881/135705979-b9ccd043-6bf5-4cf0-b06f-527ab1899c0f.png)

![Pseudi-2](https://user-images.githubusercontent.com/72455881/135705982-ea3fa1e1-9f7f-4102-8507-4a81b6beb05f.png)

-   `Time Complexity: O(mV)`
-   `Space Complexity: O(V) which is for storing the output array`

Using Backtracking:

-   By using the backtracking method, the main idea is to assign colors one by one to different vertices right from the first vertex (vertex 0).
-   Before color assignment, check if the adjacent vertices have the same or different colors by considering already assigned colors to the adjacent vertices.
-   If the color assignment does not violate any constraints, then we mark that color as part of the result. If the color assignment is not possible then backtrack and return false.
-   Time Complexity: O(mV). Since backtracking is also a kind of brute force approach, there would be total O(mV) possible color combinations. It is to be noted that the upper bound time complexity remains the same but the average time taken will be less due to the refined approach.
-   Space Complexity: O(V) for storing the output array in O(V) space
