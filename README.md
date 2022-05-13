# Astar Pathfinding Algorithm
    A* is a searching algorithm that is used to find the shortest path between an initial and
    a final point. It is a handy algorithm that is often used for map traversal to find the
    shortest path to be taken.

## Components
### 1. Node
    Node represents a single block that is used in mage generation and pathfinding. It is also
    used to display the maze and pathfinding process in terminal.

### 2. Grid
    Plane containing Nodes as the smallest unit in numbers of rows and columns.

### 3. Maze Generator
    Before A* algorithm is used to find the shortest path between two points in the Grid,
    maze generator is used to make the Grid into a maze where some nodes are open(walkable)
    while some are closed(not walkable)

####     **How does it work?**
    Maze generator initializes start current and next variable to store a single Node.
    It also initializes a stack(vector) to store visited nodes. At first start Node(0, 0)
    is pushed into visited stack. Then while visited stack is not empty current node is
    set as the last node in visited stack and it is marked as visited. Then a random
    eligible(which is not already visited) neighbor is selected. If no eligible neighbor is
    found the current Node is popped off the visited stack. If eligible is available, next is
    set to a random neighbor if more than one then next is pushed onto the visited stack and
    while loop is continued.

####     **Note**:
    This method creates maze such that only single path is available between any two nodes.

![Mage generation gif](https://i.imgur.com/m6QdvSm.gif)

### 4. Path finder
    After the maze generator modifies the Grid to make a maze of nodes of which some are
    walkable and some aren't, it the job of path finder to find the shortest path from
    start node to end node.

    The algorithm used here is A*(A star). Each iteration A* selected the node with the lowest
    f cost.
            f(n) = g(n) + h(n)
    where f(n) is the total cost of node which is the sum of cost of movement from start node
    to current node( g(n) ) and estimated cost of movement from current node to end node( h(n) ).

#### **Pseudocode**
```
open_list = list containing start
close_list = empty list
while open_list is not empty
    current = item with lowest f cost from open_list
    if current is equal to end:
        reconstruct reverse path from end to start by following parent 
    put current to close_list
    for neighbors of current:
        if neighbor is in close_list:
            ignore this neighbor
        else if neighbor is in open_list:
            if f cost from current is less then neighbors current f cost:
                set the neighbors parent to current
                set its cost using current node as parent
        else if the neighbor is not in both list:
            set neighbors parent to current
            calculate its cost
            add neighbor to open_list
```

![](https://i.imgur.com/oYoXF8a.gif)