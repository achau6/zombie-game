// #include "astar.h"

// //Converts the object layer to a node based grid
// std::vector<std::vector<Node>> TileToNodeGrid(std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> grid, size_t layer) {
//     std::vector<std::vector<Node>> node_grid;
//     node_grid.reserve(grid.size());
//     for(size_t i = 0; i < grid.size(); i++) {
//         node_grid.reserve(grid[i].size());
//         node_grid.push_back(std::vector<Node>());
//         for(size_t j = 0; j < grid[i].size(); j++) {
//             if(grid[i][j][layer] != nullptr) {
//                 if(grid[i][j][layer]->isWall()) {
//                     node_grid[i][j].isWall = true;
//                 }
//             }
//             else {
//                 node_grid[i][j].isWall = false;
//             }
//         }
//     }
//     return node_grid;
// }

// // A Utility Function to calculate the 'h' heuristics.
// double calculateHValue(Node current, Node dest)
// {
//     // Return using the distance formula
//     return ((double)sqrt((current.pos.x-dest.pos.x)*(current.pos.x-dest.pos.x)+(current.pos.y-dest.pos.y)*(current.pos.y-dest.pos.y)));
// }

// std::vector<Node> GetNeighbors(Node& n, sf::Vector2u grid_size) {
//     std::vector<Node> neighbors;
//     for(int i = -1; i <= 1; i++) {
//         for(int j = -1; j <= 1; j++) {
//             /* if at center
//             [-1][-1] [-1][0] [-1][1]
//             [0][-1] [0][0] [0][1]
//             [1][-1] [1][0] [1][1]
//             */
//             if(i == 0 && j == 0)
//                 continue;

//             int checkX = n.pos.x + i;
//             int checkY = n.pos.y + j;

//             Node temp_node;
//             temp_node.pos.x = checkX;
//             temp_node.pos.y = checkY;

//             if(checkX >= 0 && checkX < grid_size.x && checkY >= 0 && checkY < grid_size.y)
//                 neighbors.push_back(temp_node);
//         }
//     }
// 	return neighbors;
// }

// std::vector<Node> TracePath(Node start, Node end) {
//     std::vector<Node> path;
//     Node current = end;
//     while(current != start) {
//         path.push_back(current);
//         current = *(current.parent);
//     }
//     std::reverse(path.begin(), path.end());
//     return path;
// }

// // FIXME: bug where parent has the exact same pos as current
// // Node holds the current in current loop rather than the current node from previous loop
// std::vector<Node> AStar(Node start, Node end, std::vector<std::vector<Node>> grid) {
//     MyQueue<Node> open_set;
//     std::vector<Node> closed_set;

//     open_set.push(start);

//     while(!open_set.empty()) {
//         // redefining current does not change the pointer so the data the pointer points to is changed
//         Node current = open_set.top();
//         // IT HAPPENS HERE
//         open_set.pop();
//         closed_set.push_back(current);
//         if(current == end) {
//             return TracePath(start, current);
//         }

//         // first is x grid size and grid[0] is y grid size
//         unsigned int grid_size_x = grid.size();
//         unsigned int grid_size_y = grid[0].size();
//         std::vector<Node> neighbors_list = GetNeighbors(current, sf::Vector2u(grid_size_x, grid_size_y));
//         for(auto& neighbor : neighbors_list) {
//             // if neighbor is not traversable or neighbor is in the closed set
//             if(neighbor.isWall || (std::find(closed_set.begin(), closed_set.end(), neighbor)!= closed_set.end())) {
//                 // skip to the next neighboring node
//                 continue;
//             }

//             int new_g_cost = current.g_cost + calculateHValue(current, neighbor);
//             // if new path to neighbor is short or neighbor is not in the open set
//             if(new_g_cost < neighbor.g_cost || !open_set.contains(neighbor)) {
//                 // set f_cost of neighbor by g + h
//                 // set parent of neighbor to current node
//                 neighbor.g_cost = new_g_cost;
//                 neighbor.h_cost = calculateHValue(neighbor, end);
//                 neighbor.f_cost = neighbor.g_cost + neighbor.h_cost;

//                 // FIXME: SOMETHING WRONG HERE
//                 neighbor.parent = &current;

//                 // if neighbor is not in the open list
//                     // push back neighbor
//                 if(!open_set.contains(neighbor)) {
//                     open_set.push(neighbor);
//                 }
//             }
//         }
//     }

// 	// returning empty list
// 	return std::vector<Node>();
// }