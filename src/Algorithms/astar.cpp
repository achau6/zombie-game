#include "astar.h"

// Converts the object layer to a node based grid
// TODO: FIX MAGIC NUMS
std::vector<std::vector<std::shared_ptr<Node>>> Astar::TileToNodeGrid(const std::vector<std::vector<int>>& grid) {
   std::vector<std::vector<std::shared_ptr<Node>>> node_grid;
   const int WALL = 1;
   node_grid.reserve(grid.size());
   for(size_t i = 0; i < grid.size(); i++) {
       node_grid.reserve(grid.size());
       node_grid.push_back(std::vector<std::shared_ptr<Node>>());
       for(size_t j = 0; j < grid.size(); j++) {
            if(grid[i][j] == WALL ) {
                 // here
                 node_grid[i].push_back(std::make_shared<Node>());
                 node_grid[i][j]->isWall = true;
            }
            else {
                node_grid[i].push_back(std::make_shared<Node>());
                node_grid[i][j]->isWall = false;
            }
       }
   }
   return node_grid;
}

// A Utility Function to calculate the 'h' heuristics.
double Astar::calculateHValue(Node current, Node dest)
{
    // Return using the distance formula
    return ((double)sqrt((current.pos.x-dest.pos.x)*(current.pos.x-dest.pos.x)+(current.pos.y-dest.pos.y)*(current.pos.y-dest.pos.y)));
}

std::vector<std::shared_ptr<Node>> Astar::GetNeighbors(std::shared_ptr<Node> n, const std::vector<std::vector<std::shared_ptr<Node>>>& grid) {
    std::vector<std::shared_ptr<Node>> neighbors;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            /* if at center
            [-1][-1] [-1][0] [-1][1]
            [0][-1] [0][0] [0][1]
            [1][-1] [1][0] [1][1]
            */
            if(i == 0 && j == 0)
                continue;

            int checkX = n->pos.x + i;
            int checkY = n->pos.y + j;

            std::shared_ptr<Node> temp_node = std::make_shared<Node>();
            temp_node->pos.x = checkX;
            temp_node->pos.y = checkY;

            if(checkX >= 0 && checkX < grid.size() && checkY >= 0 && checkY < grid.size()) {
                if(grid[checkY][checkX] != nullptr) {
                    if(grid[checkY][checkX]->isWall) {
                        temp_node->isWall = true;
                    }
                }
                neighbors.push_back(temp_node);
                // std::cout << "NEIGHBORS " << temp_node->pos.x << " " << temp_node->pos.y << std::endl;
            }
        }
    }
	return neighbors;
}

std::vector<std::shared_ptr<Node>> Astar::TracePath(std::shared_ptr<Node> start, std::shared_ptr<Node> end) {
    std::vector<std::shared_ptr<Node>> path;
    path.push_back(end);
    Node* current = end.get();
    while(current != nullptr) {
        path.push_back(current->parent);
        current = current->parent.get();
        if(current != nullptr) {
            if(*current != *start.get()) {
                // std::cout << current.use_count() << " big weiner\n";
                // std::cout << current->pos.x << " " << current->pos.y << std::endl;
            }
        }
    }
    // removing last node that's null
    path.pop_back();
    std::reverse(path.begin(), path.end());
    return path;
}

// FIXME: bug where parent has the exact same pos as current
// Node holds the current in current loop rather than the current node from previous loop
std::vector<std::shared_ptr<Node>> Astar::AStarSearch(std::shared_ptr<Node> start, std::shared_ptr<Node> end, std::vector<std::vector<std::shared_ptr<Node>>> grid) {
    MyQueue<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>, MyCompare> open_set;
    std::vector<std::shared_ptr<Node>> closed_set;

    open_set.push(start);

    while(!open_set.empty()) {
//        std::cout << open_set.size() << std::endl;
        // redefining current does not change the pointer so the data the pointer points to is changed
        std::shared_ptr<Node> current = open_set.top();
        // std::cout << "current node:" << current->pos.x << " " << current->pos.y << std::endl;
        open_set.pop();
//        std::cout << "POPPED\n";
        closed_set.push_back(current);

//        std::cout << "CURRENT: " << current->pos.x << " " << current->pos.y << std::endl;
//        std::cout << "END: " << end->pos.x << " " << end->pos.y << std::endl;

        if(*current == *end) {
//            std::cout << "PATH FOUND\n";
            std::vector<std::shared_ptr<Node>> path = TracePath(start, current);
            return path;
        }

        std::vector<std::shared_ptr<Node>> neighbors_list = GetNeighbors(current, grid);

        for(auto& neighbor : neighbors_list) {
            // if neighbor is not traversable or neighbor is in the closed set
            // std::cout << "WALL:" << neighbor->isWall << std::endl;

            if(neighbor->isWall || (std::find(closed_set.begin(), closed_set.end(), neighbor) != closed_set.end())) {
                // closed_set.push_back(neighbor);
                // std::cout << "WALL:" << current->pos.x << " " << current->pos.y << std::endl;
                // skip to the next neighboring node
                continue;
            }

            // std::cout << "h cost: " << calculateHValue(*current, *neighbor) << std::endl;

            double new_g_cost = current->g_cost + calculateHValue(*current, *neighbor);
            // if new path to neighbor is short or neighbor is not in the open set
            if(new_g_cost < neighbor->g_cost || !open_set.contains(neighbor)) {
                // std::cout << "New g cost: " << new_g_cost << std::endl;
                // set f_cost of neighbor by g + h
                // set parent of neighbor to current node
                neighbor->g_cost = new_g_cost;
                neighbor->h_cost = calculateHValue(*neighbor, *end);
                neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;

                neighbor->parent = current;

                // if neighbor is not in the open list
                    // push back neighbor

                // pushes too many neighbors??
                if(!open_set.contains(neighbor)) {
//                    std::cout << "FCOST: " << neighbor->f_cost << std::endl;
                    open_set.push(neighbor);
//                    std::cout << current->pos.x << " " << current->pos.y << std::endl;
                }
            }
        }
    }

	// returning empty list
	return std::vector<std::shared_ptr<Node>>();
}
