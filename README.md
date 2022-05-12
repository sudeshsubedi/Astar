# Astar Pathfinding Algorithm
    A* is a searching algorithm that is used to find the shortest path between an initial and a final point. It is a handy algorithm that is often used for map traversal to find the shortest path to be taken.

## Components
### Node
    Node represents a single block that is used in mage generation and pathfinding. It is also used to display the maze and pathfinding process in terminal.

### Grid
    Plane containing Nodes as the smallest unit in numbers of rows and columns.

### Maze Generator
    Before A* algorithm is used to find the shortest path between two points in the Grid, maze generator is used to make the Grid into a maze where some nodes are open(walkable) while some are closed(not walkable)

#### **How does it work?**
Maze generator initializes start current and next variable to store
a single Node. It also initializes a stack(vector) to store visited nodes.
At first start Node(0, 0) is pushed into visited stack. Then while visited
stack is not empty current node is set as the last node in visited stack and
it is marked as visited. Then a random eligible(which is not already visited)
neighbor is selected. If no eligible neighbor is found the current Node is
popped off the visited stack. If eligible is available, next is set to a random
neighbor if more than one then next is pushed onto the visited stack and while
loop is continued.

#### **Note**:
    This method creates maze such that only single path is available between any two nodes.