// #pragma once

// #include <queue>
// #include <map>
// #include <algorithm>
// #include <memory>
// #include "TileMap/tile.h"

// struct Node {
//     Node() = default;

//     bool operator >(const Node& n) const {
//         return this->f_cost > n.f_cost;
//     }

//     bool operator <(const Node& n) const {
//         return this->f_cost < n.f_cost;
//     }

//     bool operator ==(const Node& n) const{
//         return (this->pos.x == n.pos.x) && (this->pos.y == n.pos.y);
//     }

//     bool operator !=(const Node& n) const {
//         return (this->pos.x != n.pos.x) && (this->pos.y != n.pos.y);
//     }

//     sf::Vector2u pos;
//     int g_cost = 0;
//     int h_cost = 0;
//     int f_cost = g_cost + h_cost;
//     bool isWall = false;
//     Node* parent = nullptr;
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
//         while (first!=last) {
//             if (*first==val) return true;
//             ++first;
//         }
//         return false;
//     }
// };

// std::vector<std::vector<Node>> TileToNodeGrid(std::vector<std::vector<std::vector<std::shared_ptr<Tile>>>> grid, size_t layer);

// double calculateHValue(Node current, Node dest);

// std::vector<Node> GetNeighbors(Node& n, sf::Vector2u grid_size);

// std::vector<Node> TracePath(Node start, Node target);

// std::vector<Node> AStar(Node start, Node end, std::vector<std::vector<Node>> grid);


