#include "SetGraph.hpp"

struct cmp {
    bool operator() (const edge_t &a, const edge_t &b) {
        return a.angle >= b.angle;
    }
};

// Определение углов разным квадрантам
// Тк сейчас все значения с положительным знаком
int main(int argc, const char * argv[]) {
    
    std::set<edge_t, cmp> edges;
    
    
    edges.insert({{5, 5}, {5, 8}});
    edges.insert({{5, 5}, {6, 1}});
    edges.insert({{5, 5}, {8, 2}});
    edges.insert({{5, 5}, {1, 2}});
    edges.insert({{5, 5}, {2, 5}});
    edges.insert({{5, 5}, {9, 5}});
    edges.insert({{5, 5}, {5, 1}});
    
    
    for (auto i = edges.begin(); i != edges.end(); i++) {
        auto item = *i;
        std::cout << item.point2.x << " " << item.point2.y << " -> " << item.angle << std::endl;
    }
    
    vector_t v1{0, 0, 1, 0};
    vector_t v2{2, 2, 3, 4};
    
//    angleQuadrant({5, 5}, {9, 5});
//    angleQuadrant({5, 5}, {9, 4});
//    angleQuadrant({5, 5}, {8, 2});
//    angleQuadrant({5, 5}, {6, 1});
//    angleQuadrant({5, 5}, {5, 1});
//    angleQuadrant({5, 5}, {2, 2});
//    angleQuadrant({5, 5}, {2, 5});
//    angleQuadrant({5, 5}, {2, 8});
//    angleQuadrant({5, 5}, {5, 8});
//    angleQuadrant({5, 5}, {8, 8});
    
//    std::cout << angleBetweenVectors(v1, v2) * 180 / 3.14 << std::endl;
//    std::cout << angle(1, 0, -1, 1) * 180 / 3.14 << std::endl;
    return 0;
}
