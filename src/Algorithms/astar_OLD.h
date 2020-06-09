// #pragma once

// #include <queue>
// #include <map>
// #include <algorithm>
// #include <memory>
// #include "TileMap/tile.h"

// struct Node {
//     Node() = default;

//     bool operator >(const Node& n) const {
//         return this->h_cost > n.h_cost;
//     }

//     bool operator <(const Node& n) const {
//         return this->h_cost < n.h_cost;
//     }

//     bool operator ==(const Node& n) const{
//         return (this->pos.x == n.pos.x) && (this->pos.y == n.pos.y);
//     }

//     bool operator !=(const Node& n) const {
//         return (this->pos.x != n.pos.x) && (this->pos.y != n.pos.y);
//     }

//     sf::Vector2u pos;
//     double g_cost = 0;
//     double h_cost = 0;
//     double f_cost = g_cost + h_cost;
//     bool isWall = false;
//     std::shared_ptr<Node> parent = nullptr;
// };

// template<
//     class T,
//     class Container = std::vector<T>,
//     class Compare = std::less<typename Container::value_type>
// > class MyQueue : public std::priority_queue<T, Container, Compare>
// {
// public:
//     typedef typename
//         std::priority_queue<
//         T,
//         Container,
//         Compare>::container_type::const_iterator const_iterator;

//     bool contains(const T& val) const
//     {
//         auto first = this->c.cbegin();
//         auto last = this->c.cend();
//         while(first != last) {
//             if (**first == *val) return true;
//             ++first;
//         }
//         return false;
//     }
// };

// class Astar {
// public:
// 	static std::vector<std::vector<std::shared_ptr<Node>>> TileToNodeGrid(const std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>>& grid, size_t layer);

// 	static double calculateHValue(Node current, Node dest);

// 	static std::vector<std::shared_ptr<Node>> GetNeighbors(std::shared_ptr<Node> n, sf::Vector2u grid_size);

// 	static std::vector<std::shared_ptr<Node>> TracePath(std::shared_ptr<Node> start, std::shared_ptr<Node> target);

// 	static std::vector<std::shared_ptr<Node>> AStarSearch(std::shared_ptr<Node> start, std::shared_ptr<Node> end, std::vector<std::vector<std::shared_ptr<Node>>> grid);
// };



